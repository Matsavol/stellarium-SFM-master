/****************************************************************************
** Meta object code from reading C++ file 'GPSMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/modules/GPSMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GPSMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GPSMgr_t {
    QByteArrayData data[16];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GPSMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GPSMgr_t qt_meta_stringdata_GPSMgr = {
    {
QT_MOC_LITERAL(0, 0, 6), // "GPSMgr"
QT_MOC_LITERAL(1, 7, 12), // "stateChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "GPSMgr::State"
QT_MOC_LITERAL(4, 35, 5), // "value"
QT_MOC_LITERAL(5, 41, 14), // "enabledChanged"
QT_MOC_LITERAL(6, 56, 15), // "positionUpdated"
QT_MOC_LITERAL(7, 72, 16), // "QGeoPositionInfo"
QT_MOC_LITERAL(8, 89, 4), // "info"
QT_MOC_LITERAL(9, 94, 7), // "onError"
QT_MOC_LITERAL(10, 102, 29), // "QGeoPositionInfoSource::Error"
QT_MOC_LITERAL(11, 132, 16), // "positioningError"
QT_MOC_LITERAL(12, 149, 10), // "setEnabled"
QT_MOC_LITERAL(13, 160, 7), // "enabled"
QT_MOC_LITERAL(14, 168, 5), // "state"
QT_MOC_LITERAL(15, 174, 5) // "State"

    },
    "GPSMgr\0stateChanged\0\0GPSMgr::State\0"
    "value\0enabledChanged\0positionUpdated\0"
    "QGeoPositionInfo\0info\0onError\0"
    "QGeoPositionInfoSource::Error\0"
    "positioningError\0setEnabled\0enabled\0"
    "state\0State"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GPSMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   45,    2, 0x08 /* Private */,
       9,    1,   48,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      12,    1,   51,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

 // methods: parameters
    QMetaType::Void, QMetaType::Bool,    4,

 // properties: name, type, flags
      13, QMetaType::Bool, 0x00495103,
      14, 0x80000000 | 15, 0x00495009,

 // properties: notify_signal_id
       1,
       0,

       0        // eod
};

void GPSMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GPSMgr *_t = static_cast<GPSMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< GPSMgr::State(*)>(_a[1]))); break;
        case 1: _t->enabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->positionUpdated((*reinterpret_cast< const QGeoPositionInfo(*)>(_a[1]))); break;
        case 3: _t->onError((*reinterpret_cast< QGeoPositionInfoSource::Error(*)>(_a[1]))); break;
        case 4: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GPSMgr::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GPSMgr::*_t)(GPSMgr::State );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GPSMgr::stateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GPSMgr::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GPSMgr::enabledChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        GPSMgr *_t = static_cast<GPSMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isEnabled(); break;
        case 1: *reinterpret_cast< State*>(_v) = _t->getState(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        GPSMgr *_t = static_cast<GPSMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEnabled(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject GPSMgr::staticMetaObject = {
    { &StelModule::staticMetaObject, qt_meta_stringdata_GPSMgr.data,
      qt_meta_data_GPSMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GPSMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GPSMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GPSMgr.stringdata0))
        return static_cast<void*>(const_cast< GPSMgr*>(this));
    return StelModule::qt_metacast(_clname);
}

int GPSMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StelModule::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GPSMgr::stateChanged(GPSMgr::State _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GPSMgr::enabledChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
