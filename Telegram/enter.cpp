#include "enter.h"
#include "ui_enter.h"
#include <QKeyEvent>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>

enum condition { Entering , Registering } ;
condition con = Entering ;
QString PersianLetters = "0123456789 ئاآبپتثجچحخدذرزژسشصضطظعغفقکگلمنوهی" ;
QString CaptchaCode ;
extern QSqlDatabase DB ;
bool CheckLineEditUsername ;
bool CheckLineEditPassword ;

Enter::Enter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Enter)
{
    ui->setupUi(this);
    this->setWindowTitle("ورود") ;
    ui->E_FCaptcha->hide() ;
    ui->E_ErrorPasswordLabel->hide() ;
    ui->E_ErrorUsernameLabel->hide() ;
    ui->E_CaptchaTextEdit->setReadOnly(1) ;
    ui->E_U_LineEdit->setMaxLength(25) ;
    ui->E_P_LineEdit->setMaxLength(25) ;
    ui->E_P_VisableButton->setStyleSheet("image: url(:/new/prefix2/EyeIcon(3.1).jpg);") ;
    ui->E_P_LineEdit->setEchoMode(QLineEdit::Password) ;
    ui->E_FCaptchaImage->setDisabled(1) ;
    if ( !DB.open() )
    {
        QMessageBox::information(this,"توجه","دیتابیس باز نشد","خروج") ;
        this->~Enter() ;
    }
}

Enter::~Enter()
{
    delete ui;
}

void Enter::GotoEntering ()
{
    this->setWindowTitle("ورود") ;
    ui->E_FCaptcha->hide() ;
    ui->E_ErrorPasswordLabel->hide() ;
    ui->E_ErrorUsernameLabel->hide() ;
    ui->E_P_LineEdit->setText("") ;
    ui->E_U_LineEdit->setText("") ;
    ui->E_TitleText->setText("ورود") ;
    ui->E_EntRegButton->setText("ورود") ;
    ui->E_GotoButton->setText("آیا حساب کاربری ندارید؟ برای ثبتنام کلیک کنید") ;
    ui->E_CaptchaLineEdit->setText("") ;
    con = Entering ;
    return ;
}

void Enter::GotoRegistering ()
{
    this->setWindowTitle("ثبتنام") ;
    ui->E_FCaptcha->show() ;
    ui->E_ErrorPasswordLabel->hide() ;
    ui->E_ErrorUsernameLabel->hide() ;
    ui->E_P_LineEdit->setText("") ;
    ui->E_U_LineEdit->setText("") ;
    ui->E_TitleText->setText("ثبتنام") ;
    ui->E_EntRegButton->setText("ثبتنام") ;
    ui->E_GotoButton->setText("آیا حساب کاربری دارید؟ برای ورود کلیک کنید") ;
    GenerateCaptchaCode() ;
    con = Registering ;
    return ;
}

void Enter::on_E_GotoButton_clicked()
{
    if ( con == Entering )
        GotoRegistering() ;
    else
        GotoEntering() ;
    return ;
}

bool Enter::CheckRuleSpeciaLetters( QString str )
{
    bool sw ;
    for ( QChar i : str )
    {
        sw = false ;
        for ( QChar j : PersianLetters )
            if ( i == j )
            {
                sw = true ;
                break ;
            }
        if ( !sw )
            if ( ( i < 48 || i > 57 ) && ( i < 65 || i > 90 ) && ( i < 97 || i > 122 ) )
                return false ;
    }
    return true ;
}


void Enter::on_E_U_LineEdit_textChanged(const QString &arg1)
{
    /*
      The rules of username :
      maximum size : 25 ;
      cannot start with space ;
      Only letters and numbers can be used ;
    */
    if ( arg1 == "" )
        return ;
    bool sw = false ;
    QString str ("<ul>") ;
    if ( !CheckRuleSpeciaLetters (arg1) )
    {
        str += "<li>لطفا فقط از اعداد و حروف استفاده کنید</li>" ;
        sw = true ;
    }
    if ( arg1.at(0) == ' ' )
    {
        str += "<li>نام کاربری نمیتواند با اسپیس شروع شود</li>" ;
        sw = true ;
    }
    if ( sw )
    {
        str += "</ul>" ;
        ui->E_ErrorUsernameLabel->setText(str) ;
        ui->E_ErrorUsernameLabel->show() ;
        CheckLineEditUsername = false ;
    }
    else
    {
        ui->E_ErrorUsernameLabel->hide() ;
        CheckLineEditUsername =  true ;
    }
    return ;
}



