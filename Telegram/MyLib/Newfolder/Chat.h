#include <QSqlDatabase>
#include <QtSql>

#ifndef CHAT_H
#define CHAT_H

class User ;

class Pv
{

    friend class User ;

    QSqlDatabase DB ;

    QString name ;
    QString contact ;

//public :

    Pv ( QSqlDatabase db ) ;

    void create_table () ;

    void add_message ( const QString &text , const QString &sender ) ;

};

#endif // CHAT_H
