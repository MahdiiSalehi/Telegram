/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QFrame *S_FButton;
    QGridLayout *gridLayout;
    QPushButton *S_Buttom;
    QFrame *S_FMainText;
    QGridLayout *gridLayout_2;
    QLabel *S_MainText;
    QFrame *S_FCaptionText;
    QGridLayout *gridLayout_3;
    QLabel *S_Caption;
    QFrame *S_FImage;
    QGridLayout *gridLayout_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName(QString::fromUtf8("Start"));
        Start->resize(800, 600);
        Start->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 231, 184);"));
        centralwidget = new QWidget(Start);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        S_FButton = new QFrame(centralwidget);
        S_FButton->setObjectName(QString::fromUtf8("S_FButton"));
        S_FButton->setFrameShape(QFrame::StyledPanel);
        S_FButton->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(S_FButton);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        S_Buttom = new QPushButton(S_FButton);
        S_Buttom->setObjectName(QString::fromUtf8("S_Buttom"));
        S_Buttom->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setPointSize(10);
        S_Buttom->setFont(font);
        S_Buttom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 207, 0,50);\n"
""));

        gridLayout->addWidget(S_Buttom, 0, 0, 1, 1);


        gridLayout_5->addWidget(S_FButton, 2, 0, 1, 1);

        S_FMainText = new QFrame(centralwidget);
        S_FMainText->setObjectName(QString::fromUtf8("S_FMainText"));
        S_FMainText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 247, 0,40);"));
        S_FMainText->setFrameShape(QFrame::StyledPanel);
        S_FMainText->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(S_FMainText);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        S_MainText = new QLabel(S_FMainText);
        S_MainText->setObjectName(QString::fromUtf8("S_MainText"));
        QFont font1;
        font1.setPointSize(9);
        S_MainText->setFont(font1);
        S_MainText->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(S_MainText, 0, 0, 1, 1);


        gridLayout_5->addWidget(S_FMainText, 1, 0, 1, 1);

        S_FCaptionText = new QFrame(centralwidget);
        S_FCaptionText->setObjectName(QString::fromUtf8("S_FCaptionText"));
        S_FCaptionText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 247, 0,70);"));
        S_FCaptionText->setFrameShape(QFrame::StyledPanel);
        S_FCaptionText->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(S_FCaptionText);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        S_Caption = new QLabel(S_FCaptionText);
        S_Caption->setObjectName(QString::fromUtf8("S_Caption"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Vladimir Script"));
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        S_Caption->setFont(font2);
        S_Caption->setStyleSheet(QString::fromUtf8(""));
        S_Caption->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(S_Caption, 0, 0, 1, 1);


        gridLayout_5->addWidget(S_FCaptionText, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 0, 1, 1);

        S_FImage = new QFrame(centralwidget);
        S_FImage->setObjectName(QString::fromUtf8("S_FImage"));
        S_FImage->setMinimumSize(QSize(300, 100));
        S_FImage->setMaximumSize(QSize(16777215, 300));
        S_FImage->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/S_Image.jpg);"));
        S_FImage->setFrameShape(QFrame::StyledPanel);
        S_FImage->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(S_FImage);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));

        gridLayout_6->addWidget(S_FImage, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        Start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Start);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Start->setMenuBar(menubar);
        statusbar = new QStatusBar(Start);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Start->setStatusBar(statusbar);

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QMainWindow *Start)
    {
        Start->setWindowTitle(QApplication::translate("Start", "Start", nullptr));
        S_Buttom->setText(QApplication::translate("Start", "Start", nullptr));
        S_MainText->setText(QApplication::translate("Start", "Welcome to the best Telegram ! click start", nullptr));
        S_Caption->setText(QApplication::translate("Start", "Telegram ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
