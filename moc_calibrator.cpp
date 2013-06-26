/****************************************************************************
** Meta object code from reading C++ file 'calibrator.h'
**
** Created: Wed Apr 24 15:58:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Calib/calibrator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibrator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Calibrator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      72,   66,   11,   11, 0x08,
     105,   66,   11,   11, 0x08,
     137,   66,   11,   11, 0x08,
     172,   66,   11,   11, 0x08,
     204,   66,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Calibrator[] = {
    "Calibrator\0\0on_camaraButton_clicked()\0"
    "on_capturarButton_clicked()\0value\0"
    "on_colorSlider_valueChanged(int)\0"
    "on_STopSlider_valueChanged(int)\0"
    "on_SBottomSlider_valueChanged(int)\0"
    "on_VTopSilder_valueChanged(int)\0"
    "on_VBottomSlider_valueChanged(int)\0"
};

void Calibrator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Calibrator *_t = static_cast<Calibrator *>(_o);
        switch (_id) {
        case 0: _t->on_camaraButton_clicked(); break;
        case 1: _t->on_capturarButton_clicked(); break;
        case 2: _t->on_colorSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_STopSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_SBottomSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_VTopSilder_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_VBottomSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Calibrator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Calibrator::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Calibrator,
      qt_meta_data_Calibrator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Calibrator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Calibrator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Calibrator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Calibrator))
        return static_cast<void*>(const_cast< Calibrator*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Calibrator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
