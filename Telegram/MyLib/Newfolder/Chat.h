#include <QSqlDatabase>
#include <QtSql>

#ifndef CHAT_H
#define CHAT_H

class Pv
{

    QSqlDatabase DB ;

    QString name ;
    QString contact ;

public :

    Pv ( QSqlDatabase db ) ;

    void create_table () ;

};

#endif // CHAT_H
