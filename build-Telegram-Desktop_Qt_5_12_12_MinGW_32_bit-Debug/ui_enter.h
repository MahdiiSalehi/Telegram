/********************************************************************************
** Form generated from reading UI file 'enter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTER_H
#define UI_ENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Enter
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *E_Frame;
    QGridLayout *gridLayout_2;
    QLabel *E_TitleText;
    QSplitter *splitter_4;
    QSplitter *splitter;
    QLineEdit *E_U_LineEdit;
    QLabel *E_U_Label;
    QLabel *E_ErrorUsernameLabel;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QLineEdit *E_P_LineEdit;
    QPushButton *E_P_VisableButton;
    QLabel *E_P_Label;
    QLabel *E_ErrorPasswordLabel;
    QFrame *E_FCaptcha;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_8;
    QFrame *E_FCaptchaImage;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_7;
    QLabel *E_CaptchaNum1;
    QLabel *E_CaptchaNum2;
    QLabel *E_CaptchaNum3;
    QLabel *E_CaptchaNum4;
    QSplitter *splitter_6;
    QTextEdit *E_CaptchaTextEdit;
    QSplitter *splitter_5;
    QPushButton *pushButton;
    QLineEdit *E_CaptchaLineEdit;
    QPushButton *E_EntRegButton;
    QPushButton *E_GotoButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Enter)
    {
        if (Enter->objectName().isEmpty())
            Enter->setObjectName(QString::fromUtf8("Enter"));
        Enter->resize(766, 600);
        Enter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 231, 184);"));
        centralwidget = new QWidget(Enter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        E_Frame = new QFrame(centralwidget);
        E_Frame->setObjectName(QString::fromUtf8("E_Frame"));
        E_Frame->setMaximumSize(QSize(450, 16777215));
        E_Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 247, 0,70);"));
        E_Frame->setFrameShape(QFrame::StyledPanel);
        E_Frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(E_Frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        E_TitleText = new QLabel(E_Frame);
        E_TitleText->setObjectName(QString::fromUtf8("E_TitleText"));
        E_TitleText->setMinimumSize(QSize(0, 0));
        E_TitleText->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Andalus"));
        font.setPointSize(30);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        E_TitleText->setFont(font);
        E_TitleText->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(E_TitleText, 0, 0, 1, 1);

        splitter_4 = new QSplitter(E_Frame);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_4);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        E_U_LineEdit = new QLineEdit(splitter);
        E_U_LineEdit->setObjectName(QString::fromUtf8("E_U_LineEdit"));
        E_U_LineEdit->setMinimumSize(QSize(0, 0));
        E_U_LineEdit->setMaximumSize(QSize(16777215, 30));
        splitter->addWidget(E_U_LineEdit);
        E_U_Label = new QLabel(splitter);
        E_U_Label->setObjectName(QString::fromUtf8("E_U_Label"));
        E_U_Label->setMinimumSize(QSize(0, 0));
        E_U_Label->setMaximumSize(QSize(16777215, 30));
        E_U_Label->setAlignment(Qt::AlignCenter);
        splitter->addWidget(E_U_Label);
        splitter_4->addWidget(splitter);
        E_ErrorUsernameLabel = new QLabel(splitter_4);
        E_ErrorUsernameLabel->setObjectName(QString::fromUtf8("E_ErrorUsernameLabel"));
        E_ErrorUsernameLabel->setMinimumSize(QSize(0, 0));
        E_ErrorUsernameLabel->setMaximumSize(QSize(16777215, 60));
        splitter_4->addWidget(E_ErrorUsernameLabel);

        gridLayout_2->addWidget(splitter_4, 1, 0, 1, 1);

        splitter_3 = new QSplitter(E_Frame);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        E_P_LineEdit = new QLineEdit(splitter_2);
        E_P_LineEdit->setObjectName(QString::fromUtf8("E_P_LineEdit"));
        E_P_LineEdit->setMinimumSize(QSize(0, 0));
        E_P_LineEdit->setMaximumSize(QSize(16777215, 30));
        splitter_2->addWidget(E_P_LineEdit);
        E_P_VisableButton = new QPushButton(splitter_2);
        E_P_VisableButton->setObjectName(QString::fromUtf8("E_P_VisableButton"));
        E_P_VisableButton->setMinimumSize(QSize(0, 0));
        E_P_VisableButton->setMaximumSize(QSize(30, 30));
        splitter_2->addWidget(E_P_VisableButton);
        E_P_Label = new QLabel(splitter_2);
        E_P_Label->setObjectName(QString::fromUtf8("E_P_Label"));
        E_P_Label->setMinimumSize(QSize(0, 0));
        E_P_Label->setMaximumSize(QSize(16777215, 30));
        E_P_Label->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(E_P_Label);
        splitter_3->addWidget(splitter_2);
        E_ErrorPasswordLabel = new QLabel(splitter_3);
        E_ErrorPasswordLabel->setObjectName(QString::fromUtf8("E_ErrorPasswordLabel"));
        E_ErrorPasswordLabel->setMinimumSize(QSize(0, 0));
        E_ErrorPasswordLabel->setMaximumSize(QSize(16777215, 60));
        splitter_3->addWidget(E_ErrorPasswordLabel);

        gridLayout_2->addWidget(splitter_3, 2, 0, 1, 1);

        E_FCaptcha = new QFrame(E_Frame);
        E_FCaptcha->setObjectName(QString::fromUtf8("E_FCaptcha"));
        E_FCaptcha->setMaximumSize(QSize(16777215, 100));
        E_FCaptcha->setFrameShape(QFrame::StyledPanel);
        E_FCaptcha->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(E_FCaptcha);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter_8 = new QSplitter(E_FCaptcha);
        splitter_8->setObjectName(QString::fromUtf8("splitter_8"));
        splitter_8->setOrientation(Qt::Horizontal);
        E_FCaptchaImage = new QFrame(splitter_8);
        E_FCaptchaImage->setObjectName(QString::fromUtf8("E_FCaptchaImage"));
        E_FCaptchaImage->setMinimumSize(QSize(0, 0));
        E_FCaptchaImage->setMaximumSize(QSize(210, 16777215));
        E_FCaptchaImage->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix4/Captcha.jpg);"));
        E_FCaptchaImage->setFrameShape(QFrame::StyledPanel);
        E_FCaptchaImage->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(E_FCaptchaImage);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        splitter_7 = new QSplitter(E_FCaptchaImage);
        splitter_7->setObjectName(QString::fromUtf8("splitter_7"));
        splitter_7->setOrientation(Qt::Horizontal);
        E_CaptchaNum1 = new QLabel(splitter_7);
        E_CaptchaNum1->setObjectName(QString::fromUtf8("E_CaptchaNum1"));
        QFont font1;
        font1.setPointSize(15);
        E_CaptchaNum1->setFont(font1);
        E_CaptchaNum1->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix4/Captcha.jpg);"));
        E_CaptchaNum1->setAlignment(Qt::AlignCenter);
        splitter_7->addWidget(E_CaptchaNum1);
        E_CaptchaNum2 = new QLabel(splitter_7);
        E_CaptchaNum2->setObjectName(QString::fromUtf8("E_CaptchaNum2"));
        E_CaptchaNum2->setFont(font1);
        E_CaptchaNum2->setAlignment(Qt::AlignCenter);
        splitter_7->addWidget(E_CaptchaNum2);
        E_CaptchaNum3 = new QLabel(splitter_7);
        E_CaptchaNum3->setObjectName(QString::fromUtf8("E_CaptchaNum3"));
        E_CaptchaNum3->setFont(font1);
        E_CaptchaNum3->setAlignment(Qt::AlignCenter);
        splitter_7->addWidget(E_CaptchaNum3);
        E_CaptchaNum4 = new QLabel(splitter_7);
        E_CaptchaNum4->setObjectName(QString::fromUtf8("E_CaptchaNum4"));
        E_CaptchaNum4->setFont(font1);
        E_CaptchaNum4->setAlignment(Qt::AlignCenter);
        splitter_7->addWidget(E_CaptchaNum4);

        gridLayout_4->addWidget(splitter_7, 0, 0, 1, 1);

        splitter_8->addWidget(E_FCaptchaImage);
        splitter_6 = new QSplitter(splitter_8);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setOrientation(Qt::Vertical);
        E_CaptchaTextEdit = new QTextEdit(splitter_6);
        E_CaptchaTextEdit->setObjectName(QString::fromUtf8("E_CaptchaTextEdit"));
        E_CaptchaTextEdit->setMinimumSize(QSize(0, 0));
        E_CaptchaTextEdit->setMaximumSize(QSize(16777215, 180));
        splitter_6->addWidget(E_CaptchaTextEdit);
        splitter_5 = new QSplitter(splitter_6);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(30, 30));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix3/ReGenerate.jpg);"));
        splitter_5->addWidget(pushButton);
        E_CaptchaLineEdit = new QLineEdit(splitter_5);
        E_CaptchaLineEdit->setObjectName(QString::fromUtf8("E_CaptchaLineEdit"));
        E_CaptchaLineEdit->setMinimumSize(QSize(0, 0));
        E_CaptchaLineEdit->setMaximumSize(QSize(200, 40));
        splitter_5->addWidget(E_CaptchaLineEdit);
        splitter_6->addWidget(splitter_5);
        splitter_8->addWidget(splitter_6);

        gridLayout_3->addWidget(splitter_8, 0, 0, 1, 1);


        gridLayout_2->addWidget(E_FCaptcha, 3, 0, 1, 1);

        E_EntRegButton = new QPushButton(E_Frame);
        E_EntRegButton->setObjectName(QString::fromUtf8("E_EntRegButton"));
        E_EntRegButton->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        E_EntRegButton->setFont(font2);

        gridLayout_2->addWidget(E_EntRegButton, 4, 0, 1, 1);

        E_GotoButton = new QPushButton(E_Frame);
        E_GotoButton->setObjectName(QString::fromUtf8("E_GotoButton"));
        E_GotoButton->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(E_GotoButton, 5, 0, 1, 1);


        gridLayout->addWidget(E_Frame, 1, 0, 1, 1);

        Enter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Enter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 766, 25));
        Enter->setMenuBar(menubar);
        statusbar = new QStatusBar(Enter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Enter->setStatusBar(statusbar);

        retranslateUi(Enter);

        QMetaObject::connectSlotsByName(Enter);
    } // setupUi

    void retranslateUi(QMainWindow *Enter)
    {
        Enter->setWindowTitle(QApplication::translate("Enter", "MainWindow", nullptr));
        E_TitleText->setText(QApplication::translate("Enter", "\331\210\330\261\331\210\330\257", nullptr));
        E_U_Label->setText(QApplication::translate("Enter", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        E_ErrorUsernameLabel->setText(QString());
        E_P_VisableButton->setText(QString());
        E_P_Label->setText(QApplication::translate("Enter", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        E_ErrorPasswordLabel->setText(QString());
        E_CaptchaNum1->setText(QString());
        E_CaptchaNum2->setText(QString());
        E_CaptchaNum3->setText(QString());
        E_CaptchaNum4->setText(QString());
        E_CaptchaTextEdit->setHtml(QApplication::translate("Enter", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\331\204\330\267\331\201\330\247 \330\271\330\250\330\247\330\261\330\252 \330\257\330\247\330\256\331\204 \330\271\332\251\330\263 \330\261\330\247 \330\257\330\261</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\332\251\330\247\330\257\330\261 \330\262\333\214\330\261 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257</p></body></html>", nullptr));
        pushButton->setText(QString());
        E_EntRegButton->setText(QApplication::translate("Enter", "\331\210\330\261\331\210\330\257", nullptr));
        E_GotoButton->setText(QApplication::translate("Enter", "\330\242\333\214\330\247 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214 \331\206\330\257\330\247\330\261\333\214\330\257\330\237 \330\250\330\261\330\247\333\214 \330\253\330\250\330\252\331\206\330\247\331\205 \332\251\331\204\333\214\332\251 \332\251\331\206\333\214\330\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Enter: public Ui_Enter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTER_H
