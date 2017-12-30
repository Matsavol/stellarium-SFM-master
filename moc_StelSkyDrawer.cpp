/****************************************************************************
** Meta object code from reading C++ file 'StelSkyDrawer.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelSkyDrawer.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelSkyDrawer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelSkyDrawer_t {
    QByteArrayData data[43];
    char stringdata0[807];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelSkyDrawer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelSkyDrawer_t qt_meta_stringdata_StelSkyDrawer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "StelSkyDrawer"
QT_MOC_LITERAL(1, 14, 20), // "setRelativeStarScale"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 1), // "b"
QT_MOC_LITERAL(4, 38, 20), // "getRelativeStarScale"
QT_MOC_LITERAL(5, 59, 20), // "setAbsoluteStarScale"
QT_MOC_LITERAL(6, 80, 20), // "getAbsoluteStarScale"
QT_MOC_LITERAL(7, 101, 16), // "setTwinkleAmount"
QT_MOC_LITERAL(8, 118, 16), // "getTwinkleAmount"
QT_MOC_LITERAL(9, 135, 14), // "setFlagTwinkle"
QT_MOC_LITERAL(10, 150, 14), // "getFlagTwinkle"
QT_MOC_LITERAL(11, 165, 14), // "setBortleScale"
QT_MOC_LITERAL(12, 180, 5), // "index"
QT_MOC_LITERAL(13, 186, 14), // "getBortleScale"
QT_MOC_LITERAL(14, 201, 17), // "getLimitMagnitude"
QT_MOC_LITERAL(15, 219, 25), // "setFlagStarMagnitudeLimit"
QT_MOC_LITERAL(16, 245, 27), // "setFlagNebulaMagnitudeLimit"
QT_MOC_LITERAL(17, 273, 25), // "getFlagStarMagnitudeLimit"
QT_MOC_LITERAL(18, 299, 27), // "getFlagNebulaMagnitudeLimit"
QT_MOC_LITERAL(19, 327, 27), // "getCustomStarMagnitudeLimit"
QT_MOC_LITERAL(20, 355, 27), // "setCustomStarMagnitudeLimit"
QT_MOC_LITERAL(21, 383, 5), // "limit"
QT_MOC_LITERAL(22, 389, 29), // "getCustomNebulaMagnitudeLimit"
QT_MOC_LITERAL(23, 419, 29), // "setCustomNebulaMagnitudeLimit"
QT_MOC_LITERAL(24, 449, 17), // "getLimitLuminance"
QT_MOC_LITERAL(25, 467, 26), // "setFlagLuminanceAdaptation"
QT_MOC_LITERAL(26, 494, 26), // "getFlagLuminanceAdaptation"
QT_MOC_LITERAL(27, 521, 20), // "setFlagHasAtmosphere"
QT_MOC_LITERAL(28, 542, 20), // "getFlagHasAtmosphere"
QT_MOC_LITERAL(29, 563, 24), // "setExtinctionCoefficient"
QT_MOC_LITERAL(30, 588, 8), // "extCoeff"
QT_MOC_LITERAL(31, 597, 24), // "getExtinctionCoefficient"
QT_MOC_LITERAL(32, 622, 24), // "setAtmosphereTemperature"
QT_MOC_LITERAL(33, 647, 7), // "celsius"
QT_MOC_LITERAL(34, 655, 24), // "getAtmosphereTemperature"
QT_MOC_LITERAL(35, 680, 21), // "setAtmospherePressure"
QT_MOC_LITERAL(36, 702, 4), // "mbar"
QT_MOC_LITERAL(37, 707, 21), // "getAtmospherePressure"
QT_MOC_LITERAL(38, 729, 13), // "getExtinction"
QT_MOC_LITERAL(39, 743, 13), // "getRefraction"
QT_MOC_LITERAL(40, 757, 23), // "getBig3dModelHaloRadius"
QT_MOC_LITERAL(41, 781, 23), // "setBig3dModelHaloRadius"
QT_MOC_LITERAL(42, 805, 1) // "r"

    },
    "StelSkyDrawer\0setRelativeStarScale\0\0"
    "b\0getRelativeStarScale\0setAbsoluteStarScale\0"
    "getAbsoluteStarScale\0setTwinkleAmount\0"
    "getTwinkleAmount\0setFlagTwinkle\0"
    "getFlagTwinkle\0setBortleScale\0index\0"
    "getBortleScale\0getLimitMagnitude\0"
    "setFlagStarMagnitudeLimit\0"
    "setFlagNebulaMagnitudeLimit\0"
    "getFlagStarMagnitudeLimit\0"
    "getFlagNebulaMagnitudeLimit\0"
    "getCustomStarMagnitudeLimit\0"
    "setCustomStarMagnitudeLimit\0limit\0"
    "getCustomNebulaMagnitudeLimit\0"
    "setCustomNebulaMagnitudeLimit\0"
    "getLimitLuminance\0setFlagLuminanceAdaptation\0"
    "getFlagLuminanceAdaptation\0"
    "setFlagHasAtmosphere\0getFlagHasAtmosphere\0"
    "setExtinctionCoefficient\0extCoeff\0"
    "getExtinctionCoefficient\0"
    "setAtmosphereTemperature\0celsius\0"
    "getAtmosphereTemperature\0setAtmospherePressure\0"
    "mbar\0getAtmospherePressure\0getExtinction\0"
    "getRefraction\0getBig3dModelHaloRadius\0"
    "setBig3dModelHaloRadius\0r"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelSkyDrawer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  194,    2, 0x0a /* Public */,
       1,    0,  197,    2, 0x2a /* Public | MethodCloned */,
       4,    0,  198,    2, 0x0a /* Public */,
       5,    1,  199,    2, 0x0a /* Public */,
       5,    0,  202,    2, 0x2a /* Public | MethodCloned */,
       6,    0,  203,    2, 0x0a /* Public */,
       7,    1,  204,    2, 0x0a /* Public */,
       8,    0,  207,    2, 0x0a /* Public */,
       9,    1,  208,    2, 0x0a /* Public */,
      10,    0,  211,    2, 0x0a /* Public */,
      11,    1,  212,    2, 0x0a /* Public */,
      13,    0,  215,    2, 0x0a /* Public */,
      14,    0,  216,    2, 0x0a /* Public */,
      15,    1,  217,    2, 0x0a /* Public */,
      16,    1,  220,    2, 0x0a /* Public */,
      17,    0,  223,    2, 0x0a /* Public */,
      18,    0,  224,    2, 0x0a /* Public */,
      19,    0,  225,    2, 0x0a /* Public */,
      20,    1,  226,    2, 0x0a /* Public */,
      22,    0,  229,    2, 0x0a /* Public */,
      23,    1,  230,    2, 0x0a /* Public */,
      24,    0,  233,    2, 0x0a /* Public */,
      25,    1,  234,    2, 0x0a /* Public */,
      26,    0,  237,    2, 0x0a /* Public */,
      27,    1,  238,    2, 0x0a /* Public */,
      28,    0,  241,    2, 0x0a /* Public */,
      29,    1,  242,    2, 0x0a /* Public */,
      31,    0,  245,    2, 0x0a /* Public */,
      32,    1,  246,    2, 0x0a /* Public */,
      34,    0,  249,    2, 0x0a /* Public */,
      35,    1,  250,    2, 0x0a /* Public */,
      37,    0,  253,    2, 0x0a /* Public */,
      38,    0,  254,    2, 0x0a /* Public */,
      39,    0,  255,    2, 0x0a /* Public */,
      40,    0,  256,    2, 0x0a /* Public */,
      41,    1,  257,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Int,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double,   33,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double,   36,
    QMetaType::Double,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Float,   42,

       0        // eod
};

