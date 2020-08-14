/****************************************************************************
** Meta object code from reading C++ file 'comminterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ACTUALGUI/comminterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comminterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommInterface_t {
    QByteArrayData data[17];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommInterface_t qt_meta_stringdata_CommInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CommInterface"
QT_MOC_LITERAL(1, 14, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(4, 63, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(5, 87, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(6, 111, 24), // "on_pushButton_10_clicked"
QT_MOC_LITERAL(7, 136, 24), // "on_pushButton_11_clicked"
QT_MOC_LITERAL(8, 161, 24), // "on_pushButton_12_clicked"
QT_MOC_LITERAL(9, 186, 9), // "showPopUp"
QT_MOC_LITERAL(10, 196, 12), // "save_pop_up*"
QT_MOC_LITERAL(11, 209, 5), // "popup"
QT_MOC_LITERAL(12, 215, 9), // "tree_load"
QT_MOC_LITERAL(13, 225, 10), // "tree_destr"
QT_MOC_LITERAL(14, 236, 10), // "enterEvent"
QT_MOC_LITERAL(15, 247, 7), // "QEvent*"
QT_MOC_LITERAL(16, 255, 5) // "event"

    },
    "CommInterface\0on_pushButton_7_clicked\0"
    "\0on_pushButton_8_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_9_clicked\0"
    "on_pushButton_10_clicked\0"
    "on_pushButton_11_clicked\0"
    "on_pushButton_12_clicked\0showPopUp\0"
    "save_pop_up*\0popup\0tree_load\0tree_destr\0"
    "enterEvent\0QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommInterface[] = {

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
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void CommInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_7_clicked(); break;
        case 1: _t->on_pushButton_8_clicked(); break;
        case 2: _t->on_pushButton_5_clicked(); break;
        case 3: _t->on_pushButton_9_clicked(); break;
        case 4: _t->on_pushButton_10_clicked(); break;
        case 5: _t->on_pushButton_11_clicked(); break;
        case 6: _t->on_pushButton_12_clicked(); break;
        case 7: _t->showPopUp((*reinterpret_cast< save_pop_up*(*)>(_a[1]))); break;
        case 8: _t->tree_load(); break;
        case 9: _t->tree_destr(); break;
        case 10: _t->enterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< save_pop_up* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CommInterface.data,
    qt_meta_data_CommInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommInterface.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CommInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
