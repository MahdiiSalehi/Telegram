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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_5;
    QListWidget *C_ContactList;
    QPushButton *C_AddContactButton;
    QLabel *C_ContactName;
    QSplitter *splitter_2;
    QListWidget *C_ChatList;
    QFrame *frame;
    QGridLayout *gridLayout;
    QSplitter *splitter_4;
    QPlainTextEdit *C_PlainText;
    QSplitter *splitter;
    QPushButton *C_SendMessageButton;
    QPushButton *C_SendFileButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatPage)
    {
        if (ChatPage->objectName().isEmpty())
            ChatPage->setObjectName(QString::fromUtf8("ChatPage"));
        ChatPage->resize(919, 640);
        centralwidget = new QWidget(ChatPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter_5 = new QSplitter(centralwidget);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setOrientation(Qt::Vertical);
        C_ContactList = new QListWidget(splitter_5);
        C_ContactList->setObjectName(QString::fromUtf8("C_ContactList"));
        C_ContactList->setMaximumSize(QSize(310, 16777215));
        splitter_5->addWidget(C_ContactList);
        C_AddContactButton = new QPushButton(splitter_5);
        C_AddContactButton->setObjectName(QString::fromUtf8("C_AddContactButton"));
        C_AddContactButton->setMaximumSize(QSize(16777215, 30));
        splitter_5->addWidget(C_AddContactButton);

        gridLayout_2->addWidget(splitter_5, 0, 0, 2, 1);

        C_ContactName = new QLabel(centralwidget);
        C_ContactName->setObjectName(QString::fromUtf8("C_ContactName"));
        C_ContactName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        C_ContactName->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(C_ContactName, 0, 1, 1, 1);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        C_ChatList = new QListWidget(splitter_2);
        C_ChatList->setObjectName(QString::fromUtf8("C_ChatList"));
        splitter_2->addWidget(C_ChatList);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 120));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter_4 = new QSplitter(frame);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        C_PlainText = new QPlainTextEdit(splitter_4);
        C_PlainText->setObjectName(QString::fromUtf8("C_PlainText"));
        splitter_4->addWidget(C_PlainText);
        splitter = new QSplitter(splitter_4);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        C_SendMessageButton = new QPushButton(splitter);
        C_SendMessageButton->setObjectName(QString::fromUtf8("C_SendMessageButton"));
        C_SendMessageButton->setMaximumSize(QSize(16777215, 30));
        splitter->addWidget(C_SendMessageButton);
        C_SendFileButton = new QPushButton(splitter);
        C_SendFileButton->setObjectName(QString::fromUtf8("C_SendFileButton"));
        C_SendFileButton->setMaximumSize(QSize(16777215, 30));
        splitter->addWidget(C_SendFileButton);
        splitter_4->addWidget(splitter);

        gridLayout->addWidget(splitter_4, 0, 0, 1, 1);

        splitter_2->addWidget(frame);

        gridLayout_2->addWidget(splitter_2, 1, 1, 1, 1);

        ChatPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 919, 25));
        ChatPage->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChatPage->setStatusBar(statusbar);

        retranslateUi(ChatPage);

        QMetaObject::connectSlotsByName(ChatPage);
    } // setupUi

    void retranslateUi(QMainWindow *ChatPage)
    {
        ChatPage->setWindowTitle(QApplication::translate("ChatPage", "MainWindow", nullptr));
        C_AddContactButton->setText(QApplication::translate("ChatPage", "AddContact", nullptr));
        C_ContactName->setText(QApplication::translate("ChatPage", "TextLabel", nullptr));
        C_SendMessageButton->setText(QApplication::translate("ChatPage", "Send Message", nullptr));
        C_SendFileButton->setText(QApplication::translate("ChatPage", "Send File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatPage: public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
