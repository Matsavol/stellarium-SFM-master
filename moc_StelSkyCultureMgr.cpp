/****************************************************************************
** Meta object code from reading C++ file 'StelSkyCultureMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelSkyCultureMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelSkyCultureMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelSkyCultureMgr_t {
    QByteArrayData data[14];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelSkyCultureMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelSkyCultureMgr_t qt_meta_stringdata_StelSkyCultureMgr = {
    {
QT_MOC_LITERAL(0, 0, 17), // "StelSkyCultureMgr"
QT_MOC_LITERAL(1, 18, 31), // "getCurrentSkyCultureEnglishName"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 27), // "getCurrentSkyCultureNameI18"
QT_MOC_LITERAL(4, 79, 27), // "setCurrentSkyCultureNameI18"
QT_MOC_LITERAL(5, 107, 11), // "cultureName"
QT_MOC_LITERAL(6, 119, 22), // "getCurrentSkyCultureID"
QT_MOC_LITERAL(7, 142, 22), // "setCurrentSkyCultureID"
QT_MOC_LITERAL(8, 165, 2), // "id"
QT_MOC_LITERAL(9, 168, 22), // "getDefaultSkyCultureID"
QT_MOC_LITERAL(10, 191, 22), // "setDefaultSkyCultureID"
QT_MOC_LITERAL(11, 214, 24), // "getSkyCultureListEnglish"
QT_MOC_LITERAL(12, 239, 20), // "getSkyCultureListI18"
QT_MOC_LITERAL(13, 260, 20) // "getSkyCultureListIDs"

    },
    "StelSkyCultureMgr\0getCurrentSkyCultureEnglishName\0"
    "\0getCurrentSkyCultureNameI18\0"
    "setCurrentSkyCultureNameI18\0cultureName\0"
    "getCurrentSkyCultureID\0setCurrentSkyCultureID\0"
    "id\0getDefaultSkyCultureID\0"
    "setDefaultSkyCultureID\0getSkyCultureListEnglish\0"
    "getSkyCultureListI18\0getSkyCultureListIDs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelSkyCultureMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    1,   66,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x0a /* Public */,
       7,    1,   70,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    1,   74,    2, 0x0a /* Public */,
      11,    0,   77,    2, 0x0a /* Public */,
      12,    0,   78,    2, 0x0a /* Public */,
      13,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::QStringList,
    QMetaType::QStringList,

       0        // eod
};

void StelSkyCultureMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelSkyCultureMgr *_t = static_cast<StelSkyCultureMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->getCurrentSkyCultureEnglishName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->getCurrentSkyCultureNameI18();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->setCurrentSkyCultureNameI18((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->getCurrentSkyCultureID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->setCurrentSkyCultureID((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->getDefaultSkyCultureID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->setDefaultSkyCultureID((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->getSkyCultureListEnglish();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { QStringList _r = _t->getSkyCultureListI18();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 9: { QStringList _r = _t->getSkyCultureListIDs();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject StelSkyCultureMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StelSkyCultureMgr.data,
      qt_meta_data_StelSkyCultureMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelSkyCultureMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelSkyCultureMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelSkyCultureMgr.stringdata0))
        return static_cast<void*>(const_cast< StelSkyCultureMgr*>(this));
    return QObject::qt_metacast(_clname);
}

int StelSkyCultureMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
