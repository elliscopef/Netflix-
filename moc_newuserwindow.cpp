/****************************************************************************
** Meta object code from reading C++ file 'newuserwindow.h'
**
** Created: Thu Jan 22 03:01:20 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newuserwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newuserwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewUserWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      32,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewUserWindow[] = {
    "NewUserWindow\0\0ConfirmClicked()\0"
    "CancelClicked()\0"
};

void NewUserWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewUserWindow *_t = static_cast<NewUserWindow *>(_o);
        switch (_id) {
        case 0: _t->ConfirmClicked(); break;
        case 1: _t->CancelClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NewUserWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewUserWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NewUserWindow,
      qt_meta_data_NewUserWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewUserWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewUserWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewUserWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewUserWindow))
        return static_cast<void*>(const_cast< NewUserWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int NewUserWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
