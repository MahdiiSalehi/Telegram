#ifndef CODETAEED_H
#define CODETAEED_H

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

namespace Ui {
class CodeTaeed;
}

class CodeTaeed : public QMainWindow
{
    Q_OBJECT
    QWidget *w = new QWidget(nullptr,Qt::CoverWindow) ;
    QVBoxLayout *ly = new QVBoxLayout(w) ;
    QLineEdit *le = new QLineEdit() ;
    QLabel *lb = new QLabel () ;

public:
    explicit CodeTaeed(QWidget *parent = nullptr);
    ~CodeTaeed();

private slots:
    void on_C_LineEdit1EnterCode_textChanged(const QString &arg1);

    void on_C_LineEdit2EnterCode_textChanged(const QString &arg1);

    void on_C_LineEdit3EnterCode_textChanged(const QString &arg1);

    void on_C_Button_clicked();

private:
    Ui::CodeTaeed *ui;
};

#endif // CODETAEED_H
