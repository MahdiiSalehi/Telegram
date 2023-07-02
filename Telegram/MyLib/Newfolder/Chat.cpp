#include "Chat.h"

Pv::Pv ( QSqlDatabase* db )
{
    DB = db ;
}

void Pv::create_table()
{
    num_UnSeenMessages = 0 ;
    QFile *file = new QFile ("table_name.txt") ;
    QString str ;
    file->open( QFile::ReadWrite ) ;
    str = name = file->readAll() ;
    QSqlQuery q (*DB) ;

    q.prepare("CREATE TABLE " + name + " "
              "("
              "sender_name VARCHAR (26) ,"
              "text_message VARCHAR (200) ,"
              "seen INT "
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
    QString str ("txt") ;
    str.append(text) ;
    q.prepare("INSERT INTO " + name + " "
              "VALUES ( ? , ? , ? ) ;") ;
    q.addBindValue(sender) ;
    q.addBindValue(str) ;
    q.addBindValue(0) ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , name , "No2" ) ;
}

void Pv::add_file(const QString &address, const QString &sender)
{
    QSqlQuery q ( *DB ) ;
    QString str ("img") ;
    str.append(address) ;
    q.prepare("INSERT INTO " + name + " "
              "VALUES ( ? , ? , ? ) ;") ;
    q.addBindValue(sender) ;
    q.addBindValue(str) ;
    q.addBindValue(0) ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , name , "No22" ) ;
}

QString Pv::getContact ()
{
    return contact ;
}

QString SeparatorText (const QString &str )
{
    QString str2 ;
    for ( int i = 3 ; i < str.length() ; i ++ )
        str2.append(str.at(i)) ;
    return str2 ;
}

void Pv::ShowMessaegs(QListWidget *lw)
{
    QSqlQuery q (*DB) ;

    q.prepare("SELECT * FROM " + name + " ;") ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , name , "No3" ) ;

    QString str ;
    while ( q.next() )
    {
        //QMessageBox::critical( nullptr , "ERROR" , "S1" ) ;
        //lw->addItem( "->" + q.value(0).toString() + '\n' + q.value(1).toString() ) ;
        str = ( SeparatorText( q.value(1).toString() ) ) ;
        if ( q.value(1).toString()[0] == 'i' )
        {
            QListWidgetItem *item = new QListWidgetItem ("<" + q.value(0).toString() + ">\n") ;
            item->setIcon(QIcon(str)) ;
            lw->addItem(item) ;
        }
        else
        {
            lw->addItem( "->" + q.value(0).toString() + '\n' + str ) ;
        }
    }
    //QMessageBox::critical( nullptr , "ERROR" , "S2" ) ;
    seen_messages() ;
    //QMessageBox::critical( nullptr , "ERROR" , "S3" ) ;
    lw->scrollToBottom() ;
}

void Pv::ShowLastMessage(QListWidget *lw)
{
    QSqlQuery q ( *DB ) ;

    q.prepare("SELECT * FROM " + name + " ;") ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , "" , "No4" ) ;

    q.last() ;
    QString str ( SeparatorText( q.value(1).toString() ) ) ;
    if ( q.value(1).toString()[0] == 'i' )
    {
        QListWidgetItem *item = new QListWidgetItem ("<" + q.value(0).toString() + ">\n") ;
        item->setIcon(QIcon(str)) ;
        lw->addItem(item) ;
    }
    else
    {
        lw->addItem( "<" + q.value(0).toString() + ">" + '\n' + str ) ;
    }
    lw->scrollToBottom() ;
}

QString Pv::getSummaryLastMessage()
{
    QSqlQuery q (*DB) ;
    q.prepare("SELECT * FROM " + name + " ;") ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , "ShowSummary" , "ERROR" ) ;
    QString str ;
    if ( q.last() )
    {
        if ( q.value(1).toString()[0] == 'i' )
        {
            str = "[img]" ;
            return str ;
        }
        else
        {
            str = SeparatorText( q.value(1).toString()) ;
            if ( str.length() < 10 )
            {
                str.append("...") ;
                return str ;
            }
            else
            {
                QString str2 ;
                for ( int i = 0 ; i < 10 ; i ++ )
                    str2.append(str.at(i)) ;
                str2.append("...") ;
                return str2 ;
            }
        }
    }
    return str ;
}

int Pv::CountUnSeenMessages()
{
    num_UnSeenMessages = 0 ;

    QSqlQuery q (*DB) ;

    q.prepare("SELECT * FROM " + name + " ;") ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , "SelectCounting" , "ERROR" ) ;

    if ( q.last() )
    {
        if ( q.value(0).toString() == contact  && !q.value(2).toInt() )
        {
            num_UnSeenMessages ++ ;
        }
        while ( q.previous() && q.value(0).toString() == contact  && !q.value(2).toInt() )
        {
            num_UnSeenMessages ++ ;
        }
    }
    return num_UnSeenMessages ;
}

void Pv::seen_messages()
{
    QSqlQuery q (*DB) ;

    q.prepare("UPDATE " + name + " "
              "SET seen = ? "
              "WHERE sender_name = ? ;") ;
    q.addBindValue(1) ;
    q.addBindValue(contact) ;

    if ( !q.exec() )
        QMessageBox::critical( nullptr , "SELECTseen" , "ERROR" ) ;

    num_UnSeenMessages = 0 ;
}
