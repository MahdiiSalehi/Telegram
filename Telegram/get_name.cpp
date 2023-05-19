#include "get_name.h"
#include "ui_get_name.h"
#include <MyLib/Newfolder/MyLib.h>
#include <QMessageBox>

extern MyQSqlDatabase db ;
extern QString NewUserName ;
QString Name ;

Get_Name::Get_Name(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Get_Name)
{
    ui->setupUi(this);
}

Get_Name::~Get_Name()
{
    delete ui;
}

void Get_Name::on_GN_button_clicked()
{
    QString s = ui->GN_lineedit->text() ;
    if ( s == "" )
        QMessageBox::information( this , "توجه" , "لطفا نام خود را وارد کنید" , "باشه" ) ;
    else
    {
        db.Insert_name( NewUserName , s ) ;
        Name = s ;
        QMessageBox::information( this , "خوش آمد گویی" , "خوش آمدی " + s , "بریم" ) ;
        // vorod be safhe chat
        this->close() ;
        this->~Get_Name() ;
    }
}

