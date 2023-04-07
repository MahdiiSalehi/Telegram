#include <QSqlDatabase>
#include <QtSql>

enum column { phonenum , username , password } ;

class MyQSqlDatabase
{
    QSqlDatabase DB ;
public :
    explicit MyQSqlDatabase() ;
    bool Search ( const QString& , column ) ;
    bool Insert ( const QString& , const QString& , const QString& ) ;
    QVariant GetInfo ( const QString& , column , column ) ;
};

