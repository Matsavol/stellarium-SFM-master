/****************************************************************************
** Meta object code from reading C++ file 'StelAudioMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelAudioMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelAudioMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelAudioMgr_t {
    QByteArrayData data[9];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelAudioMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelAudioMgr_t qt_meta_stringdata_StelAudioMgr = {
    {
QT_MOC_LITERAL(0, 0, 12), // "StelAudioMgr"
QT_MOC_LITERAL(1, 13, 9), // "loadSound"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "filename"
QT_MOC_LITERAL(4, 33, 2), // "id"
QT_MOC_LITERAL(5, 36, 9), // "playSound"
QT_MOC_LITERAL(6, 46, 10), // "pauseSound"
QT_MOC_LITERAL(7, 57, 9), // "stopSound"
QT_MOC_LITERAL(8, 67, 9) // "dropSound"

    },
    "StelAudioMgr\0loadSound\0\0filename\0id\0"
    "playSound\0pauseSound\0stopSound\0dropSound"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelAudioMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a /* Public */,
       5,    1,   44,    2, 0x0a /* Public */,
       6,    1,   47,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       8,    1,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void StelAudioMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelAudioMgr *_t = static_cast<StelAudioMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadSound((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->playSound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->pauseSound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->stopSound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->dropSound((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject StelAudioMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StelAudioMgr.data,
      qt_meta_data_StelAudioMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelAudioMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelAudioMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelAudioMgr.stringdata0))
        return static_cast<void*>(const_cast< StelAudioMgr*>(this));
    return QObject::qt_metacast(_clname);
}

int StelAudioMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
