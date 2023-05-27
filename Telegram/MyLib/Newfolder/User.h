#include <QSqlDatabase>
#include <QtSql>
#include "Chat.h"

#ifndef USER_H
#define USER_H

class User
{

    QSqlDatabase DB ;

    QString username ;
    QString name ;

    Pv *pv ;

public :

    User () ;

};

#endif // USER_H
