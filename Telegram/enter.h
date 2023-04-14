#ifndef ENTER_H
#define ENTER_H

#include <QMainWindow>

namespace Ui {
class Enter;
}

class Enter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Enter(QWidget *parent = nullptr);
    ~Enter();

protected:
    bool CheckRuleSpeciaLetters ( QString ) ;
    // Check use some characters like(*&^%#$) ;

    void GotoEntering () ;

    void GotoRegistering () ;

    void GenerateCaptchaCode () ;

private slots:
    void on_E_U_LineEdit_textChanged(const QString &arg1);

    void on_E_GotoButton_clicked();

    void on_E_P_LineEdit_textChanged(const QString &arg1);

    void on_E_P_VisableButton_clicked();

    void on_E_CaptchaRegenerate_clicked();

    void on_E_EntRegButton_clicked();

    void on_E_PhoneCodeNum_activated(int index);

    void on_E_PhoneCodeRegion_activated(int index);

    void on_E_PhoneLineEdit_textChanged(const QString &arg1);

private:
    Ui::Enter *ui;
};

#endif // ENTER_H
