/****************************************************************************
** Meta object code from reading C++ file 'StelSkyLayerMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelSkyLayerMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelSkyLayerMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelSkyLayerMgr_t {
    QByteArrayData data[39];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelSkyLayerMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelSkyLayerMgr_t qt_meta_stringdata_StelSkyLayerMgr = {
    {
QT_MOC_LITERAL(0, 0, 15), // "StelSkyLayerMgr"
QT_MOC_LITERAL(1, 16, 11), // "setFlagShow"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "b"
QT_MOC_LITERAL(4, 31, 12), // "loadSkyImage"
QT_MOC_LITERAL(5, 44, 2), // "id"
QT_MOC_LITERAL(6, 47, 8), // "filename"
QT_MOC_LITERAL(7, 56, 3), // "ra0"
QT_MOC_LITERAL(8, 60, 4), // "dec0"
QT_MOC_LITERAL(9, 65, 3), // "ra1"
QT_MOC_LITERAL(10, 69, 4), // "dec1"
QT_MOC_LITERAL(11, 74, 3), // "ra2"
QT_MOC_LITERAL(12, 78, 4), // "dec2"
QT_MOC_LITERAL(13, 83, 3), // "ra3"
QT_MOC_LITERAL(14, 87, 4), // "dec3"
QT_MOC_LITERAL(15, 92, 6), // "minRes"
QT_MOC_LITERAL(16, 99, 9), // "maxBright"
QT_MOC_LITERAL(17, 109, 7), // "visible"
QT_MOC_LITERAL(18, 117, 17), // "loadSkyImageAltAz"
QT_MOC_LITERAL(19, 135, 4), // "alt0"
QT_MOC_LITERAL(20, 140, 4), // "azi0"
QT_MOC_LITERAL(21, 145, 4), // "alt1"
QT_MOC_LITERAL(22, 150, 4), // "azi1"
QT_MOC_LITERAL(23, 155, 4), // "alt2"
QT_MOC_LITERAL(24, 160, 4), // "azi2"
QT_MOC_LITERAL(25, 165, 4), // "alt3"
QT_MOC_LITERAL(26, 170, 4), // "azi3"
QT_MOC_LITERAL(27, 175, 9), // "showLayer"
QT_MOC_LITERAL(28, 185, 12), // "getShowLayer"
QT_MOC_LITERAL(29, 198, 14), // "insertSkyImage"
QT_MOC_LITERAL(30, 213, 3), // "uri"
QT_MOC_LITERAL(31, 217, 7), // "keyHint"
QT_MOC_LITERAL(32, 225, 4), // "show"
QT_MOC_LITERAL(33, 230, 14), // "removeSkyLayer"
QT_MOC_LITERAL(34, 245, 3), // "key"
QT_MOC_LITERAL(35, 249, 10), // "getAllKeys"
QT_MOC_LITERAL(36, 260, 19), // "loadingStateChanged"
QT_MOC_LITERAL(37, 280, 20), // "percentLoadedChanged"
QT_MOC_LITERAL(38, 301, 10) // "percentage"

    },
    "StelSkyLayerMgr\0setFlagShow\0\0b\0"
    "loadSkyImage\0id\0filename\0ra0\0dec0\0ra1\0"
    "dec1\0ra2\0dec2\0ra3\0dec3\0minRes\0maxBright\0"
    "visible\0loadSkyImageAltAz\0alt0\0azi0\0"
    "alt1\0azi1\0alt2\0azi2\0alt3\0azi3\0showLayer\0"
    "getShowLayer\0insertSkyImage\0uri\0keyHint\0"
    "show\0removeSkyLayer\0key\0getAllKeys\0"
    "loadingStateChanged\0percentLoadedChanged\0"
    "percentage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelSkyLayerMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       1,  164, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,   13,   77,    2, 0x0a /* Public */,
      18,   13,  104,    2, 0x0a /* Public */,
      27,    2,  131,    2, 0x0a /* Public */,
      28,    1,  136,    2, 0x0a /* Public */,
      29,    3,  139,    2, 0x0a /* Public */,
      29,    2,  146,    2, 0x2a /* Public | MethodCloned */,
      29,    1,  151,    2, 0x2a /* Public | MethodCloned */,
      33,    1,  154,    2, 0x0a /* Public */,
      35,    0,  157,    2, 0x0a /* Public */,
      36,    1,  158,    2, 0x08 /* Private */,
      37,    1,  161,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    5,    6,   19,   20,   21,   22,   23,   24,   25,   26,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    5,    3,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   30,   31,   32,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   30,   31,
    QMetaType::QString, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   38,

 // properties: name, type, flags
      17, QMetaType::Bool, 0x00095003,

       0        // eod
};

void StelSkyLayerMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelSkyLayerMgr *_t = static_cast<StelSkyLayerMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFlagShow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: { bool _r = _t->loadSkyImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11])),(*reinterpret_cast< double(*)>(_a[12])),(*reinterpret_cast< bool(*)>(_a[13])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->loadSkyImageAltAz((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11])),(*reinterpret_cast< double(*)>(_a[12])),(*reinterpret_cast< bool(*)>(_a[13])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->showLayer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: { bool _r = _t->getShowLayer((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->insertSkyImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->insertSkyImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->insertSkyImage((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: _t->removeSkyLayer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: { QStringList _r = _t->getAllKeys();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 10: _t->loadingStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->percentLoadedChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StelSkyLayerMgr *_t = static_cast<StelSkyLayerMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getFlagShow(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StelSkyLayerMgr *_t = static_cast<StelSkyLayerMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFlagShow(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject StelSkyLayerMgr::staticMetaObject = {
    { &StelModule::staticMetaObject, qt_meta_stringdata_StelSkyLayerMgr.data,
      qt_meta_data_StelSkyLayerMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelSkyLayerMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelSkyLayerMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelSkyLayerMgr.stringdata0))
        return static_cast<void*>(const_cast< StelSkyLayerMgr*>(this));
    return StelModule::qt_metacast(_clname);
}

int StelSkyLayerMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StelModule::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
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
QT_END_MOC_NAMESPACE
