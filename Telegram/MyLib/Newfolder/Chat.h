#include <QSqlDatabase>
#include <QtSql>
#include <QListWidget>
#include <QMessageBox>

#ifndef CHAT_H
#define CHAT_H

class User ;

class Pv
{

    friend class User ;

    QSqlDatabase* DB ;

    QString name ;
    QString contact ;

    Pv ( QSqlDatabase* db ) ;

    void create_table () ;

    void add_message ( const QString &text , const QString &sender ) ;

public :

    QString getContact () ;

    void ShowMessaegs ( QListWidget *lw ) ;

    void ShowLastMessage ( QListWidget *lw ) ;

};

#endif // CHAT_H
