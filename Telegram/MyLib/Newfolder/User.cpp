#include "User.h"

User::User ( QSqlDatabase db , QString _username , QString _name )
{
    DB = db ;
    name = _name ;
    username = _username ;
    rows = 0 ;

    QSqlQuery q (DB) ;

    q.prepare("CREATE TABLE ?"
              "("
              "pv_name VARCHAR (5) ,"
              "contact VARCHAR (26) ,"
              ") ;") ;
    q.addBindValue(name) ;
    q.exec() ;

    q.prepare("SELECT * FROM ? ;") ;
    q.addBindValue(name) ;
    while ( q.next() )
    {
        rows ++ ;
    }

    pv = new Pv* [rows] ;

    q.prepare("SELECT * FROM ? ;") ;
    q.addBindValue(name) ;
    for ( int i = 0 ; q.next() ; i ++ )
    {
        pv[i] = new Pv ( DB ) ;
        pv[i]->name = q.value(0).toString() ;
        pv[i]->contact = q.value(1).toString() ;
    }
}

User::~User()
{
    for ( int i = 0 ; i < rows ; i ++ )
        delete pv [i] ;
    delete pv ;
}

void User::addPV( QString contact )
{
    Pv **pv2 ;
    for ( int i = 0 ; i < rows ; i ++ )
        pv2 [i] = pv [i] ;
    pv2 [rows++] = new Pv ( DB ) ;
    delete[] pv ;
    pv = pv2 ;
    pv[rows-1]->contact = contact ;
    pv[rows-1]->create_table() ;
    QSqlQuery q ( DB ) ;
    q.prepare("INSERT INTO ?"
              "VALUES ( ? , ? ) ;") ;
    q.addBindValue(name) ;
    q.addBindValue(pv[rows-1]->name) ;
    q.addBindValue(contact) ;

    q.prepare("INSERT INTO ?"
              "VALUES ( ? , ? ) ;") ;
    q.addBindValue(contact) ;
    q.addBindValue(pv[rows-1]->name) ;
    q.addBindValue(name) ;
}

void User::add_message(const QString &text)
{
    pv[currentPv]->add_message( text , username ) ;
}

