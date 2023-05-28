/********************************************************************************
** Form generated from reading UI file 'chatpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGE_H
#define UI_CHATPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatPage)
    {
        if (ChatPage->objectName().isEmpty())
            ChatPage->setObjectName(QString::fromUtf8("ChatPage"));
        ChatPage->resize(800, 600);
        menubar = new QMenuBar(ChatPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        ChatPage->setMenuBar(menubar);
        centralwidget = new QWidget(ChatPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ChatPage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ChatPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChatPage->setStatusBar(statusbar);

        retranslateUi(ChatPage);

        QMetaObject::connectSlotsByName(ChatPage);
    } // setupUi

    void retranslateUi(QMainWindow *ChatPage)
    {
        ChatPage->setWindowTitle(QApplication::translate("ChatPage", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatPage: public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
