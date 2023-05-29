QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyLib/Newfolder/Chat.cpp \
    MyLib/Newfolder/User.cpp \
    chatpage.cpp \
    codetaeed.cpp \
    enter.cpp \
    get_name.cpp \
    main.cpp \
    start.cpp \
    MyLib/Newfolder/MyLib.cpp

HEADERS += \
    MyLib/Newfolder/Chat.h \
    MyLib/Newfolder/User.h \
    chatpage.h \
    codetaeed.h \
    enter.h \
    get_name.h \
    start.h \
    MyLib/Newfolder/MyLib.h

FORMS += \
    chatpage.ui \
    codetaeed.ui \
    enter.ui \
    get_name.ui \
    start.ui

TRANSLATIONS += \
    Telegram_fa_IR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Pictures/Pictures.qrc

DISTFILES += \
    S_Image.png
