#include "server.h"
#include "ui_server.h"

bool firstMessage = false ;

Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);

    my_server = new QTcpServer () ;
    num_users = 0 ;

    if ( my_server->listen( QHostAddress::Any , 8080 ) )
    {
        //connect( this , &Server::newMessage , this , &Server::displayMessage ) ;
        connect ( my_server , &QTcpServer::newConnection , this , &Server::newConnection ) ;
        ui->statusbar->showMessage("Server is listening...") ;
    }
    else
    {
        QMessageBox::critical( this , "QTcpServer" , QString ("Unable to start the server: %1.").arg(my_server->errorString())) ;
        exit (EXIT_FAILURE) ;
    }
}

Server::~Server()
{
    delete[] users ;

    my_server->close();
    my_server->deleteLater();

    delete ui;
}

void Server::newConnection ()
{
    while ( my_server->hasPendingConnections() )
        appendToSocketList( my_server->nextPendingConnection() ) ;
}

void Server::appendToSocketList ( QTcpSocket* socket )
{
    connect(socket, &QTcpSocket::readyRead, this, &Server::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &Server::discardSocket);
    firstMessage = true ;
//    connect(socket, &QAbstractSocket::errorOccurred, this, &Server::displayError);
//    ui->comboBox_receiver->addItem(QString::number(socket->socketDescriptor()));
//    displayMessage(QString("INFO :: Client with sockd:%1 has just entered the room").arg(socket->socketDescriptor()));
}

//void Server::discardSocket(){}
//void Server::readSocket(){}

void Server::discardSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());

    for ( int i = 0 ; i < num_users ; i ++ )
    {
        if ( users[i]->getSocket() == socket )
        {
            removeUser( i ) ;
            break ;
        }
    }
//    QSet<User>::iterator it = sockets.find(socket);
//    if (it != sockets.end()){
//        sockets.remove(*it);
//    }
    socket->deleteLater();
}

/////////////////////////////////////////////////////////////////

void Server::readSocket()
{

    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender()) ;


    QByteArray buffer;

    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_12);

    socketStream.startTransaction();
    socketStream >> buffer;


    if ( firstMessage )
    {

        User* u = new User ( socket , buffer ) ;

        addUser( u ) ;

        firstMessage = false ;

        return ;
    }

    for ( int i = 0 ; i < num_users ; i ++ )
        if ( users[i]->getUsername() == buffer )
            for ( int j = 0 ; j < num_users ; j ++ )
                if ( users [j]->getSocket() == socket )
                {
                    sendMessage( users [i]->getSocket() , users [j]->getUsername() ) ;
                    return ;
                }
}

//void Server::readSocket ()
//{
//    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender()) ;

//    QByteArray buffer ;

//    QDataStream socketStream ( socket ) ;
//    socketStream.setVersion(QDataStream::Qt_5_12) ;

//    socketStream.startTransaction() ;
//    socketStream >> buffer ;

//    if(!socketStream.commitTransaction())
//    {
//        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
//        emit newMessage(message);
//        return;
//    }

//    QString header = buffer.mid(0,128);
//    QString fileType = header.split(",")[0].split(":")[1];

//    buffer = buffer.mid(128);

//    if(fileType=="attachment"){
//        QString fileName = header.split(",")[1].split(":")[1];
//        QString ext = fileName.split(".")[1];
//        QString size = header.split(",")[2].split(":")[1].split(";")[0];

//        if (QMessageBox::Yes == QMessageBox::question(this, "QTCPServer", QString("You are receiving an attachment from sd:%1 of size: %2 bytes, called %3. Do you want to accept it?").arg(socket->socketDescriptor()).arg(size).arg(fileName)))
//        {
//            QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/"+fileName, QString("File (*.%1)").arg(ext));

//            QFile file(filePath);
//            if(file.open(QIODevice::WriteOnly)){
//                file.write(buffer);
//                QString message = QString("INFO :: Attachment from sd:%1 successfully stored on disk under the path %2").arg(socket->socketDescriptor()).arg(QString(filePath));
//                emit newMessage(message);
//            }else
//                QMessageBox::critical(this,"QTCPServer", "An error occurred while trying to write the attachment.");
//        }else{
//            QString message = QString("INFO :: Attachment from sd:%1 discarded").arg(socket->socketDescriptor());
//            emit newMessage(message);
//        }
//    }else if(fileType=="message"){
//        QString message = QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
//        emit newMessage(message);
//    }
//}
void Server::sendMessage(QTcpSocket* socket , QString name )
{
    if(socket)
    {
        if(socket->isOpen())
        {
            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_12);

            //socketStream.setVersion(QDataStream::Qt_5_12);
            socketStream << name;
        }
        else
            QMessageBox::critical(this,"QTCPServer","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPServer","Not connected");
}

void Server::addUser ( User* u )
{
    User** users2 = new User* [++num_users] ;
    for ( int i = 0 ; i < num_users - 1 ; i ++ )
        users2 [i] = users [i] ;
    users2 [num_users-1] = u ;
    if ( num_users != 1 )
        delete[] users ;
    users = users2 ;
}

void Server::removeUser ( int i )
{
    User** users2 = new User* [--num_users] ;
    for ( int j = 0 ; j < i ; j ++ )
        users2  [j] = users [j] ;
    for ( int j = i + 1 ; j < num_users + 1 ; j ++ )
        users2 [j-1] = users [j] ;
    delete[] users ;
    users = users2 ;
}

bool Server::existUser ( User* u )
{
    for ( int i = 0 ; i < num_users ; i ++ )
        if ( users [i] == u )
            return true ;
    return false ;
}


User::User ( QTcpSocket* _socket , QString _username )
{
    socket = _socket ;
    username = _username ;
}

QTcpSocket* User::getSocket()
{
    return socket ;
}

QString User::getUsername()
{
    return username ;
}

User::~User()
{
    deleteSocket() ;
}

void User::deleteSocket()
{
    socket->close() ;
    delete socket ;
}
