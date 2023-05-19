/********************************************************************************
** Form generated from reading UI file 'get_name.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GET_NAME_H
#define UI_GET_NAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Get_Name
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QFrame *GN_titleFrame;
    QGridLayout *gridLayout_2;
    QLabel *GN_titleLabel;
    QFrame *GN_frame;
    QGridLayout *gridLayout;
    QLineEdit *GN_lineedit;
    QHBoxLayout *horizontalLayout;
    QPushButton *GN_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Get_Name)
    {
        if (Get_Name->objectName().isEmpty())
            Get_Name->setObjectName(QString::fromUtf8("Get_Name"));
        Get_Name->resize(349, 267);
        Get_Name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 231, 184);"));
        centralwidget = new QWidget(Get_Name);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        GN_titleFrame = new QFrame(centralwidget);
        GN_titleFrame->setObjectName(QString::fromUtf8("GN_titleFrame"));
        GN_titleFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 247, 0,70);"));
        GN_titleFrame->setFrameShape(QFrame::StyledPanel);
        GN_titleFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(GN_titleFrame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        GN_titleLabel = new QLabel(GN_titleFrame);
        GN_titleLabel->setObjectName(QString::fromUtf8("GN_titleLabel"));
        GN_titleLabel->setMinimumSize(QSize(0, 60));
        GN_titleLabel->setMaximumSize(QSize(16777215, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Andalus"));
        font.setPointSize(23);
        GN_titleLabel->setFont(font);
        GN_titleLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(GN_titleLabel, 0, 0, 1, 1);


        gridLayout_3->addWidget(GN_titleFrame, 0, 0, 1, 1);

        GN_frame = new QFrame(centralwidget);
        GN_frame->setObjectName(QString::fromUtf8("GN_frame"));
        GN_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 247, 0,70);"));
        GN_frame->setFrameShape(QFrame::StyledPanel);
        GN_frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(GN_frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GN_lineedit = new QLineEdit(GN_frame);
        GN_lineedit->setObjectName(QString::fromUtf8("GN_lineedit"));
        GN_lineedit->setMaximumSize(QSize(220, 27));
        QFont font1;
        font1.setPointSize(9);
        GN_lineedit->setFont(font1);
        GN_lineedit->setMaxLength(20);

        gridLayout->addWidget(GN_lineedit, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        GN_button = new QPushButton(GN_frame);
        GN_button->setObjectName(QString::fromUtf8("GN_button"));
        GN_button->setMaximumSize(QSize(100, 30));
        GN_button->setFont(font1);

        horizontalLayout->addWidget(GN_button);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_3->addWidget(GN_frame, 1, 0, 1, 1);

        Get_Name->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Get_Name);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 349, 25));
        Get_Name->setMenuBar(menubar);
        statusbar = new QStatusBar(Get_Name);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Get_Name->setStatusBar(statusbar);

        retranslateUi(Get_Name);

        QMetaObject::connectSlotsByName(Get_Name);
    } // setupUi

    void retranslateUi(QMainWindow *Get_Name)
    {
        Get_Name->setWindowTitle(QApplication::translate("Get_Name", "MainWindow", nullptr));
        GN_titleLabel->setText(QApplication::translate("Get_Name", "\331\204\330\267\331\201\330\247 \331\206\330\247\331\205 \330\256\331\210\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        GN_button->setText(QApplication::translate("Get_Name", "\330\247\331\210\332\251\333\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Get_Name: public Ui_Get_Name {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GET_NAME_H
