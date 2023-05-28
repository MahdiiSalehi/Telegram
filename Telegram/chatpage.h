#ifndef CHATPAGE_H
#define CHATPAGE_H

#include <QMainWindow>

namespace Ui {
class ChatPage;
}

class ChatPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatPage(QWidget *parent = nullptr);
    ~ChatPage();

private:
    Ui::ChatPage *ui;
};

#endif // CHATPAGE_H
