/****************************************************************************
** Meta object code from reading C++ file 'moviesearchwindow.h'
**
** Created: Thu Jan 22 03:01:19 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "moviesearchwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moviesearchwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MovieSearchWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      40,   18,   18,   18, 0x08,
      59,   18,   18,   18, 0x08,
      84,   18,   18,   18, 0x08,
     104,   18,   18,   18, 0x08,
     127,   18,   18,   18, 0x08,
     152,   18,   18,   18, 0x08,
     174,  168,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MovieSearchWindow[] = {
    "MovieSearchWindow\0\0ReturnMovieClicked()\0"
    "RentMovieClicked()\0DeleteFromQueueClicked()\0"
    "MoveToBackClicked()\0SearchByTitleClicked()\0"
    "SearchByKeyWordClicked()\0LogOutClicked()\0"
    "event\0closeEvent(QCloseEvent*)\0"
};

void MovieSearchWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MovieSearchWindow *_t = static_cast<MovieSearchWindow *>(_o);
        switch (_id) {
        case 0: _t->ReturnMovieClicked(); break;
        case 1: _t->RentMovieClicked(); break;
        case 2: _t->DeleteFromQueueClicked(); break;
        case 3: _t->MoveToBackClicked(); break;
        case 4: _t->SearchByTitleClicked(); break;
        case 5: _t->SearchByKeyWordClicked(); break;
        case 6: _t->LogOutClicked(); break;
        case 7: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MovieSearchWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MovieSearchWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MovieSearchWindow,
      qt_meta_data_MovieSearchWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MovieSearchWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MovieSearchWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MovieSearchWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MovieSearchWindow))
        return static_cast<void*>(const_cast< MovieSearchWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MovieSearchWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
