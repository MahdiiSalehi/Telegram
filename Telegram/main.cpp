#include "start.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSqlDatabase>

QSqlDatabase DB ;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Telegram_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    DB = QSqlDatabase::addDatabase("QSQLITE") ;
    DB.setHostName("127.0.0.1") ;
    DB.setPort(3306) ;
    DB.setUserName("root") ;
    DB.setPassword("AAAAAAAA") ;
    DB.setDatabaseName("test0") ;
    Start w;
    w.show();
    return a.exec();
}
