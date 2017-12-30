/****************************************************************************
** Meta object code from reading C++ file 'GridLinesMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/modules/GridLinesMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GridLinesMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GridLinesMgr_t {
    QByteArrayData data[87];
    char stringdata0[1910];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GridLinesMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GridLinesMgr_t qt_meta_stringdata_GridLinesMgr = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GridLinesMgr"
QT_MOC_LITERAL(1, 13, 29), // "azimuthalGridDisplayedChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 25), // "azimuthalGridColorChanged"
QT_MOC_LITERAL(4, 70, 5), // "Vec3f"
QT_MOC_LITERAL(5, 76, 8), // "newColor"
QT_MOC_LITERAL(6, 85, 27), // "equatorGridDisplayedChanged"
QT_MOC_LITERAL(7, 113, 9), // "displayed"
QT_MOC_LITERAL(8, 123, 23), // "equatorGridColorChanged"
QT_MOC_LITERAL(9, 147, 32), // "equatorJ2000GridDisplayedChanged"
QT_MOC_LITERAL(10, 180, 28), // "equatorJ2000GridColorChanged"
QT_MOC_LITERAL(11, 209, 33), // "eclipticJ2000GridDisplayedCha..."
QT_MOC_LITERAL(12, 243, 29), // "eclipticJ2000GridColorChanged"
QT_MOC_LITERAL(13, 273, 28), // "galacticGridDisplayedChanged"
QT_MOC_LITERAL(14, 302, 24), // "galacticGridColorChanged"
QT_MOC_LITERAL(15, 327, 27), // "equatorLineDisplayedChanged"
QT_MOC_LITERAL(16, 355, 23), // "equatorLineColorChanged"
QT_MOC_LITERAL(17, 379, 28), // "eclipticLineDisplayedChanged"
QT_MOC_LITERAL(18, 408, 24), // "eclipticLineColorChanged"
QT_MOC_LITERAL(19, 433, 28), // "meridianLineDisplayedChanged"
QT_MOC_LITERAL(20, 462, 24), // "meridianLineColorChanged"
QT_MOC_LITERAL(21, 487, 27), // "horizonLineDisplayedChanged"
QT_MOC_LITERAL(22, 515, 23), // "horizonLineColorChanged"
QT_MOC_LITERAL(23, 539, 33), // "galacticPlaneLineDisplayedCha..."
QT_MOC_LITERAL(24, 573, 29), // "galacticPlaneLineColorChanged"
QT_MOC_LITERAL(25, 603, 20), // "setFlagAzimuthalGrid"
QT_MOC_LITERAL(26, 624, 20), // "getFlagAzimuthalGrid"
QT_MOC_LITERAL(27, 645, 21), // "getColorAzimuthalGrid"
QT_MOC_LITERAL(28, 667, 21), // "setColorAzimuthalGrid"
QT_MOC_LITERAL(29, 689, 18), // "setFlagEquatorGrid"
QT_MOC_LITERAL(30, 708, 18), // "getFlagEquatorGrid"
QT_MOC_LITERAL(31, 727, 19), // "getColorEquatorGrid"
QT_MOC_LITERAL(32, 747, 19), // "setColorEquatorGrid"
QT_MOC_LITERAL(33, 767, 23), // "setFlagEquatorJ2000Grid"
QT_MOC_LITERAL(34, 791, 23), // "getFlagEquatorJ2000Grid"
QT_MOC_LITERAL(35, 815, 24), // "getColorEquatorJ2000Grid"
QT_MOC_LITERAL(36, 840, 24), // "setColorEquatorJ2000Grid"
QT_MOC_LITERAL(37, 865, 24), // "setFlagEclipticJ2000Grid"
QT_MOC_LITERAL(38, 890, 24), // "getFlagEclipticJ2000Grid"
QT_MOC_LITERAL(39, 915, 25), // "getColorEclipticJ2000Grid"
QT_MOC_LITERAL(40, 941, 25), // "setColorEclipticJ2000Grid"
QT_MOC_LITERAL(41, 967, 19), // "setFlagGalacticGrid"
QT_MOC_LITERAL(42, 987, 19), // "getFlagGalacticGrid"
QT_MOC_LITERAL(43, 1007, 20), // "getColorGalacticGrid"
QT_MOC_LITERAL(44, 1028, 20), // "setColorGalacticGrid"
QT_MOC_LITERAL(45, 1049, 18), // "setFlagEquatorLine"
QT_MOC_LITERAL(46, 1068, 18), // "getFlagEquatorLine"
QT_MOC_LITERAL(47, 1087, 19), // "getColorEquatorLine"
QT_MOC_LITERAL(48, 1107, 19), // "setColorEquatorLine"
QT_MOC_LITERAL(49, 1127, 19), // "setFlagEclipticLine"
QT_MOC_LITERAL(50, 1147, 19), // "getFlagEclipticLine"
QT_MOC_LITERAL(51, 1167, 20), // "getColorEclipticLine"
QT_MOC_LITERAL(52, 1188, 20), // "setColorEclipticLine"
QT_MOC_LITERAL(53, 1209, 19), // "setFlagMeridianLine"
QT_MOC_LITERAL(54, 1229, 19), // "getFlagMeridianLine"
QT_MOC_LITERAL(55, 1249, 20), // "getColorMeridianLine"
QT_MOC_LITERAL(56, 1270, 20), // "setColorMeridianLine"
QT_MOC_LITERAL(57, 1291, 18), // "setFlagHorizonLine"
QT_MOC_LITERAL(58, 1310, 18), // "getFlagHorizonLine"
QT_MOC_LITERAL(59, 1329, 19), // "getColorHorizonLine"
QT_MOC_LITERAL(60, 1349, 19), // "setColorHorizonLine"
QT_MOC_LITERAL(61, 1369, 24), // "setFlagGalacticPlaneLine"
QT_MOC_LITERAL(62, 1394, 24), // "getFlagGalacticPlaneLine"
QT_MOC_LITERAL(63, 1419, 25), // "getColorGalacticPlaneLine"
QT_MOC_LITERAL(64, 1445, 25), // "setColorGalacticPlaneLine"
QT_MOC_LITERAL(65, 1471, 12), // "setStelStyle"
QT_MOC_LITERAL(66, 1484, 7), // "section"
QT_MOC_LITERAL(67, 1492, 16), // "updateLineLabels"
QT_MOC_LITERAL(68, 1509, 22), // "azimuthalGridDisplayed"
QT_MOC_LITERAL(69, 1532, 18), // "azimuthalGridColor"
QT_MOC_LITERAL(70, 1551, 20), // "equatorGridDisplayed"
QT_MOC_LITERAL(71, 1572, 16), // "equatorGridColor"
QT_MOC_LITERAL(72, 1589, 25), // "equatorJ2000GridDisplayed"
QT_MOC_LITERAL(73, 1615, 26), // "eclipticJ2000GridDisplayed"
QT_MOC_LITERAL(74, 1642, 21), // "equatorJ2000GridColor"
QT_MOC_LITERAL(75, 1664, 21), // "galacticGridDisplayed"
QT_MOC_LITERAL(76, 1686, 17), // "galacticGridColor"
QT_MOC_LITERAL(77, 1704, 20), // "equatorLineDisplayed"
QT_MOC_LITERAL(78, 1725, 16), // "equatorLineColor"
QT_MOC_LITERAL(79, 1742, 21), // "eclipticLineDisplayed"
QT_MOC_LITERAL(80, 1764, 17), // "eclipticLineColor"
QT_MOC_LITERAL(81, 1782, 21), // "meridianLineDisplayed"
QT_MOC_LITERAL(82, 1804, 17), // "meridianLineColor"
QT_MOC_LITERAL(83, 1822, 20), // "horizonLineDisplayed"
QT_MOC_LITERAL(84, 1843, 16), // "horizonLineColor"
QT_MOC_LITERAL(85, 1860, 26), // "galacticPlaneLineDisplayed"
QT_MOC_LITERAL(86, 1887, 22) // "galacticPlaneLineColor"

    },
    "GridLinesMgr\0azimuthalGridDisplayedChanged\0"
    "\0azimuthalGridColorChanged\0Vec3f\0"
    "newColor\0equatorGridDisplayedChanged\0"
    "displayed\0equatorGridColorChanged\0"
    "equatorJ2000GridDisplayedChanged\0"
    "equatorJ2000GridColorChanged\0"
    "eclipticJ2000GridDisplayedChanged\0"
    "eclipticJ2000GridColorChanged\0"
    "galacticGridDisplayedChanged\0"
    "galacticGridColorChanged\0"
    "equatorLineDisplayedChanged\0"
    "equatorLineColorChanged\0"
    "eclipticLineDisplayedChanged\0"
    "eclipticLineColorChanged\0"
    "meridianLineDisplayedChanged\0"
    "meridianLineColorChanged\0"
    "horizonLineDisplayedChanged\0"
    "horizonLineColorChanged\0"
    "galacticPlaneLineDisplayedChanged\0"
    "galacticPlaneLineColorChanged\0"
    "setFlagAzimuthalGrid\0getFlagAzimuthalGrid\0"
    "getColorAzimuthalGrid\0setColorAzimuthalGrid\0"
    "setFlagEquatorGrid\0getFlagEquatorGrid\0"
    "getColorEquatorGrid\0setColorEquatorGrid\0"
    "setFlagEquatorJ2000Grid\0getFlagEquatorJ2000Grid\0"
    "getColorEquatorJ2000Grid\0"
    "setColorEquatorJ2000Grid\0"
    "setFlagEclipticJ2000Grid\0"
    "getFlagEclipticJ2000Grid\0"
    "getColorEclipticJ2000Grid\0"
    "setColorEclipticJ2000Grid\0setFlagGalacticGrid\0"
    "getFlagGalacticGrid\0getColorGalacticGrid\0"
    "setColorGalacticGrid\0setFlagEquatorLine\0"
    "getFlagEquatorLine\0getColorEquatorLine\0"
    "setColorEquatorLine\0setFlagEclipticLine\0"
    "getFlagEclipticLine\0getColorEclipticLine\0"
    "setColorEclipticLine\0setFlagMeridianLine\0"
    "getFlagMeridianLine\0getColorMeridianLine\0"
    "setColorMeridianLine\0setFlagHorizonLine\0"
    "getFlagHorizonLine\0getColorHorizonLine\0"
    "setColorHorizonLine\0setFlagGalacticPlaneLine\0"
    "getFlagGalacticPlaneLine\0"
    "getColorGalacticPlaneLine\0"
    "setColorGalacticPlaneLine\0setStelStyle\0"
    "section\0updateLineLabels\0"
    "azimuthalGridDisplayed\0azimuthalGridColor\0"
    "equatorGridDisplayed\0equatorGridColor\0"
    "equatorJ2000GridDisplayed\0"
    "eclipticJ2000GridDisplayed\0"
    "equatorJ2000GridColor\0galacticGridDisplayed\0"
    "galacticGridColor\0equatorLineDisplayed\0"
    "equatorLineColor\0eclipticLineDisplayed\0"
    "eclipticLineColor\0meridianLineDisplayed\0"
    "meridianLineColor\0horizonLineDisplayed\0"
    "horizonLineColor\0galacticPlaneLineDisplayed\0"
    "galacticPlaneLineColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GridLinesMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      62,   14, // methods
      19,  468, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  324,    2, 0x06 /* Public */,
       3,    1,  327,    2, 0x06 /* Public */,
       6,    1,  330,    2, 0x06 /* Public */,
       8,    1,  333,    2, 0x06 /* Public */,
       9,    1,  336,    2, 0x06 /* Public */,
      10,    1,  339,    2, 0x06 /* Public */,
      11,    1,  342,    2, 0x06 /* Public */,
      12,    1,  345,    2, 0x06 /* Public */,
      13,    1,  348,    2, 0x06 /* Public */,
      14,    1,  351,    2, 0x06 /* Public */,
      15,    1,  354,    2, 0x06 /* Public */,
      16,    1,  357,    2, 0x06 /* Public */,
      17,    1,  360,    2, 0x06 /* Public */,
      18,    1,  363,    2, 0x06 /* Public */,
      19,    1,  366,    2, 0x06 /* Public */,
      20,    1,  369,    2, 0x06 /* Public */,
      21,    1,  372,    2, 0x06 /* Public */,
      22,    1,  375,    2, 0x06 /* Public */,
      23,    1,  378,    2, 0x06 /* Public */,
      24,    1,  381,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    1,  384,    2, 0x0a /* Public */,
      26,    0,  387,    2, 0x0a /* Public */,
      27,    0,  388,    2, 0x0a /* Public */,
      28,    1,  389,    2, 0x0a /* Public */,
      29,    1,  392,    2, 0x0a /* Public */,
      30,    0,  395,    2, 0x0a /* Public */,
      31,    0,  396,    2, 0x0a /* Public */,
      32,    1,  397,    2, 0x0a /* Public */,
      33,    1,  400,    2, 0x0a /* Public */,
      34,    0,  403,    2, 0x0a /* Public */,
      35,    0,  404,    2, 0x0a /* Public */,
      36,    1,  405,    2, 0x0a /* Public */,
      37,    1,  408,    2, 0x0a /* Public */,
      38,    0,  411,    2, 0x0a /* Public */,
      39,    0,  412,    2, 0x0a /* Public */,
      40,    1,  413,    2, 0x0a /* Public */,
      41,    1,  416,    2, 0x0a /* Public */,
      42,    0,  419,    2, 0x0a /* Public */,
      43,    0,  420,    2, 0x0a /* Public */,
      44,    1,  421,    2, 0x0a /* Public */,
      45,    1,  424,    2, 0x0a /* Public */,
      46,    0,  427,    2, 0x0a /* Public */,
      47,    0,  428,    2, 0x0a /* Public */,
      48,    1,  429,    2, 0x0a /* Public */,
      49,    1,  432,    2, 0x0a /* Public */,
      50,    0,  435,    2, 0x0a /* Public */,
      51,    0,  436,    2, 0x0a /* Public */,
      52,    1,  437,    2, 0x0a /* Public */,
      53,    1,  440,    2, 0x0a /* Public */,
      54,    0,  443,    2, 0x0a /* Public */,
      55,    0,  444,    2, 0x0a /* Public */,
      56,    1,  445,    2, 0x0a /* Public */,
      57,    1,  448,    2, 0x0a /* Public */,
      58,    0,  451,    2, 0x0a /* Public */,
      59,    0,  452,    2, 0x0a /* Public */,
      60,    1,  453,    2, 0x0a /* Public */,
      61,    1,  456,    2, 0x0a /* Public */,
      62,    0,  459,    2, 0x0a /* Public */,
      63,    0,  460,    2, 0x0a /* Public */,
      64,    1,  461,    2, 0x0a /* Public */,
      65,    1,  464,    2, 0x08 /* Private */,
      67,    0,  467,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,   66,
    QMetaType::Void,

 // properties: name, type, flags
      68, QMetaType::Bool, 0x00495003,
      69, 0x80000000 | 4, 0x0049500b,
      70, QMetaType::Bool, 0x00495003,
      71, 0x80000000 | 4, 0x0049500b,
      72, QMetaType::Bool, 0x00495003,
      73, QMetaType::Bool, 0x00495003,
      74, 0x80000000 | 4, 0x0049500b,
      75, QMetaType::Bool, 0x00495003,
      76, 0x80000000 | 4, 0x0049500b,
      77, QMetaType::Bool, 0x00495003,
      78, 0x80000000 | 4, 0x0049500b,
      79, QMetaType::Bool, 0x00495003,
      80, 0x80000000 | 4, 0x0049500b,
      81, QMetaType::Bool, 0x00495003,
      82, 0x80000000 | 4, 0x0049500b,
      83, QMetaType::Bool, 0x00495003,
      84, 0x80000000 | 4, 0x0049500b,
      85, QMetaType::Bool, 0x00495003,
      86, 0x80000000 | 4, 0x0049500b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       6,
       5,
       8,
       9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,
      17,
      18,
      19,

       0        // eod
};

void GridLinesMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GridLinesMgr *_t = static_cast<GridLinesMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->azimuthalGridDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->azimuthalGridColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 2: _t->equatorGridDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 3: _t->equatorGridColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 4: _t->equatorJ2000GridDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 5: _t->equatorJ2000GridColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 6: _t->eclipticJ2000GridDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 7: _t->eclipticJ2000GridColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 8: _t->galacticGridDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 9: _t->galacticGridColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 10: _t->equatorLineDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 11: _t->equatorLineColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 12: _t->eclipticLineDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 13: _t->eclipticLineColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 14: _t->meridianLineDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 15: _t->meridianLineColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 16: _t->horizonLineDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 17: _t->horizonLineColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 18: _t->galacticPlaneLineDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 19: _t->galacticPlaneLineColorChanged((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 20: _t->setFlagAzimuthalGrid((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 21: { bool _r = _t->getFlagAzimuthalGrid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { Vec3f _r = _t->getColorAzimuthalGrid();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 23: _t->setColorAzimuthalGrid((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 24: _t->setFlagEquatorGrid((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 25: { bool _r = _t->getFlagEquatorGrid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 26: { Vec3f _r = _t->getColorEquatorGrid();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 27: _t->setColorEquatorGrid((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 28: _t->setFlagEquatorJ2000Grid((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 29: { bool _r = _t->getFlagEquatorJ2000Grid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 30: { Vec3f _r = _t->getColorEquatorJ2000Grid();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 31: _t->setColorEquatorJ2000Grid((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 32: _t->setFlagEclipticJ2000Grid((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 33: { bool _r = _t->getFlagEclipticJ2000Grid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 34: { Vec3f _r = _t->getColorEclipticJ2000Grid();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 35: _t->setColorEclipticJ2000Grid((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 36: _t->setFlagGalacticGrid((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 37: { bool _r = _t->getFlagGalacticGrid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 38: { Vec3f _r = _t->getColorGalacticGrid();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 39: _t->setColorGalacticGrid((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 40: _t->setFlagEquatorLine((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 41: { bool _r = _t->getFlagEquatorLine();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 42: { Vec3f _r = _t->getColorEquatorLine();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 43: _t->setColorEquatorLine((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 44: _t->setFlagEclipticLine((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 45: { bool _r = _t->getFlagEclipticLine();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 46: { Vec3f _r = _t->getColorEclipticLine();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 47: _t->setColorEclipticLine((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 48: _t->setFlagMeridianLine((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 49: { bool _r = _t->getFlagMeridianLine();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 50: { Vec3f _r = _t->getColorMeridianLine();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 51: _t->setColorMeridianLine((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 52: _t->setFlagHorizonLine((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 53: { bool _r = _t->getFlagHorizonLine();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 54: { Vec3f _r = _t->getColorHorizonLine();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 55: _t->setColorHorizonLine((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 56: _t->setFlagGalacticPlaneLine((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 57: { bool _r = _t->getFlagGalacticPlaneLine();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 58: { Vec3f _r = _t->getColorGalacticPlaneLine();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 59: _t->setColorGalacticPlaneLine((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 60: _t->setStelStyle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 61: _t->updateLineLabels(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::azimuthalGridDisplayedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::azimuthalGridColorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::equatorGridDisplayedChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::equatorGridColorChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::equatorJ2000GridDisplayedChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::equatorJ2000GridColorChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::eclipticJ2000GridDisplayedChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::eclipticJ2000GridColorChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::galacticGridDisplayedChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::galacticGridColorChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::equatorLineDisplayedChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::equatorLineColorChanged)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::eclipticLineDisplayedChanged)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::eclipticLineColorChanged)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::meridianLineDisplayedChanged)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::meridianLineColorChanged)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::horizonLineDisplayedChanged)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::horizonLineColorChanged)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const bool ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::galacticPlaneLineDisplayedChanged)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (GridLinesMgr::*_t)(const Vec3f & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GridLinesMgr::galacticPlaneLineColorChanged)) {
                *result = 19;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        GridLinesMgr *_t = static_cast<GridLinesMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getFlagAzimuthalGrid(); break;
        case 1: *reinterpret_cast< Vec3f*>(_v) = _t->getColorAzimuthalGrid(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getFlagEquatorGrid(); break;
        case 3: *reinterpret_cast< Vec3f*>(_v) = _t->getColorEquatorGrid(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getFlagEquatorJ2000Grid(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->getFlagEclipticJ2000Grid(); break;
        case 6: *reinterpret_cast< Vec3f*>(_v) = _t->getColorEquatorJ2000Grid(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->getFlagGalacticGrid(); break;
        case 8: *reinterpret_cast< Vec3f*>(_v) = _t->getColorGalacticGrid(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->getFlagEquatorLine(); break;
        case 10: *reinterpret_cast< Vec3f*>(_v) = _t->getColorEquatorLine(); break;
        case 11: *reinterpret_cast< bool*>(_v) = _t->getFlagEclipticLine(); break;
        case 12: *reinterpret_cast< Vec3f*>(_v) = _t->getColorEclipticLine(); break;
        case 13: *reinterpret_cast< bool*>(_v) = _t->getFlagMeridianLine(); break;
        case 14: *reinterpret_cast< Vec3f*>(_v) = _t->getColorMeridianLine(); break;
        case 15: *reinterpret_cast< bool*>(_v) = _t->getFlagHorizonLine(); break;
        case 16: *reinterpret_cast< Vec3f*>(_v) = _t->getColorHorizonLine(); break;
        case 17: *reinterpret_cast< bool*>(_v) = _t->getFlagGalacticPlaneLine(); break;
        case 18: *reinterpret_cast< Vec3f*>(_v) = _t->getColorGalacticPlaneLine(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        GridLinesMgr *_t = static_cast<GridLinesMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFlagAzimuthalGrid(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setColorAzimuthalGrid(*reinterpret_cast< Vec3f*>(_v)); break;
        case 2: _t->setFlagEquatorGrid(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setColorEquatorGrid(*reinterpret_cast< Vec3f*>(_v)); break;
        case 4: _t->setFlagEquatorJ2000Grid(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setFlagEclipticJ2000Grid(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setColorEquatorJ2000Grid(*reinterpret_cast< Vec3f*>(_v)); break;
        case 7: _t->setFlagGalacticGrid(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setColorGalacticGrid(*reinterpret_cast< Vec3f*>(_v)); break;
        case 9: _t->setFlagEquatorLine(*reinterpret_cast< bool*>(_v)); break;
        case 10: _t->setColorEquatorLine(*reinterpret_cast< Vec3f*>(_v)); break;
        case 11: _t->setFlagEclipticLine(*reinterpret_cast< bool*>(_v)); break;
        case 12: _t->setColorEclipticLine(*reinterpret_cast< Vec3f*>(_v)); break;
        case 13: _t->setFlagMeridianLine(*reinterpret_cast< bool*>(_v)); break;
        case 14: _t->setColorMeridianLine(*reinterpret_cast< Vec3f*>(_v)); break;
        case 15: _t->setFlagHorizonLine(*reinterpret_cast< bool*>(_v)); break;
        case 16: _t->setColorHorizonLine(*reinterpret_cast< Vec3f*>(_v)); break;
        case 17: _t->setFlagGalacticPlaneLine(*reinterpret_cast< bool*>(_v)); break;
        case 18: _t->setColorGalacticPlaneLine(*reinterpret_cast< Vec3f*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject GridLinesMgr::staticMetaObject = {
    { &StelModule::staticMetaObject, qt_meta_stringdata_GridLinesMgr.data,
      qt_meta_data_GridLinesMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GridLinesMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GridLinesMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GridLinesMgr.stringdata0))
        return static_cast<void*>(const_cast< GridLinesMgr*>(this));
    return StelModule::qt_metacast(_clname);
}

int GridLinesMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StelModule::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 62)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 62;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 62)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 62;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 19;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GridLinesMgr::azimuthalGridDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GridLinesMgr::azimuthalGridColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GridLinesMgr::equatorGridDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GridLinesMgr::equatorGridColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GridLinesMgr::equatorJ2000GridDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GridLinesMgr::equatorJ2000GridColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GridLinesMgr::eclipticJ2000GridDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GridLinesMgr::eclipticJ2000GridColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GridLinesMgr::galacticGridDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GridLinesMgr::galacticGridColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GridLinesMgr::equatorLineDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 10, _a);
}

// SIGNAL 11
void GridLinesMgr::equatorLineColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 11, _a);
}

// SIGNAL 12
void GridLinesMgr::eclipticLineDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 12, _a);
}

// SIGNAL 13
void GridLinesMgr::eclipticLineColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 13, _a);
}

// SIGNAL 14
void GridLinesMgr::meridianLineDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 14, _a);
}

// SIGNAL 15
void GridLinesMgr::meridianLineColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 15, _a);
}

// SIGNAL 16
void GridLinesMgr::horizonLineDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 16, _a);
}

// SIGNAL 17
void GridLinesMgr::horizonLineColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 17, _a);
}

// SIGNAL 18
void GridLinesMgr::galacticPlaneLineDisplayedChanged(const bool _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 18, _a);
}

// SIGNAL 19
void GridLinesMgr::galacticPlaneLineColorChanged(const Vec3f & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< GridLinesMgr *>(this), &staticMetaObject, 19, _a);
}
QT_END_MOC_NAMESPACE
