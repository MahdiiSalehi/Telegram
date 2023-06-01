#include "chatpage.h"
#include "ui_chatpage.h"

extern MyQSqlDatabase db ;
extern QString NewUserName ;
extern QString Name ;

enum ChatList { pv , chat , none } ;
ChatList chatlist ;

ChatPage::ChatPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatPage)
{
    ui->setupUi(this);
    user = new User ( db.getDataBase() , NewUserName , Name ) ;

    for ( int i = 0 ; i < user->get_rows() ; i ++ )
    {
        item = new QListWidgetItem ( user->getPv(i)->getContact() ) ;
        ui->C_ContactList->addItem( item ) ;
    }

    socket = new QTcpSocket (this) ;

    connect(socket, &QTcpSocket::readyRead, this, &ChatPage::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &ChatPage::discardSocket);

    socket->connectToHost(QHostAddress::LocalHost,8080);
    if(!socket->waitForConnected())
    {
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        this->close () ;
    }

    if(socket)
    {
        if(socket->isOpen())
        {

            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_12);

            socketStream << NewUserName ;
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");

}

ChatPage::~ChatPage()
{
    if ( socket->isOpen() )
        socket->close() ;
    delete socket ;
    delete user ;
    delete ui;
}

bool IsEmptyText ( QString text )
{
    for ( QChar i : text )
    {
        if ( i != ' ' && i != '\n' )
            return false ;
    }
    return true ;
}

void ChatPage::readSocket ()
{
    QByteArray buffer;

    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_12);

    socketStream.startTransaction();
    socketStream >> buffer;

    if ( buffer == user->getCurrentPv()->getContact() )
    {
        user->ShowLastMessageCurrentPv( ui->C_ChatList ) ;
    }
    else
    {// show Unseened messages
    }
}
/*
void MainWindow::readSocket()
{
    QByteArray buffer;

    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_12);

    socketStream.startTransaction();
    socketStream >> buffer;

    if(!socketStream.commitTransaction())
    {
        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
        emit newMessage(message);
        return;
    }

    QString header = buffer.mid(0,128);
    QString fileType = header.split(",")[0].split(":")[1];

    buffer = buffer.mid(128);

    if(fileType=="attachment"){
        QString fileName = header.split(",")[1].split(":")[1];
        QString ext = fileName.split(".")[1];
        QString size = header.split(",")[2].split(":")[1].split(";")[0];

        if (QMessageBox::Yes == QMessageBox::question(this, "QTCPServer", QString("You are receiving an attachment from sd:%1 of size: %2 bytes, called %3. Do you want to accept it?").arg(socket->socketDescriptor()).arg(size).arg(fileName)))
        {
            QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/"+fileName, QString("File (*.%1)").arg(ext));

            QFile file(filePath);
            if(file.open(QIODevice::WriteOnly)){
                file.write(buffer);
                QString message = QString("INFO :: Attachment from sd:%1 successfully stored on disk under the path %2").arg(socket->socketDescriptor()).arg(QString(filePath));
                emit newMessage(message);
            }else
                QMessageBox::critical(this,"QTCPServer", "An error occurred while trying to write the attachment.");
        }else{
            QString message = QString("INFO :: Attachment from sd:%1 discarded").arg(socket->socketDescriptor());
            emit newMessage(message);
        }
    }else if(fileType=="message"){
        QString message = QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
        emit newMessage(message);
    }
}
*/
void ChatPage::discardSocket()
{
    socket->deleteLater();
    socket=nullptr;

    QMessageBox::critical( this , "Disconnected!","Your connection was destroyed") ;
    this->close() ;
}


void ChatPage::on_C_MessageButton_clicked()
{
    if ( IsEmptyText( ui->C_PlainText->toPlainText() ) )
    {
        return ;
    }
    if(socket)
    {
        if(socket->isOpen())
        {
            user->add_message(ui->C_PlainText->toPlainText()) ;
            ui->C_ChatList->addItem( "->" + NewUserName + '\n' + ui->C_PlainText->toPlainText() ) ;

            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_12);

            QByteArray byteArray (user->getCurrentPv()->getContact().toStdString().c_str()) ;

            socketStream << byteArray;
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");
}


void ChatPage::on_C_AddContactButton_clicked()
{
    ui->C_ChatList->clear() ;
    QSqlQuery q ( *db.getDataBase() ) ;
    q.exec("SELECT * FROM Users ;") ;
    while ( q.next() )
    {
        if ( q.value(1).toString() != NewUserName )
        {
            item = new QListWidgetItem ( q.value(1).toString() ) ;
            ui->C_ChatList->addItem(item) ;
        }
    }
    chatlist = pv ;
}


void ChatPage::on_C_ChatList_itemDoubleClicked(QListWidgetItem *item)
{
    if ( chatlist == pv )
    {
        ui->C_ContactList->addItem(item->text()) ;
        user->addPV( item->text() ) ;
        ui->C_ChatList->clear() ;
        chatlist = none ;
    }
    else
    {

    }
}


void ChatPage::on_C_ContactList_itemClicked(QListWidgetItem *item)
{
    user->setCurrentPv( item->text() ) ;
    ui->C_ChatList->clear() ;
    user->ShowMessages( ui->C_ChatList ) ;
}

