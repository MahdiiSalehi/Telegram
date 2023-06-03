/****************************************************************************
** Meta object code from reading C++ file 'chatpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Telegram/chatpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatPage_t {
    QByteArrayData data[15];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatPage_t qt_meta_stringdata_ChatPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ChatPage"
QT_MOC_LITERAL(1, 9, 10), // "readSocket"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "discardSocket"
QT_MOC_LITERAL(4, 35, 30), // "on_C_SendMessageButton_clicked"
QT_MOC_LITERAL(5, 66, 29), // "on_C_AddContactButton_clicked"
QT_MOC_LITERAL(6, 96, 31), // "on_C_ChatList_itemDoubleClicked"
QT_MOC_LITERAL(7, 128, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 145, 4), // "item"
QT_MOC_LITERAL(9, 150, 28), // "on_C_ContactList_itemClicked"
QT_MOC_LITERAL(10, 179, 6), // "ChatOn"
QT_MOC_LITERAL(11, 186, 7), // "ChatOff"
QT_MOC_LITERAL(12, 194, 18), // "ContactNameLabelOn"
QT_MOC_LITERAL(13, 213, 19), // "ContactNameLabelOff"
QT_MOC_LITERAL(14, 233, 27) // "on_C_SendFileButton_clicked"

    },
    "ChatPage\0readSocket\0\0discardSocket\0"
    "on_C_SendMessageButton_clicked\0"
    "on_C_AddContactButton_clicked\0"
    "on_C_ChatList_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "on_C_ContactList_itemClicked\0ChatOn\0"
    "ChatOff\0ContactNameLabelOn\0"
    "ContactNameLabelOff\0on_C_SendFileButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    1,   73,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChatPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readSocket(); break;
        case 1: _t->discardSocket(); break;
        case 2: _t->on_C_SendMessageButton_clicked(); break;
        case 3: _t->on_C_AddContactButton_clicked(); break;
        case 4: _t->on_C_ChatList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_C_ContactList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->ChatOn(); break;
        case 7: _t->ChatOff(); break;
        case 8: _t->ContactNameLabelOn(); break;
        case 9: _t->ContactNameLabelOff(); break;
        case 10: _t->on_C_SendFileButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatPage::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_ChatPage.data,
    qt_meta_data_ChatPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatPage.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ChatPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
