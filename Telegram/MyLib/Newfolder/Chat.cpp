#include "Chat.h"

Pv::Pv ( QSqlDatabase db )
{
    DB = db ;
}

void Pv::create_table()
{
    QSqlQuery q(DB) ;
    QFile *file = new QFile ("table_name.txt") ;
    QString str ;
    int num ;
    file->open( QFile::ReadWrite ) ;
    str = name = file->readAll() ;
    q.prepare("CREATE TABLE ?"
              "("
              "sender VARCHAR (26) ,"
              "text VARCHAR (200) ,"
              ") ;") ;
    q.addBindValue(name) ;
    q.exec() ;
    num = str.toInt() + 1 ;
    for ( int i = 3 ; i >= 0 ; i -- )
    {
        str [i] = ( num % 10 ) + 48 ;
        num /= 10 ;
    }
    file->seek ( 0 ) ;
    file->write(str.toStdString().c_str()) ;
    file->close() ;
}
