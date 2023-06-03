#include "User.h"

User::User ( QSqlDatabase* db , QString _username , QString _name )
{
    DB = db ;
    name = _name ;
    username = _username ;
    rows = 0 ;

    QSqlQuery q (*DB) ;

    q.prepare("CREATE TABLE " + username + " "
              "("
              "pv_name VARCHAR (5) ,"
              "contact VARCHAR (26) "
              ") ;") ;
    if ( !q.exec() );
        //QMessageBox::critical( nullptr , "" , "No6" ) ;

    q.prepare("SELECT * FROM " + username + " ;") ;
    if ( !q.exec() )
        QMessageBox::critical( nullptr , "" , "No7" ) ;
    while ( q.next() )
    {
        rows ++ ;
    }

    pv = new Pv* [rows] ;

    q.prepare("SELECT * FROM " + username + " ;") ;
    if ( !q.exec() )
            QMessageBox::critical( nullptr , "" , "No8" ) ;
    for ( int i = 0 ; q.next() ; i ++ )
    {
        pv[i] = new Pv ( DB ) ;
        pv[i]->name = q.value(0).toString() ;
        pv[i]->contact = q.value(1).toString() ;
    }
}

User::~User()
{
    if ( rows >= 1 )
        delete[] pv ;
}

void User::addPV( QString contact )
{
    Pv **pv2 = new Pv* [++rows] ;
    for ( int i = 0 ; i < rows - 1 ; i ++ )
        pv2 [i] = pv [i] ;
    pv2 [rows-1] = new Pv ( DB ) ;
    if ( rows != 1 )
        delete[] pv ;
    pv = pv2 ;
    pv[rows-1]->contact = contact ;
    pv[rows-1]->create_table() ;
    QSqlQuery q ( *DB ) ;
    q.prepare("INSERT INTO " + username + " "
              "VALUES ( ? , ? ) ;") ;
    q.addBindValue(pv[rows-1]->name) ;
    q.addBindValue(contact) ;
    if ( !q.exec() )
                QMessageBox::critical( nullptr , "" , "No9" ) ;

    q.prepare("INSERT INTO " + contact + " "
              "VALUES ( ? , ? ) ;") ;
    q.addBindValue(pv[rows-1]->name) ;
    q.addBindValue(username) ;
    if ( !q.exec() )
                QMessageBox::critical( nullptr , "" , "No10" ) ;
}

void User::add_message(const QString &text)
{
    pv[currentPv]->add_message( text , username ) ;
}

void User::add_file (const QString &address)
{
    pv[currentPv]->add_file ( address , username ) ;
}

Pv* User::getCurrentPv ()
{
    return pv[currentPv] ;
}

int User::get_rows()
{
    return rows ;
}

Pv* User::getPv(int n)
{
    if ( n >= 0 && n < rows )
        return pv [n] ;
}

void User::setCurrentPv(QString str)
{
    QString str2 ;
    for ( int i = 0 ; str[i] != '(' && str[i] != '\n' ; i ++ )
        str2 [i] = str [i] ;
    for ( int i = 0 ; i < rows ; i ++ )
    {
        if ( pv [i]->contact == str2 )
        {
            currentPv = i ;
        }
    }
}

void User::ShowMessages(QListWidget *lw)
{
    //QMessageBox::critical( nullptr , "ERROR" , QString::number(currentPv) ) ;
    pv[currentPv]->ShowMessaegs( lw ) ;
    //QMessageBox::critical( nullptr , "ERROR" , "SH3" ) ;
}

void User::ShowLastMessageCurrentPv(QListWidget *lw)
{
    pv[currentPv]->ShowLastMessage( lw ) ;
}

void User::ShowPvs(QListWidget *lw)
{
    lw->clear() ;
    int UnSeenMessage ;
    for ( int i = 0 ; i < rows ; i ++ )
    {
        UnSeenMessage = pv[i]->CountUnSeenMessages() ;
        if ( UnSeenMessage )
            lw->addItem( pv[i]->getContact()+ '(' + QString::number(UnSeenMessage) + ")\n" + pv[i]->getSummaryLastMessage() ) ;
        else
            lw->addItem( pv[i]->getContact() + '\n' + pv[i]->getSummaryLastMessage() ) ;
    }
}
