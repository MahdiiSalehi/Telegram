#include "start.h"
#include "get_name.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSqlDatabase>
//#include "chatpage.h"
//#include "codetaeed.h"
/*#include <MyLib/Newfolder/MyLib.h>

MyQSqlDatabase db ;*/

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
    srand(time(NULL)) ;
    Start* w = new Start ;
    w->show();
    //ChatPage* w2 = new ChatPage ;
    //w2->show() ;
    return a.exec();
}
