#include <QSqlDatabase>
#include <QtSql>
#include <QListWidget>
#include <QListWidgetItem>
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

    int num_UnSeenMessages ;

public :

    QString getContact () ;

    void ShowMessaegs ( QListWidget *lw ) ;

    void ShowLastMessage ( QListWidget *lw ) ;

    QString getSummaryLastMessage () ;

    void create_table () ;

    void add_message ( const QString &text , const QString &sender ) ;

    void add_file ( const QString &address , const QString &sender ) ;

    int CountUnSeenMessages () ;

    //int get_num_UnSeenMessages () ;

    void seen_messages () ;

};

#endif // CHAT_H
