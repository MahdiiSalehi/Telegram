/********************************************************************************
** Form generated from reading UI file 'codetaeed.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODETAEED_H
#define UI_CODETAEED_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodeTaeed
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *C_F;
    QGridLayout *gridLayout_4;
    QFrame *C_F_MainText;
    QGridLayout *gridLayout_2;
    QLabel *C_LabalMainText;
    QFrame *C_F_EnterCode;
    QGridLayout *gridLayout_3;
    QLabel *C_CaptionLabel;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QPushButton *C_Button;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QLineEdit *C_LineEdit1EnterCode;
    QLineEdit *C_LineEdit2EnterCode;
    QLineEdit *C_LineEdit3EnterCode;
    QLineEdit *C_LineEdit4EnterCode;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CodeTaeed)
    {
        if (CodeTaeed->objectName().isEmpty())
            CodeTaeed->setObjectName(QString::fromUtf8("CodeTaeed"));
        CodeTaeed->resize(584, 466);
        CodeTaeed->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 231, 184);"));
        centralwidget = new QWidget(CodeTaeed);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        C_F = new QFrame(centralwidget);
        C_F->setObjectName(QString::fromUtf8("C_F"));
        C_F->setMaximumSize(QSize(450, 16777215));
        C_F->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 247, 0,70);"));
        C_F->setFrameShape(QFrame::StyledPanel);
        C_F->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(C_F);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        C_F_MainText = new QFrame(C_F);
        C_F_MainText->setObjectName(QString::fromUtf8("C_F_MainText"));
        C_F_MainText->setMinimumSize(QSize(0, 100));
        C_F_MainText->setMaximumSize(QSize(16777215, 100));
        C_F_MainText->setFrameShape(QFrame::StyledPanel);
        C_F_MainText->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(C_F_MainText);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        C_LabalMainText = new QLabel(C_F_MainText);
        C_LabalMainText->setObjectName(QString::fromUtf8("C_LabalMainText"));
        C_LabalMainText->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setPointSize(15);
        C_LabalMainText->setFont(font);
        C_LabalMainText->setFrameShape(QFrame::NoFrame);
        C_LabalMainText->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(C_LabalMainText, 0, 0, 1, 1);


        gridLayout_4->addWidget(C_F_MainText, 0, 0, 1, 1);

        C_F_EnterCode = new QFrame(C_F);
        C_F_EnterCode->setObjectName(QString::fromUtf8("C_F_EnterCode"));
        C_F_EnterCode->setMinimumSize(QSize(200, 200));
        C_F_EnterCode->setFrameShape(QFrame::Box);
        C_F_EnterCode->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(C_F_EnterCode);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        C_CaptionLabel = new QLabel(C_F_EnterCode);
        C_CaptionLabel->setObjectName(QString::fromUtf8("C_CaptionLabel"));
        C_CaptionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(C_CaptionLabel, 2, 1, 1, 1);

        frame_2 = new QFrame(C_F_EnterCode);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        C_Button = new QPushButton(frame_2);
        C_Button->setObjectName(QString::fromUtf8("C_Button"));
        C_Button->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setPointSize(9);
        C_Button->setFont(font1);

        gridLayout_6->addWidget(C_Button, 1, 0, 1, 1);


        gridLayout_3->addWidget(frame_2, 3, 0, 1, 2);

        frame = new QFrame(C_F_EnterCode);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        splitter_2 = new QSplitter(frame);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        C_LineEdit1EnterCode = new QLineEdit(splitter);
        C_LineEdit1EnterCode->setObjectName(QString::fromUtf8("C_LineEdit1EnterCode"));
        C_LineEdit1EnterCode->setMinimumSize(QSize(55, 55));
        C_LineEdit1EnterCode->setMaximumSize(QSize(55, 55));
        QFont font2;
        font2.setPointSize(20);
        C_LineEdit1EnterCode->setFont(font2);
        C_LineEdit1EnterCode->setMaxLength(1);
        splitter->addWidget(C_LineEdit1EnterCode);
        C_LineEdit2EnterCode = new QLineEdit(splitter);
        C_LineEdit2EnterCode->setObjectName(QString::fromUtf8("C_LineEdit2EnterCode"));
        C_LineEdit2EnterCode->setMinimumSize(QSize(55, 55));
        C_LineEdit2EnterCode->setMaximumSize(QSize(55, 55));
        C_LineEdit2EnterCode->setFont(font2);
        C_LineEdit2EnterCode->setMaxLength(1);
        splitter->addWidget(C_LineEdit2EnterCode);
        C_LineEdit3EnterCode = new QLineEdit(splitter);
        C_LineEdit3EnterCode->setObjectName(QString::fromUtf8("C_LineEdit3EnterCode"));
        C_LineEdit3EnterCode->setMinimumSize(QSize(55, 55));
        C_LineEdit3EnterCode->setMaximumSize(QSize(55, 55));
        C_LineEdit3EnterCode->setFont(font2);
        C_LineEdit3EnterCode->setMaxLength(1);
        splitter->addWidget(C_LineEdit3EnterCode);
        C_LineEdit4EnterCode = new QLineEdit(splitter);
        C_LineEdit4EnterCode->setObjectName(QString::fromUtf8("C_LineEdit4EnterCode"));
        C_LineEdit4EnterCode->setMinimumSize(QSize(55, 55));
        C_LineEdit4EnterCode->setMaximumSize(QSize(55, 55));
        C_LineEdit4EnterCode->setFont(font2);
        C_LineEdit4EnterCode->setMaxLength(1);
        splitter->addWidget(C_LineEdit4EnterCode);
        splitter_2->addWidget(splitter);

        gridLayout_5->addWidget(splitter_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 2, 2);


        gridLayout_4->addWidget(C_F_EnterCode, 2, 0, 1, 1);


        gridLayout->addWidget(C_F, 0, 0, 1, 1);

        CodeTaeed->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CodeTaeed);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 584, 25));
        CodeTaeed->setMenuBar(menubar);
        statusbar = new QStatusBar(CodeTaeed);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CodeTaeed->setStatusBar(statusbar);
        QWidget::setTabOrder(C_LineEdit1EnterCode, C_LineEdit2EnterCode);
        QWidget::setTabOrder(C_LineEdit2EnterCode, C_LineEdit3EnterCode);
        QWidget::setTabOrder(C_LineEdit3EnterCode, C_LineEdit4EnterCode);
        QWidget::setTabOrder(C_LineEdit4EnterCode, C_Button);

        retranslateUi(CodeTaeed);

        QMetaObject::connectSlotsByName(CodeTaeed);
    } // setupUi

    void retranslateUi(QMainWindow *CodeTaeed)
    {
        CodeTaeed->setWindowTitle(QApplication::translate("CodeTaeed", "MainWindow", nullptr));
        C_LabalMainText->setText(QApplication::translate("CodeTaeed", "\331\204\330\267\331\201\330\247 \332\251\330\257 \330\252\330\247\333\214\333\214\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        C_CaptionLabel->setText(QApplication::translate("CodeTaeed", "TextLabel", nullptr));
        C_Button->setText(QApplication::translate("CodeTaeed", "\330\252\330\247\333\214\333\214\330\257", nullptr));
        C_LineEdit1EnterCode->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CodeTaeed: public Ui_CodeTaeed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODETAEED_H