void StelSkyDrawer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelSkyDrawer *_t = static_cast<StelSkyDrawer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRelativeStarScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->setRelativeStarScale(); break;
        case 2: { float _r = _t->getRelativeStarScale();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 3: _t->setAbsoluteStarScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setAbsoluteStarScale(); break;
        case 5: { float _r = _t->getAbsoluteStarScale();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 6: _t->setTwinkleAmount((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: { float _r = _t->getTwinkleAmount();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 8: _t->setFlagTwinkle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: { bool _r = _t->getFlagTwinkle();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: _t->setBortleScale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: { int _r = _t->getBortleScale();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { float _r = _t->getLimitMagnitude();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 13: _t->setFlagStarMagnitudeLimit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setFlagNebulaMagnitudeLimit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: { bool _r = _t->getFlagStarMagnitudeLimit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->getFlagNebulaMagnitudeLimit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { float _r = _t->getCustomStarMagnitudeLimit();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 18: _t->setCustomStarMagnitudeLimit((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: { float _r = _t->getCustomNebulaMagnitudeLimit();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 20: _t->setCustomNebulaMagnitudeLimit((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: { float _r = _t->getLimitLuminance();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 22: _t->setFlagLuminanceAdaptation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: { bool _r = _t->getFlagLuminanceAdaptation();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: _t->setFlagHasAtmosphere((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: { bool _r = _t->getFlagHasAtmosphere();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 26: _t->setExtinctionCoefficient((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: { double _r = _t->getExtinctionCoefficient();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 28: _t->setAtmosphereTemperature((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: { double _r = _t->getAtmosphereTemperature();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 30: _t->setAtmospherePressure((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: { double _r = _t->getAtmospherePressure();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 32: _t->getExtinction(); break;
        case 33: _t->getRefraction(); break;
        case 34: { float _r = _t->getBig3dModelHaloRadius();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 35: _t->setBig3dModelHaloRadius((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject StelSkyDrawer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StelSkyDrawer.data,
      qt_meta_data_StelSkyDrawer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelSkyDrawer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelSkyDrawer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelSkyDrawer.stringdata0))
        return static_cast<void*>(const_cast< StelSkyDrawer*>(this));
    return QObject::qt_metacast(_clname);
}

int StelSkyDrawer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
