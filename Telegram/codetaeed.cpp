#include "codetaeed.h"
#include "ui_codetaeed.h"
#include <MyLib/Newfolder/MyLib.h>

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

extern MyQSqlDatabase db ;
enum condition { Entering , Registering } ;
extern condition con ;
extern QString NewUserName ;
extern QString NewPhoneNum ;
extern QString NewPassword ;

QString Code_Taeed ("") ;

CodeTaeed::CodeTaeed(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CodeTaeed)
{
    ui->setupUi(this);
    this->setWindowTitle("کد تایید") ;
    ui->C_LineEdit1EnterCode->setAlignment(Qt::AlignCenter) ;
    ui->C_LineEdit2EnterCode->setAlignment(Qt::AlignCenter) ;
    ui->C_LineEdit3EnterCode->setAlignment(Qt::AlignCenter) ;
    ui->C_LineEdit4EnterCode->setAlignment(Qt::AlignCenter) ;
    ui->C_LineEdit1EnterCode->setValidator( new QIntValidator ) ;
    ui->C_LineEdit2EnterCode->setValidator( new QIntValidator ) ;
    ui->C_LineEdit3EnterCode->setValidator( new QIntValidator ) ;
    ui->C_LineEdit4EnterCode->setValidator( new QIntValidator ) ;
    ui->C_CaptionLabel->setText("<ul><li>کد تایید در صفحه ای جداگانه نشان داده شده است.</li></ul>") ;
    for ( int i = 0 ; i < 4 ; i ++ )
        Code_Taeed += ( QString::number( rand() % 10 ) ) ;
    QFont f1 ( "MS Shell Dlg 2" , 25 ) ;
    QFont f2 ( "MS Shell Dlg 2" , 13 ) ;
    w->setFixedSize(280,140) ;
    w->setWindowTitle("تلگرام") ;
    ly->addWidget(lb) ;
    ly->addWidget(le) ;
    le->setText(Code_Taeed) ;
    le->setFont(f1) ;
    le->setAlignment(Qt::AlignCenter) ;
    le->setDisabled(1) ;
    lb->setText("کد تایید:") ;
    lb->setAlignment(Qt::AlignCenter) ;
    lb->setFont(f2) ;
    w->move(1,1) ;
    w->show() ;
}

CodeTaeed::~CodeTaeed()
{
    delete lb ;
    delete le ;
    delete ly ;
    delete w ;

    delete ui;
}
/*
 neveshtan slot raftan be lineedit badi --- OK!
 neveshtan slot button
 safhe joda --- OK!
 */

void CodeTaeed::on_C_LineEdit1EnterCode_textChanged(const QString &arg1)
{
    if ( arg1.length() )
        ui->C_LineEdit2EnterCode->setFocus() ;
}


void CodeTaeed::on_C_LineEdit2EnterCode_textChanged(const QString &arg1)
{
    if ( arg1.length() )
        ui->C_LineEdit3EnterCode->setFocus() ;
}


void CodeTaeed::on_C_LineEdit3EnterCode_textChanged(const QString &arg1)
{
    if ( arg1.length() )
        ui->C_LineEdit4EnterCode->setFocus() ;
}

void ClearMemory ()
{

}

void CodeTaeed::on_C_Button_clicked()
{
    QString str ;
    str = ui->C_LineEdit1EnterCode->text() ;
    str += ui->C_LineEdit2EnterCode->text() ;
    str += ui->C_LineEdit3EnterCode->text() ;
    str += ui->C_LineEdit4EnterCode->text() ;
    if ( str == Code_Taeed )
    {
        if ( con == Entering )
        {
            QMessageBox::information(this,"توجه","<ul><li>با موفقیت وارد حساب خود شدید!</li></ul>","باشه") ;
        }
        else
        {
            QMessageBox::information(this,"توجه","<ul><li>ثبتنام با موفقیت انجام شد!</li></ul>","باشه") ;
            db.Insert1(NewPhoneNum,NewUserName,NewPassword) ;
        }
        this->close() ;
        this->~CodeTaeed() ;
    }
    else
    {
        QMessageBox::information(this,"توجه","<ul><li>کد وارد شده با کد تایید تطابق ندارد.</li></ul>","باشه") ;
    }
    return ;
}

