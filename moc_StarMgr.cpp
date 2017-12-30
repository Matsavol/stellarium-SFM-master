/****************************************************************************
** Meta object code from reading C++ file 'StarMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/modules/StarMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StarMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StarMgr_t {
    QByteArrayData data[26];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StarMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StarMgr_t qt_meta_stringdata_StarMgr = {
    {
QT_MOC_LITERAL(0, 0, 7), // "StarMgr"
QT_MOC_LITERAL(1, 8, 13), // "setLabelColor"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "Vec3f"
QT_MOC_LITERAL(4, 29, 1), // "c"
QT_MOC_LITERAL(5, 31, 13), // "getLabelColor"
QT_MOC_LITERAL(6, 45, 12), // "setFlagStars"
QT_MOC_LITERAL(7, 58, 1), // "b"
QT_MOC_LITERAL(8, 60, 12), // "getFlagStars"
QT_MOC_LITERAL(9, 73, 13), // "setFlagLabels"
QT_MOC_LITERAL(10, 87, 13), // "getFlagLabels"
QT_MOC_LITERAL(11, 101, 15), // "setLabelsAmount"
QT_MOC_LITERAL(12, 117, 1), // "a"
QT_MOC_LITERAL(13, 119, 15), // "getLabelsAmount"
QT_MOC_LITERAL(14, 135, 11), // "setFontSize"
QT_MOC_LITERAL(15, 147, 11), // "newFontSize"
QT_MOC_LITERAL(16, 159, 15), // "setFlagSciNames"
QT_MOC_LITERAL(17, 175, 1), // "f"
QT_MOC_LITERAL(18, 177, 15), // "getFlagSciNames"
QT_MOC_LITERAL(19, 193, 12), // "setStelStyle"
QT_MOC_LITERAL(20, 206, 7), // "section"
QT_MOC_LITERAL(21, 214, 10), // "updateI18n"
QT_MOC_LITERAL(22, 225, 16), // "updateSkyCulture"
QT_MOC_LITERAL(23, 242, 13), // "skyCultureDir"
QT_MOC_LITERAL(24, 256, 18), // "flagStarsDisplayed"
QT_MOC_LITERAL(25, 275, 19) // "flagLabelsDisplayed"

    },
    "StarMgr\0setLabelColor\0\0Vec3f\0c\0"
    "getLabelColor\0setFlagStars\0b\0getFlagStars\0"
    "setFlagLabels\0getFlagLabels\0setLabelsAmount\0"
    "a\0getLabelsAmount\0setFontSize\0newFontSize\0"
    "setFlagSciNames\0f\0getFlagSciNames\0"
    "setStelStyle\0section\0updateI18n\0"
    "updateSkyCulture\0skyCultureDir\0"
    "flagStarsDisplayed\0flagLabelsDisplayed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StarMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,  114, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    1,   88,    2, 0x0a /* Public */,
       8,    0,   91,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x0a /* Public */,
      10,    0,   95,    2, 0x0a /* Public */,
      11,    1,   96,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    1,  100,    2, 0x0a /* Public */,
      16,    1,  103,    2, 0x0a /* Public */,
      18,    0,  106,    2, 0x0a /* Public */,
      19,    1,  107,    2, 0x08 /* Private */,
      21,    0,  110,    2, 0x08 /* Private */,
      22,    1,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    0x80000000 | 3,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Float,   12,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Float,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,

 // properties: name, type, flags
      24, QMetaType::Bool, 0x00095003,
      25, QMetaType::Bool, 0x00095003,

       0        // eod
};

void StarMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StarMgr *_t = static_cast<StarMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setLabelColor((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 1: { Vec3f _r = _t->getLabelColor();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 2: _t->setFlagStars((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: { bool _r = _t->getFlagStars();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->setFlagLabels((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: { bool _r = _t->getFlagLabels();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->setLabelsAmount((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: { float _r = _t->getLabelsAmount();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 8: _t->setFontSize((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->setFlagSciNames((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: { bool _r = _t->getFlagSciNames();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->setStelStyle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->updateI18n(); break;
        case 13: _t->updateSkyCulture((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StarMgr *_t = static_cast<StarMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getFlagStars(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getFlagLabels(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StarMgr *_t = static_cast<StarMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFlagStars(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setFlagLabels(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject StarMgr::staticMetaObject = {
    { &StelObjectModule::staticMetaObject, qt_meta_stringdata_StarMgr.data,
      qt_meta_data_StarMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StarMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StarMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StarMgr.stringdata0))
        return static_cast<void*>(const_cast< StarMgr*>(this));
    return StelObjectModule::qt_metacast(_clname);
}

int StarMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StelObjectModule::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
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
QT_END_MOC_NAMESPACE
