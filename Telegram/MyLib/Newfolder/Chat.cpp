#include "Chat.h"

Pv::Pv ( QSqlDatabase* db )
{
    DB = db ;
}

void Pv::create_table()
{
    QFile *file = new QFile ("table_name.txt") ;
    QString str ;
    file->open( QFile::ReadWrite ) ;
    str = name = file->readAll() ;
    QSqlQuery q (*DB) ;

    q.prepare("CREATE TABLE " + name + " "
              "("
              "sender_name VARCHAR (26) ,"
              "text_message VARCHAR (200) "
              ") ;") ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , name , "No1" ) ;
    for ( int i = 3 ; i >= 0 ; i -- )
    {
        if ( str [i] != 'z' )
        {
            char c = str [i].toLatin1() ;
            c ++ ;
            str [i] = c ;
            break ;
        }
        else
        {
            str [i] = 'a' ;
        }
    }
    file->seek ( 0 ) ;
    file->write(str.toUtf8()) ;
    file->close() ;
}

void Pv::add_message(const QString &text, const QString &sender)
{
    QSqlQuery q ( *DB ) ;
    q.prepare("INSERT INTO " + name + " "
              "VALUES ( ? , ? ) ;") ;
    q.addBindValue(sender) ;
    q.addBindValue(text) ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , name , "No2" ) ;
}

QString Pv::getContact ()
{
    return contact ;
}

void Pv::ShowMessaegs(QListWidget *lw)
{
    QSqlQuery q (*DB) ;

    q.prepare("SELECT * FROM " + name + " ;") ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , name , "No3" ) ;

    while ( q.next() )
    {
        lw->addItem( "->" + q.value(0).toString() + '\n' + q.value(1).toString() ) ;
    }
    lw->scrollToBottom() ;
}

void Pv::ShowLastMessage(QListWidget *lw)
{
    QSqlQuery q ( *DB ) ;

    q.prepare("SELECT * FROM " + name + " ;") ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , "" , "No4" ) ;

    q.last() ;
    lw->addItem( "->" + q.value(0).toString() + '\n' + q.value(1).toString() ) ;
    lw->scrollToBottom() ;
}
