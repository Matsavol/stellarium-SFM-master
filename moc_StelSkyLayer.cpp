/****************************************************************************
** Meta object code from reading C++ file 'StelSkyLayer.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelSkyLayer.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelSkyLayer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelSkyLayer_t {
    QByteArrayData data[6];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelSkyLayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelSkyLayer_t qt_meta_stringdata_StelSkyLayer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "StelSkyLayer"
QT_MOC_LITERAL(1, 13, 19), // "loadingStateChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 1), // "b"
QT_MOC_LITERAL(4, 36, 20), // "percentLoadedChanged"
QT_MOC_LITERAL(5, 57, 10) // "percentage"

    },
    "StelSkyLayer\0loadingStateChanged\0\0b\0"
    "percentLoadedChanged\0percentage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelSkyLayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void StelSkyLayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelSkyLayer *_t = static_cast<StelSkyLayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadingStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->percentLoadedChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StelSkyLayer::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelSkyLayer::loadingStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (StelSkyLayer::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelSkyLayer::percentLoadedChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject StelSkyLayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StelSkyLayer.data,
      qt_meta_data_StelSkyLayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelSkyLayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelSkyLayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelSkyLayer.stringdata0))
        return static_cast<void*>(const_cast< StelSkyLayer*>(this));
    return QObject::qt_metacast(_clname);
}

int StelSkyLayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void StelSkyLayer::loadingStateChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StelSkyLayer::percentLoadedChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
