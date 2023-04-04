#include "start.h"
#include "ui_start.h"
#include <enter.h>

Start::Start(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);
    this->setWindowTitle("پیشواز") ;
}

Start::~Start()
{
    delete ui;
}


void Start::on_S_Buttom_clicked()
{
    Enter *E = new Enter ;
    E->show() ;
    this->~Start() ;
    return ;
}

