/****************************************************************************
** Meta object code from reading C++ file 'enter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Telegram/enter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Enter_t {
    QByteArrayData data[13];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Enter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Enter_t qt_meta_stringdata_Enter = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Enter"
QT_MOC_LITERAL(1, 6, 27), // "on_E_U_LineEdit_textChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "arg1"
QT_MOC_LITERAL(4, 40, 23), // "on_E_GotoButton_clicked"
QT_MOC_LITERAL(5, 64, 27), // "on_E_P_LineEdit_textChanged"
QT_MOC_LITERAL(6, 92, 28), // "on_E_P_VisableButton_clicked"
QT_MOC_LITERAL(7, 121, 30), // "on_E_CaptchaRegenerate_clicked"
QT_MOC_LITERAL(8, 152, 25), // "on_E_EntRegButton_clicked"
QT_MOC_LITERAL(9, 178, 27), // "on_E_PhoneCodeNum_activated"
QT_MOC_LITERAL(10, 206, 5), // "index"
QT_MOC_LITERAL(11, 212, 30), // "on_E_PhoneCodeRegion_activated"
QT_MOC_LITERAL(12, 243, 30) // "on_E_PhoneLineEdit_textChanged"

    },
    "Enter\0on_E_U_LineEdit_textChanged\0\0"
    "arg1\0on_E_GotoButton_clicked\0"
    "on_E_P_LineEdit_textChanged\0"
    "on_E_P_VisableButton_clicked\0"
    "on_E_CaptchaRegenerate_clicked\0"
    "on_E_EntRegButton_clicked\0"
    "on_E_PhoneCodeNum_activated\0index\0"
    "on_E_PhoneCodeRegion_activated\0"
    "on_E_PhoneLineEdit_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Enter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    0,   66,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      11,    1,   72,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void Enter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Enter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_E_U_LineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_E_GotoButton_clicked(); break;
        case 2: _t->on_E_P_LineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_E_P_VisableButton_clicked(); break;
        case 4: _t->on_E_CaptchaRegenerate_clicked(); break;
        case 5: _t->on_E_EntRegButton_clicked(); break;
        case 6: _t->on_E_PhoneCodeNum_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_E_PhoneCodeRegion_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_E_PhoneLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Enter::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Enter.data,
    qt_meta_data_Enter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Enter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Enter.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Enter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
