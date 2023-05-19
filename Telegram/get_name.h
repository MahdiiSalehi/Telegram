#ifndef GET_NAME_H
#define GET_NAME_H

#include <QMainWindow>

namespace Ui {
class Get_Name;
}

class Get_Name : public QMainWindow
{
    Q_OBJECT

public:
    explicit Get_Name(QWidget *parent = nullptr);
    ~Get_Name();

private slots:
    void on_GN_button_clicked();

private:
    Ui::Get_Name *ui;
};

#endif // GET_NAME_H
