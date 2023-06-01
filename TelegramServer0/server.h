class User ;
#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

signals:
    void newMessage(QString);

private slots:
    void newConnection();
    void appendToSocketList(QTcpSocket* socket);

    void readSocket();
    void discardSocket();

    void sendMessage(QTcpSocket* socket , QByteArray name );

private:
    Ui::Server *ui;

    QTcpServer* my_server;

    User** users ;
    int num_users ;

    void addUser ( User* u ) ;
    void removeUser ( int i ) ;

    bool existUser ( User* u ) ;

};
#endif // SERVER_H

class User
{

    QTcpSocket* socket ;

    QString username ;

public :

    User ( QTcpSocket* _socket , QString _username ) ;

    ~User () ;

    QTcpSocket* getSocket () ;

    QString getUsername () ;

    void deleteSocket () ;
};
