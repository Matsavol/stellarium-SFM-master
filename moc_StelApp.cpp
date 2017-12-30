/****************************************************************************
** Meta object code from reading C++ file 'StelApp.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelApp.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelApp.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelApp_t {
    QByteArrayData data[17];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelApp_t qt_meta_stringdata_StelApp = {
    {
QT_MOC_LITERAL(0, 0, 7), // "StelApp"
QT_MOC_LITERAL(1, 8, 22), // "visionNightModeChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "colorSchemeChanged"
QT_MOC_LITERAL(4, 51, 15), // "languageChanged"
QT_MOC_LITERAL(5, 67, 17), // "skyCultureChanged"
QT_MOC_LITERAL(6, 85, 16), // "progressBarAdded"
QT_MOC_LITERAL(7, 102, 29), // "const StelProgressController*"
QT_MOC_LITERAL(8, 132, 18), // "progressBarRemoved"
QT_MOC_LITERAL(9, 151, 18), // "setVisionModeNight"
QT_MOC_LITERAL(10, 170, 18), // "getVisionModeNight"
QT_MOC_LITERAL(11, 189, 6), // "getFps"
QT_MOC_LITERAL(12, 196, 15), // "getTotalRunTime"
QT_MOC_LITERAL(13, 212, 26), // "reportFileDownloadFinished"
QT_MOC_LITERAL(14, 239, 14), // "QNetworkReply*"
QT_MOC_LITERAL(15, 254, 5), // "reply"
QT_MOC_LITERAL(16, 260, 9) // "nightMode"

    },
    "StelApp\0visionNightModeChanged\0\0"
    "colorSchemeChanged\0languageChanged\0"
    "skyCultureChanged\0progressBarAdded\0"
    "const StelProgressController*\0"
    "progressBarRemoved\0setVisionModeNight\0"
    "getVisionModeNight\0getFps\0getTotalRunTime\0"
    "reportFileDownloadFinished\0QNetworkReply*\0"
    "reply\0nightMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       1,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    0,   75,    2, 0x06 /* Public */,
       5,    1,   76,    2, 0x06 /* Public */,
       6,    1,   79,    2, 0x06 /* Public */,
       8,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   85,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x0a /* Public */,
      12,    0,   90,    2, 0x0a /* Public */,
      13,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Bool,
    QMetaType::Float,
    QMetaType::Double,
    QMetaType::Void, 0x80000000 | 14,   15,

 // properties: name, type, flags
      16, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,

       0        // eod
};

void StelApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelApp *_t = static_cast<StelApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->visionNightModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->colorSchemeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->languageChanged(); break;
        case 3: _t->skyCultureChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->progressBarAdded((*reinterpret_cast< const StelProgressController*(*)>(_a[1]))); break;
        case 5: _t->progressBarRemoved((*reinterpret_cast< const StelProgressController*(*)>(_a[1]))); break;
        case 6: _t->setVisionModeNight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: { bool _r = _t->getVisionModeNight();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { float _r = _t->getFps();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 9: { double _r = _t->getTotalRunTime();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 10: _t->reportFileDownloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StelApp::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelApp::visionNightModeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (StelApp::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelApp::colorSchemeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (StelApp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelApp::languageChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (StelApp::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelApp::skyCultureChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (StelApp::*_t)(const StelProgressController * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelApp::progressBarAdded)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (StelApp::*_t)(const StelProgressController * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelApp::progressBarRemoved)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StelApp *_t = static_cast<StelApp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getVisionModeNight(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StelApp *_t = static_cast<StelApp *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVisionModeNight(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject StelApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StelApp.data,
      qt_meta_data_StelApp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelApp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelApp.stringdata0))
        return static_cast<void*>(const_cast< StelApp*>(this));
    return QObject::qt_metacast(_clname);
}

int StelApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void StelApp::visionNightModeChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StelApp::colorSchemeChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StelApp::languageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void StelApp::skyCultureChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void StelApp::progressBarAdded(const StelProgressController * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void StelApp::progressBarRemoved(const StelProgressController * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
