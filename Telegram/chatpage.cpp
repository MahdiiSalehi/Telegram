#include "chatpage.h"
#include "ui_chatpage.h"

extern MyQSqlDatabase db ;
extern QString NewUserName ;
extern QString Name ;

enum ChatList { pv , chat , none } ;
ChatList chatlist = none ;

ChatPage::ChatPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatPage)
{
    ui->setupUi(this);
    user = new User ( db.getDataBase() , NewUserName , Name ) ;

    user->ShowPvs( ui->C_ContactList ) ;

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

            socketStream << NewUserName.toUtf8() ;
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");

    ChatOff () ;

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
    //QMessageBox::critical( nullptr , "Client" , " From " + buffer ) ;

    if ( ui->frame->isEnabled() && buffer == user->getCurrentPv()->getContact() )
    {
//        if ( buffer.toStdString()[0] == 'i' )
//        {

//        }
//        else
//        {

//        }
        user->ShowLastMessageCurrentPv( ui->C_ChatList ) ;
        ui->C_ChatList->scrollToBottom() ;
        //QMessageBox::critical( nullptr , "Client" , "sender is : " + buffer ) ;
    }
    else
    {// show Unseened messages
        for ( int i = 0 ; i < user->get_rows() ; i ++ )
        {
            if ( user->getPv(i)->getContact() == buffer )
            {
                user->getPv(i)->CountUnSeenMessages() ;
                user->ShowPvs( ui->C_ContactList ) ;
                break ;
            }
        }
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


void ChatPage::on_C_SendMessageButton_clicked()
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
            ui->C_ChatList->addItem( "<" + NewUserName + ">\n" + ui->C_PlainText->toPlainText() ) ;
            ui->C_ChatList->scrollToBottom() ;
            ui->C_PlainText->clear() ;
            user->ShowPvs( ui->C_ContactList ) ;

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
    ChatOff () ;
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
        for ( int i = 0 ; i < user->get_rows() ; i ++ )
            if ( user->getPv(i)->getContact() == item->text() )
            {
                ui->C_ChatList->clear() ;
                chatlist = none ;
                return ;
            }
        ui->C_ContactList->addItem(item->text()) ;
        user->addPV( item->text() ) ;
        ui->C_ChatList->clear() ;
        chatlist = none ;
    }
    else if ( chatlist == chat )
    {
        if ( !item->icon().isNull() )
        {
            QMessageBox::information( this , "Icon" , "Icon isn't null" ) ;
        }
        else
        {
            QMessageBox::information( this , "Icon" , "Icon is null" ) ;
        }
    }
}


void ChatPage::on_C_ContactList_itemClicked(QListWidgetItem *item)
{   
    //QMessageBox::critical( nullptr , "ERROR" , "E2" ) ;
    user->setCurrentPv( item->text() ) ;
    //QMessageBox::critical( nullptr , "ERROR" , "E3" ) ;
    ui->C_ChatList->clear() ;
    //QMessageBox::critical( nullptr , "ERROR" , "E4" ) ;
    user->ShowMessages( ui->C_ChatList ) ;
    //QMessageBox::critical( nullptr , "ERROR" , "E5" ) ;
    user->getCurrentPv()->seen_messages() ;
    //QMessageBox::critical( nullptr , "ERROR" , "E6" ) ;
    user->ShowPvs( ui->C_ContactList ) ;
    //QMessageBox::critical( nullptr , "ERROR" , "E7" ) ;
    ChatOn () ;
    //QMessageBox::critical( nullptr , "ERROR" , "E1" ) ;
}

void ChatPage::ChatOn ()
{
    chatlist = chat ;
    ui->frame->setEnabled(1) ;
    ContactNameLabelOn () ;
}

void ChatPage::ChatOff ()
{
    chatlist = none ;
    ui->frame->setDisabled(1) ;
    ContactNameLabelOff () ;
}

void ChatPage::ContactNameLabelOn ()
{
    ui->C_ContactName->show () ;
    ui->C_ContactName->setText( user->getCurrentPv()->getContact() ) ;
}

void ChatPage::ContactNameLabelOff ()
{
    ui->C_ContactName->hide() ;
}


void ChatPage::on_C_SendFileButton_clicked()
{
    if(socket)
        {
            if(socket->isOpen())
            {
                QString filePath = QFileDialog::getOpenFileName(this, ("Select an attachment"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), ("File (*.json *.txt *.png *.jpg *.jpeg)"));

                if(filePath.isEmpty()){
                    QMessageBox::critical(this,"QTCPClient","You haven't selected any attachment!");
                    return;
                }

                QFile m_file(filePath);
                if(m_file.open(QIODevice::ReadOnly)){

                    user->add_file( filePath ) ;
                    item = new QListWidgetItem ( "<" + NewUserName + ">\n" ) ;
                    item->setIcon(QIcon(filePath)) ;
                    ui->C_ChatList->addItem( item ) ;
                    ui->C_ChatList->scrollToBottom() ;
                    ui->C_PlainText->clear() ;
                    user->ShowPvs( ui->C_ContactList ) ;


//                    QFileInfo fileInfo(m_file.fileName());
//                    QString fileName(fileInfo.fileName());

//                    QDataStream socketStream(socket);
//                    socketStream.setVersion(QDataStream::Qt_5_12);

//                    QByteArray header;
//                    header.prepend(QString("fileType:attachment,fileName:%1,fileSize:%2;").arg(fileName).arg(m_file.size()).toUtf8());
//                    header.resize(128);

//                    QByteArray byteArray = m_file.readAll();
//                    byteArray.prepend(header);

//                    socketStream.setVersion(QDataStream::Qt_5_12);
//                    socketStream << byteArray;
                    QDataStream socketStream(socket);
                    socketStream.setVersion(QDataStream::Qt_5_12);

                    QByteArray byteArray (user->getCurrentPv()->getContact().toStdString().c_str()) ;

                    socketStream << byteArray;
                }else
                    QMessageBox::critical(this,"QTCPClient","Attachment is not readable!");
            }
            else
                QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
        }
        else
            QMessageBox::critical(this,"QTCPClient","Not connected");
}

