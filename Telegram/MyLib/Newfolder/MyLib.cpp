#include <QSqlDatabase>
#include <QtSql>
#include "MyLib.h"
//#include <QDebug>
//#include <QCoreApplication>

MyQSqlDatabase::MyQSqlDatabase()
{
    DB = QSqlDatabase::addDatabase("QSQLITE") ;
    DB.setHostName("127.0.0.1") ;
    DB.setPort(3306) ;
    DB.setUserName("root") ;
    DB.setPassword("AAAAAAAA") ;
    DB.setDatabaseName("test0.db") ;
    DB.open() ;
    QSqlQuery q(DB) ;
    q.exec("CREATE TABLE Users"
           "("
           "phonenum VARCHAR (18) ,"
           "username VARCHAR (26) ,"
           "password VARCHAR (26) ,"
           "name VARCHAR (20) "
           ") ;") ;
}

bool MyQSqlDatabase::Search(const QString & str , column col )
{
    QSqlQuery q (DB) ;
    QString colString ;
    if ( col == phonenum )
        colString = " phonenum " ;
    else if ( col == username )
        colString = " username " ;
    else
        colString = " password " ;
    q.exec("SELECT"+colString+"FROM Users ;") ;
    while ( q.next() )
    {
        if ( q.value(0) == str )
            return true ;
    }
    return false ;
}

bool MyQSqlDatabase::Insert1(const QString &phonenum , const QString &username, const QString &password )
{
    QSqlQuery q (DB) ;
    q.prepare("INSERT INTO Users"
              "( phonenum , username , password )"
              "VALUES ( ? , ? , ? ) ;") ;
    q.addBindValue(phonenum) ;
    q.addBindValue(username) ;
    q.addBindValue(password) ;
    return q.exec() ;
}

bool MyQSqlDatabase::Insert_name(const QString &username , const QString &name )
{
    QSqlQuery q (DB) ;
    q.prepare("UPDATE Users "
              "SET name = ? "
              "WHERE username = ? ;") ;
    q.addBindValue(name) ;
    q.addBindValue(username) ;
    return q.exec() ;
}

QVariant MyQSqlDatabase::GetInfo(const QString &str_1, column col_1, column col_2)
{
    QSqlQuery q (DB) ;
    q.exec("SELECT * FROM Users ;") ;
    while ( q.next() )
    {
        if ( q.value(col_1) == str_1 )
        {
            return q.value(col_2) ;
        }
    }
}

QSqlDatabase* MyQSqlDatabase::getDataBase()
{
    return &DB ;
}

