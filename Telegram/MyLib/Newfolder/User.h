#include "Chat.h"

#ifndef USER_H
#define USER_H

class User
{

    QSqlDatabase* DB ;

    QString username ;
    QString name ;

    Pv **pv ;

    int rows ;
    int currentPv ;

public :

    User ( QSqlDatabase* db , QString _username , QString _name ) ;

    ~User() ;

    void addPV( QString contact ) ;

    void add_message(const QString &text) ;

    Pv* getCurrentPv () ;

    int get_rows () ;

    Pv* getPv ( int n ) ;

    void setCurrentPv ( QString str ) ;

    void ShowMessages ( QListWidget *lw ) ;

    void ShowLastMessageCurrentPv ( QListWidget *lw ) ;

};

#endif // USER_H