void Enter::on_E_P_LineEdit_textChanged(const QString &arg1)
{
    /*
      The rules of password :
      maximum size : 25 ;
      minimum size : 7 ;
      cannot start with space ;
      Characters other than letters and numbers should be used
    */
    if ( arg1 == "" )
        return ;
    bool sw = false ;
    QString str ("<ul>") ;
    if ( CheckRuleSpeciaLetters(arg1) )
    {
        str += "<li>لطفا از کارکتر هایی غیر از حروف و اعداد هم استفاده کنید</li>" ;
        sw = true ;
    }
    if ( arg1.length() < 7 )
    {
        str += "<li>طول رمز عبور حداقل باید هفت رقم باشد</li>" ;
        sw = true ;
    }
    if ( arg1.at(0) == ' ' )
    {
        str += "<li>رمز عبور نمیتواند با اسپیس شروع شود</li>" ;
        sw = true ;
    }
    if ( sw )
    {
        str += "</ul>" ;
        ui->E_ErrorPasswordLabel->setText(str) ;
        ui->E_ErrorPasswordLabel->show() ;
        CheckLineEditPassword = false ;
    }
    else
    {
        ui->E_ErrorPasswordLabel->hide() ;
        CheckLineEditPassword = true ;
    }
    return ;
}


void Enter::on_E_P_VisableButton_clicked()
{
    static bool checked = false ;
    if ( checked )
    {
        ui->E_P_VisableButton->setStyleSheet("image: url(:/new/prefix2/EyeIcon(3.1).jpg);") ;
        ui->E_P_LineEdit->setEchoMode(QLineEdit::Password) ;
        checked = false ;
    }
    else
    {
        ui->E_P_VisableButton->setStyleSheet("image: url(:/new/prefix2/EyeIcon(3.0).jpg);") ;
        ui->E_P_LineEdit->setEchoMode(QLineEdit::Normal) ;
        checked = true ;
    }
    return ;
}

void Enter::GenerateCaptchaCode()
{
    QChar ch ;
    int num ;
    CaptchaCode = "" ;

    num = rand() % 10 ;
    ch = num + 48 ;
    CaptchaCode += ch ;
    ui->E_CaptchaNum1->setText(ch) ;

    num = rand() % 10 ;
    ch = num + 48 ;
    CaptchaCode += ch ;
    ui->E_CaptchaNum2->setText(ch) ;

    num = rand() % 10 ;
    ch = num + 48 ;
    CaptchaCode += ch ;
    ui->E_CaptchaNum3->setText(ch) ;

    num = rand() % 10 ;
    ch = num + 48 ;
    CaptchaCode += ch ;
    ui->E_CaptchaNum4->setText(ch) ;

    return ;
}

void Enter::on_pushButton_clicked()
{
    GenerateCaptchaCode() ;
    return ;
}


void Enter::on_E_EntRegButton_clicked()
{
    QString str ("<ul>") ;
    bool sw = false ;
    if ( ui->E_U_LineEdit->text() == "" )
    {
        str += "<li>لطفا نام کاربری خود را وارد کنید.</li>" ;
        sw = true ;
    }
    else if ( !CheckLineEditUsername )
    {
        str += "<li>لطفا نام کاربری خود را اصلاح کنید.</li>" ;
        sw = true ;
    }
    if ( ui->E_P_LineEdit->text() == "" )
    {
        str += "<li>لطفا رمز عبور خود را وارد کنید.</li>" ;
        sw = true ;
    }
    else if ( !CheckLineEditPassword )
    {
        str += "<li>لطفا رمز عبور خود را اصلاح کنید.</li>" ;
        sw = true ;
    }
    if ( !sw )
    {
        if ( con == Entering )
        {
            // search in database
            //error or safhe code taeed
        }
        else
        {
            // check captcha code
            //error or search in database
            //error or safhe code taeed
        }
    }
    else
    {
        str += "</ul>" ;
        QMessageBox::information(this,"تکمیل اطلاعات",str,"باشه") ;
    }
    return ;
}

