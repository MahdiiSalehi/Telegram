#include <QSqlDatabase>
#include <QtSql>

enum column { phonenum , username , password , name } ;

class MyQSqlDatabase
{
    QSqlDatabase DB ;
public :
    explicit MyQSqlDatabase() ;
    bool Search ( const QString& , column ) ;
    bool Insert1 ( const QString& , const QString& , const QString& ) ;
    QVariant GetInfo ( const QString& , column , column ) ;
};

