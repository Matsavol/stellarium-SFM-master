/****************************************************************************
** Meta object code from reading C++ file 'MilkyWay.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/modules/MilkyWay.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MilkyWay.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MilkyWay_t {
    QByteArrayData data[12];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MilkyWay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MilkyWay_t qt_meta_stringdata_MilkyWay = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MilkyWay"
QT_MOC_LITERAL(1, 9, 12), // "getIntensity"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "setIntensity"
QT_MOC_LITERAL(4, 36, 10), // "aintensity"
QT_MOC_LITERAL(5, 47, 8), // "getColor"
QT_MOC_LITERAL(6, 56, 5), // "Vec3f"
QT_MOC_LITERAL(7, 62, 8), // "setColor"
QT_MOC_LITERAL(8, 71, 1), // "c"
QT_MOC_LITERAL(9, 73, 11), // "setFlagShow"
QT_MOC_LITERAL(10, 85, 1), // "b"
QT_MOC_LITERAL(11, 87, 11) // "getFlagShow"

    },
    "MilkyWay\0getIntensity\0\0setIntensity\0"
    "aintensity\0getColor\0Vec3f\0setColor\0c\0"
    "setFlagShow\0b\0getFlagShow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MilkyWay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,
       9,    1,   52,    2, 0x0a /* Public */,
      11,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double,    4,
    0x80000000 | 6,
    QMetaType::Void, 0x80000000 | 6,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Bool,

       0        // eod
};

void MilkyWay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MilkyWay *_t = static_cast<MilkyWay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { double _r = _t->getIntensity();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 1: _t->setIntensity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: { Vec3f _r = _t->getColor();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 3: _t->setColor((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 4: _t->setFlagShow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: { bool _r = _t->getFlagShow();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject MilkyWay::staticMetaObject = {
    { &StelModule::staticMetaObject, qt_meta_stringdata_MilkyWay.data,
      qt_meta_data_MilkyWay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MilkyWay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MilkyWay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MilkyWay.stringdata0))
        return static_cast<void*>(const_cast< MilkyWay*>(this));
    return StelModule::qt_metacast(_clname);
}

int MilkyWay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StelModule::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
