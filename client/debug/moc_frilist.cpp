/****************************************************************************
** Meta object code from reading C++ file 'frilist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../frilist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frilist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Frilist_t {
    QByteArrayData data[7];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Frilist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Frilist_t qt_meta_stringdata_Frilist = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Frilist"
QT_MOC_LITERAL(1, 8, 4), // "back"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 20), // "on_friButton_clicked"
QT_MOC_LITERAL(4, 35, 22), // "on_groupButton_clilked"
QT_MOC_LITERAL(5, 58, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(6, 82, 21) // "on_backButton_clicked"

    },
    "Frilist\0back\0\0on_friButton_clicked\0"
    "on_groupButton_clilked\0on_cancelButton_clicked\0"
    "on_backButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Frilist[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Frilist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Frilist *_t = static_cast<Frilist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->on_friButton_clicked(); break;
        case 2: _t->on_groupButton_clilked(); break;
        case 3: _t->on_cancelButton_clicked(); break;
        case 4: _t->on_backButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Frilist::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Frilist::back)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Frilist::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Frilist.data,
      qt_meta_data_Frilist,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Frilist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Frilist::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Frilist.stringdata0))
        return static_cast<void*>(const_cast< Frilist*>(this));
    return QWidget::qt_metacast(_clname);
}

int Frilist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Frilist::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
