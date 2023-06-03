#ifndef CHATPAGE_H
#define CHATPAGE_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QHostAddress>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QWidget>
#include "MyLib/Newfolder/User.h"
#include "MyLib/Newfolder/MyLib.h"

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

    QTcpSocket* socket;

    User* user ;

    QListWidgetItem* item ;

    void addContactItem () ;

    void addContact () ;

private slots:

    void readSocket();
    void discardSocket();

    void on_C_SendMessageButton_clicked();
    void on_C_AddContactButton_clicked();
    void on_C_ChatList_itemDoubleClicked(QListWidgetItem *item);
    void on_C_ContactList_itemClicked(QListWidgetItem *item);

    void ChatOn () ;
    void ChatOff () ;

    void ContactNameLabelOn () ;
    void ContactNameLabelOff () ;

    void on_C_SendFileButton_clicked();
};

#endif // CHATPAGE_H
