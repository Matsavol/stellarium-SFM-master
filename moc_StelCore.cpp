/****************************************************************************
** Meta object code from reading C++ file 'StelCore.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelCore.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelCore.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelCore_t {
    QByteArrayData data[147];
    char stringdata0[2324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelCore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelCore_t qt_meta_stringdata_StelCore = {
    {
QT_MOC_LITERAL(0, 0, 8), // "StelCore"
QT_MOC_LITERAL(1, 9, 15), // "locationChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "StelLocation"
QT_MOC_LITERAL(4, 39, 15), // "timeRateChanged"
QT_MOC_LITERAL(5, 55, 4), // "rate"
QT_MOC_LITERAL(6, 60, 24), // "setCurrentProjectionType"
QT_MOC_LITERAL(7, 85, 14), // "ProjectionType"
QT_MOC_LITERAL(8, 100, 4), // "type"
QT_MOC_LITERAL(9, 105, 24), // "getCurrentProjectionType"
QT_MOC_LITERAL(10, 130, 27), // "getCurrentProjectionTypeKey"
QT_MOC_LITERAL(11, 158, 27), // "setCurrentProjectionTypeKey"
QT_MOC_LITERAL(12, 186, 24), // "getAllProjectionTypeKeys"
QT_MOC_LITERAL(13, 211, 25), // "setCurrentDeltaTAlgorithm"
QT_MOC_LITERAL(14, 237, 15), // "DeltaTAlgorithm"
QT_MOC_LITERAL(15, 253, 9), // "algorithm"
QT_MOC_LITERAL(16, 263, 25), // "getCurrentDeltaTAlgorithm"
QT_MOC_LITERAL(17, 289, 36), // "getCurrentDeltaTAlgorithmDesc..."
QT_MOC_LITERAL(18, 326, 28), // "getCurrentDeltaTAlgorithmKey"
QT_MOC_LITERAL(19, 355, 28), // "setCurrentDeltaTAlgorithmKey"
QT_MOC_LITERAL(20, 384, 11), // "setMaskType"
QT_MOC_LITERAL(21, 396, 36), // "StelProjector::StelProjectorM..."
QT_MOC_LITERAL(22, 433, 1), // "m"
QT_MOC_LITERAL(23, 435, 20), // "setFlagGravityLabels"
QT_MOC_LITERAL(24, 456, 7), // "gravity"
QT_MOC_LITERAL(25, 464, 28), // "setDefautAngleForGravityText"
QT_MOC_LITERAL(26, 493, 1), // "a"
QT_MOC_LITERAL(27, 495, 11), // "setFlipHorz"
QT_MOC_LITERAL(28, 507, 4), // "flip"
QT_MOC_LITERAL(29, 512, 11), // "setFlipVert"
QT_MOC_LITERAL(30, 524, 11), // "getFlipHorz"
QT_MOC_LITERAL(31, 536, 11), // "getFlipVert"
QT_MOC_LITERAL(32, 548, 20), // "getDefaultLocationID"
QT_MOC_LITERAL(33, 569, 20), // "setDefaultLocationID"
QT_MOC_LITERAL(34, 590, 2), // "id"
QT_MOC_LITERAL(35, 593, 23), // "returnToDefaultLocation"
QT_MOC_LITERAL(36, 617, 12), // "returnToHome"
QT_MOC_LITERAL(37, 630, 7), // "setJDay"
QT_MOC_LITERAL(38, 638, 2), // "JD"
QT_MOC_LITERAL(39, 641, 7), // "getJDay"
QT_MOC_LITERAL(40, 649, 8), // "setMJDay"
QT_MOC_LITERAL(41, 658, 3), // "MJD"
QT_MOC_LITERAL(42, 662, 8), // "getMJDay"
QT_MOC_LITERAL(43, 671, 16), // "getPresetSkyTime"
QT_MOC_LITERAL(44, 688, 16), // "setPresetSkyTime"
QT_MOC_LITERAL(45, 705, 1), // "d"
QT_MOC_LITERAL(46, 707, 11), // "setTimeRate"
QT_MOC_LITERAL(47, 719, 2), // "ts"
QT_MOC_LITERAL(48, 722, 11), // "getTimeRate"
QT_MOC_LITERAL(49, 734, 17), // "increaseTimeSpeed"
QT_MOC_LITERAL(50, 752, 17), // "decreaseTimeSpeed"
QT_MOC_LITERAL(51, 770, 21), // "increaseTimeSpeedLess"
QT_MOC_LITERAL(52, 792, 21), // "decreaseTimeSpeedLess"
QT_MOC_LITERAL(53, 814, 16), // "setZeroTimeSpeed"
QT_MOC_LITERAL(54, 831, 16), // "setRealTimeSpeed"
QT_MOC_LITERAL(55, 848, 19), // "toggleRealTimeSpeed"
QT_MOC_LITERAL(56, 868, 16), // "getRealTimeSpeed"
QT_MOC_LITERAL(57, 885, 10), // "setTimeNow"
QT_MOC_LITERAL(58, 896, 12), // "setTodayTime"
QT_MOC_LITERAL(59, 909, 6), // "target"
QT_MOC_LITERAL(60, 916, 12), // "getIsTimeNow"
QT_MOC_LITERAL(61, 929, 16), // "getInitTodayTime"
QT_MOC_LITERAL(62, 946, 16), // "setInitTodayTime"
QT_MOC_LITERAL(63, 963, 1), // "t"
QT_MOC_LITERAL(64, 965, 2), // "dt"
QT_MOC_LITERAL(65, 968, 7), // "addHour"
QT_MOC_LITERAL(66, 976, 6), // "addDay"
QT_MOC_LITERAL(67, 983, 7), // "addWeek"
QT_MOC_LITERAL(68, 991, 14), // "addSiderealDay"
QT_MOC_LITERAL(69, 1006, 15), // "addSiderealWeek"
QT_MOC_LITERAL(70, 1022, 16), // "addSiderealMonth"
QT_MOC_LITERAL(71, 1039, 15), // "addSiderealYear"
QT_MOC_LITERAL(72, 1055, 18), // "addSiderealCentury"
QT_MOC_LITERAL(73, 1074, 12), // "subtractHour"
QT_MOC_LITERAL(74, 1087, 11), // "subtractDay"
QT_MOC_LITERAL(75, 1099, 12), // "subtractWeek"
QT_MOC_LITERAL(76, 1112, 19), // "subtractSiderealDay"
QT_MOC_LITERAL(77, 1132, 20), // "subtractSiderealWeek"
QT_MOC_LITERAL(78, 1153, 21), // "subtractSiderealMonth"
QT_MOC_LITERAL(79, 1175, 20), // "subtractSiderealYear"
QT_MOC_LITERAL(80, 1196, 23), // "subtractSiderealCentury"
QT_MOC_LITERAL(81, 1220, 15), // "addSynodicMonth"
QT_MOC_LITERAL(82, 1236, 15), // "addDraconicYear"
QT_MOC_LITERAL(83, 1252, 16), // "addDraconicMonth"
QT_MOC_LITERAL(84, 1269, 19), // "addAnomalisticMonth"
QT_MOC_LITERAL(85, 1289, 16), // "addTropicalMonth"
QT_MOC_LITERAL(86, 1306, 15), // "addTropicalYear"
QT_MOC_LITERAL(87, 1322, 18), // "addTropicalCentury"
QT_MOC_LITERAL(88, 1341, 20), // "subtractSynodicMonth"
QT_MOC_LITERAL(89, 1362, 20), // "subtractDraconicYear"
QT_MOC_LITERAL(90, 1383, 21), // "subtractDraconicMonth"
QT_MOC_LITERAL(91, 1405, 24), // "subtractAnomalisticMonth"
QT_MOC_LITERAL(92, 1430, 21), // "subtractTropicalMonth"
QT_MOC_LITERAL(93, 1452, 20), // "subtractTropicalYear"
QT_MOC_LITERAL(94, 1473, 23), // "subtractTropicalCentury"
QT_MOC_LITERAL(95, 1497, 12), // "addSolarDays"
QT_MOC_LITERAL(96, 1510, 15), // "addSiderealDays"
QT_MOC_LITERAL(97, 1526, 22), // "moveObserverToSelected"
QT_MOC_LITERAL(98, 1549, 19), // "setDeltaTCustomYear"
QT_MOC_LITERAL(99, 1569, 1), // "y"
QT_MOC_LITERAL(100, 1571, 19), // "setDeltaTCustomNDot"
QT_MOC_LITERAL(101, 1591, 1), // "v"
QT_MOC_LITERAL(102, 1593, 35), // "setDeltaTCustomEquationCoeffi..."
QT_MOC_LITERAL(103, 1629, 5), // "Vec3f"
QT_MOC_LITERAL(104, 1635, 1), // "c"
QT_MOC_LITERAL(105, 1637, 19), // "getDeltaTCustomYear"
QT_MOC_LITERAL(106, 1657, 19), // "getDeltaTCustomNDot"
QT_MOC_LITERAL(107, 1677, 35), // "getDeltaTCustomEquationCoeffi..."
QT_MOC_LITERAL(108, 1713, 8), // "flipHorz"
QT_MOC_LITERAL(109, 1722, 8), // "flipVert"
QT_MOC_LITERAL(110, 1731, 21), // "ProjectionPerspective"
QT_MOC_LITERAL(111, 1753, 19), // "ProjectionEqualArea"
QT_MOC_LITERAL(112, 1773, 23), // "ProjectionStereographic"
QT_MOC_LITERAL(113, 1797, 17), // "ProjectionFisheye"
QT_MOC_LITERAL(114, 1815, 16), // "ProjectionHammer"
QT_MOC_LITERAL(115, 1832, 18), // "ProjectionCylinder"
QT_MOC_LITERAL(116, 1851, 18), // "ProjectionMercator"
QT_MOC_LITERAL(117, 1870, 22), // "ProjectionOrthographic"
QT_MOC_LITERAL(118, 1893, 17), // "WithoutCorrection"
QT_MOC_LITERAL(119, 1911, 6), // "Schoch"
QT_MOC_LITERAL(120, 1918, 8), // "Clemence"
QT_MOC_LITERAL(121, 1927, 3), // "IAU"
QT_MOC_LITERAL(122, 1931, 21), // "AstronomicalEphemeris"
QT_MOC_LITERAL(123, 1953, 18), // "TuckermanGoldstine"
QT_MOC_LITERAL(124, 1972, 16), // "MullerStephenson"
QT_MOC_LITERAL(125, 1989, 14), // "Stephenson1978"
QT_MOC_LITERAL(126, 2004, 16), // "SchmadelZech1979"
QT_MOC_LITERAL(127, 2021, 22), // "MorrisonStephenson1982"
QT_MOC_LITERAL(128, 2044, 22), // "StephensonMorrison1984"
QT_MOC_LITERAL(129, 2067, 17), // "StephensonHoulden"
QT_MOC_LITERAL(130, 2085, 7), // "Espenak"
QT_MOC_LITERAL(131, 2093, 9), // "Borkowski"
QT_MOC_LITERAL(132, 2103, 16), // "SchmadelZech1988"
QT_MOC_LITERAL(133, 2120, 13), // "ChaprontTouze"
QT_MOC_LITERAL(134, 2134, 22), // "StephensonMorrison1995"
QT_MOC_LITERAL(135, 2157, 14), // "Stephenson1997"
QT_MOC_LITERAL(136, 2172, 13), // "ChaprontMeeus"
QT_MOC_LITERAL(137, 2186, 11), // "JPLHorizons"
QT_MOC_LITERAL(138, 2198, 11), // "MeeusSimons"
QT_MOC_LITERAL(139, 2210, 18), // "MontenbruckPfleger"
QT_MOC_LITERAL(140, 2229, 18), // "ReingoldDershowitz"
QT_MOC_LITERAL(141, 2248, 22), // "MorrisonStephenson2004"
QT_MOC_LITERAL(142, 2271, 5), // "Reijs"
QT_MOC_LITERAL(143, 2277, 12), // "EspenakMeeus"
QT_MOC_LITERAL(144, 2290, 8), // "Banjevic"
QT_MOC_LITERAL(145, 2299, 17), // "IslamSadiqQureshi"
QT_MOC_LITERAL(146, 2317, 6) // "Custom"

    },
    "StelCore\0locationChanged\0\0StelLocation\0"
    "timeRateChanged\0rate\0setCurrentProjectionType\0"
    "ProjectionType\0type\0getCurrentProjectionType\0"
    "getCurrentProjectionTypeKey\0"
    "setCurrentProjectionTypeKey\0"
    "getAllProjectionTypeKeys\0"
    "setCurrentDeltaTAlgorithm\0DeltaTAlgorithm\0"
    "algorithm\0getCurrentDeltaTAlgorithm\0"
    "getCurrentDeltaTAlgorithmDescription\0"
    "getCurrentDeltaTAlgorithmKey\0"
    "setCurrentDeltaTAlgorithmKey\0setMaskType\0"
    "StelProjector::StelProjectorMaskType\0"
    "m\0setFlagGravityLabels\0gravity\0"
    "setDefautAngleForGravityText\0a\0"
    "setFlipHorz\0flip\0setFlipVert\0getFlipHorz\0"
    "getFlipVert\0getDefaultLocationID\0"
    "setDefaultLocationID\0id\0returnToDefaultLocation\0"
    "returnToHome\0setJDay\0JD\0getJDay\0"
    "setMJDay\0MJD\0getMJDay\0getPresetSkyTime\0"
    "setPresetSkyTime\0d\0setTimeRate\0ts\0"
    "getTimeRate\0increaseTimeSpeed\0"
    "decreaseTimeSpeed\0increaseTimeSpeedLess\0"
    "decreaseTimeSpeedLess\0setZeroTimeSpeed\0"
    "setRealTimeSpeed\0toggleRealTimeSpeed\0"
    "getRealTimeSpeed\0setTimeNow\0setTodayTime\0"
    "target\0getIsTimeNow\0getInitTodayTime\0"
    "setInitTodayTime\0t\0dt\0addHour\0addDay\0"
    "addWeek\0addSiderealDay\0addSiderealWeek\0"
    "addSiderealMonth\0addSiderealYear\0"
    "addSiderealCentury\0subtractHour\0"
    "subtractDay\0subtractWeek\0subtractSiderealDay\0"
    "subtractSiderealWeek\0subtractSiderealMonth\0"
    "subtractSiderealYear\0subtractSiderealCentury\0"
    "addSynodicMonth\0addDraconicYear\0"
    "addDraconicMonth\0addAnomalisticMonth\0"
    "addTropicalMonth\0addTropicalYear\0"
    "addTropicalCentury\0subtractSynodicMonth\0"
    "subtractDraconicYear\0subtractDraconicMonth\0"
    "subtractAnomalisticMonth\0subtractTropicalMonth\0"
    "subtractTropicalYear\0subtractTropicalCentury\0"
    "addSolarDays\0addSiderealDays\0"
    "moveObserverToSelected\0setDeltaTCustomYear\0"
    "y\0setDeltaTCustomNDot\0v\0"
    "setDeltaTCustomEquationCoefficients\0"
    "Vec3f\0c\0getDeltaTCustomYear\0"
    "getDeltaTCustomNDot\0"
    "getDeltaTCustomEquationCoefficients\0"
    "flipHorz\0flipVert\0ProjectionPerspective\0"
    "ProjectionEqualArea\0ProjectionStereographic\0"
    "ProjectionFisheye\0ProjectionHammer\0"
    "ProjectionCylinder\0ProjectionMercator\0"
    "ProjectionOrthographic\0WithoutCorrection\0"
    "Schoch\0Clemence\0IAU\0AstronomicalEphemeris\0"
    "TuckermanGoldstine\0MullerStephenson\0"
    "Stephenson1978\0SchmadelZech1979\0"
    "MorrisonStephenson1982\0StephensonMorrison1984\0"
    "StephensonHoulden\0Espenak\0Borkowski\0"
    "SchmadelZech1988\0ChaprontTouze\0"
    "StephensonMorrison1995\0Stephenson1997\0"
    "ChaprontMeeus\0JPLHorizons\0MeeusSimons\0"
    "MontenbruckPfleger\0ReingoldDershowitz\0"
    "MorrisonStephenson2004\0Reijs\0EspenakMeeus\0"
    "Banjevic\0IslamSadiqQureshi\0Custom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelCore[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      84,   14, // methods
       2,  566, // properties
       2,  572, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  434,    2, 0x06 /* Public */,
       4,    1,  437,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  440,    2, 0x0a /* Public */,
       9,    0,  443,    2, 0x0a /* Public */,
      10,    0,  444,    2, 0x0a /* Public */,
      11,    1,  445,    2, 0x0a /* Public */,
      12,    0,  448,    2, 0x0a /* Public */,
      13,    1,  449,    2, 0x0a /* Public */,
      16,    0,  452,    2, 0x0a /* Public */,
      17,    0,  453,    2, 0x0a /* Public */,
      18,    0,  454,    2, 0x0a /* Public */,
      19,    1,  455,    2, 0x0a /* Public */,
      20,    1,  458,    2, 0x0a /* Public */,
      23,    1,  461,    2, 0x0a /* Public */,
      25,    1,  464,    2, 0x0a /* Public */,
      27,    1,  467,    2, 0x0a /* Public */,
      29,    1,  470,    2, 0x0a /* Public */,
      30,    0,  473,    2, 0x0a /* Public */,
      31,    0,  474,    2, 0x0a /* Public */,
      32,    0,  475,    2, 0x0a /* Public */,
      33,    1,  476,    2, 0x0a /* Public */,
      35,    0,  479,    2, 0x0a /* Public */,
      36,    0,  480,    2, 0x0a /* Public */,
      37,    1,  481,    2, 0x0a /* Public */,
      39,    0,  484,    2, 0x0a /* Public */,
      40,    1,  485,    2, 0x0a /* Public */,
      42,    0,  488,    2, 0x0a /* Public */,
      43,    0,  489,    2, 0x0a /* Public */,
      44,    1,  490,    2, 0x0a /* Public */,
      46,    1,  493,    2, 0x0a /* Public */,
      48,    0,  496,    2, 0x0a /* Public */,
      49,    0,  497,    2, 0x0a /* Public */,
      50,    0,  498,    2, 0x0a /* Public */,
      51,    0,  499,    2, 0x0a /* Public */,
      52,    0,  500,    2, 0x0a /* Public */,
      53,    0,  501,    2, 0x0a /* Public */,
      54,    0,  502,    2, 0x0a /* Public */,
      55,    0,  503,    2, 0x0a /* Public */,
      56,    0,  504,    2, 0x0a /* Public */,
      57,    0,  505,    2, 0x0a /* Public */,
      58,    1,  506,    2, 0x0a /* Public */,
      60,    0,  509,    2, 0x0a /* Public */,
      61,    0,  510,    2, 0x0a /* Public */,
      62,    1,  511,    2, 0x0a /* Public */,
      44,    1,  514,    2, 0x0a /* Public */,
      65,    0,  517,    2, 0x0a /* Public */,
      66,    0,  518,    2, 0x0a /* Public */,
      67,    0,  519,    2, 0x0a /* Public */,
      68,    0,  520,    2, 0x0a /* Public */,
      69,    0,  521,    2, 0x0a /* Public */,
      70,    0,  522,    2, 0x0a /* Public */,
      71,    0,  523,    2, 0x0a /* Public */,
      72,    0,  524,    2, 0x0a /* Public */,
      73,    0,  525,    2, 0x0a /* Public */,
      74,    0,  526,    2, 0x0a /* Public */,
      75,    0,  527,    2, 0x0a /* Public */,
      76,    0,  528,    2, 0x0a /* Public */,
      77,    0,  529,    2, 0x0a /* Public */,
      78,    0,  530,    2, 0x0a /* Public */,
      79,    0,  531,    2, 0x0a /* Public */,
      80,    0,  532,    2, 0x0a /* Public */,
      81,    0,  533,    2, 0x0a /* Public */,
      82,    0,  534,    2, 0x0a /* Public */,
      83,    0,  535,    2, 0x0a /* Public */,
      84,    0,  536,    2, 0x0a /* Public */,
      85,    0,  537,    2, 0x0a /* Public */,
      86,    0,  538,    2, 0x0a /* Public */,
      87,    0,  539,    2, 0x0a /* Public */,
      88,    0,  540,    2, 0x0a /* Public */,
      89,    0,  541,    2, 0x0a /* Public */,
      90,    0,  542,    2, 0x0a /* Public */,
      91,    0,  543,    2, 0x0a /* Public */,
      92,    0,  544,    2, 0x0a /* Public */,
      93,    0,  545,    2, 0x0a /* Public */,
      94,    0,  546,    2, 0x0a /* Public */,
      95,    1,  547,    2, 0x0a /* Public */,
      96,    1,  550,    2, 0x0a /* Public */,
      97,    0,  553,    2, 0x0a /* Public */,
      98,    1,  554,    2, 0x0a /* Public */,
     100,    1,  557,    2, 0x0a /* Public */,
     102,    1,  560,    2, 0x0a /* Public */,
     105,    0,  563,    2, 0x0a /* Public */,
     106,    0,  564,    2, 0x0a /* Public */,
     107,    0,  565,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Double,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    0x80000000 | 7,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::QStringList,
    QMetaType::Void, 0x80000000 | 14,   15,
    0x80000000 | 14,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Float,   26,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   38,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double,   41,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double,   45,
    QMetaType::Void, QMetaType::Double,   47,
    QMetaType::Double,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,   59,
    QMetaType::Bool,
    QMetaType::QTime,
    QMetaType::Void, QMetaType::QTime,   63,
    QMetaType::Void, QMetaType::QDateTime,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   45,
    QMetaType::Void, QMetaType::Double,   45,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   99,
    QMetaType::Void, QMetaType::Float,  101,
    QMetaType::Void, 0x80000000 | 103,  104,
    QMetaType::Float,
    QMetaType::Float,
    0x80000000 | 103,

 // properties: name, type, flags
     108, QMetaType::Bool, 0x00095103,
     109, QMetaType::Bool, 0x00095103,

 // enums: name, flags, count, data
       7, 0x0,    8,  580,
      14, 0x0,   29,  596,

 // enum data: key, value
     110, uint(StelCore::ProjectionPerspective),
     111, uint(StelCore::ProjectionEqualArea),
     112, uint(StelCore::ProjectionStereographic),
     113, uint(StelCore::ProjectionFisheye),
     114, uint(StelCore::ProjectionHammer),
     115, uint(StelCore::ProjectionCylinder),
     116, uint(StelCore::ProjectionMercator),
     117, uint(StelCore::ProjectionOrthographic),
     118, uint(StelCore::WithoutCorrection),
     119, uint(StelCore::Schoch),
     120, uint(StelCore::Clemence),
     121, uint(StelCore::IAU),
     122, uint(StelCore::AstronomicalEphemeris),
     123, uint(StelCore::TuckermanGoldstine),
     124, uint(StelCore::MullerStephenson),
     125, uint(StelCore::Stephenson1978),
     126, uint(StelCore::SchmadelZech1979),
     127, uint(StelCore::MorrisonStephenson1982),
     128, uint(StelCore::StephensonMorrison1984),
     129, uint(StelCore::StephensonHoulden),
     130, uint(StelCore::Espenak),
     131, uint(StelCore::Borkowski),
     132, uint(StelCore::SchmadelZech1988),
     133, uint(StelCore::ChaprontTouze),
     134, uint(StelCore::StephensonMorrison1995),
     135, uint(StelCore::Stephenson1997),
     136, uint(StelCore::ChaprontMeeus),
     137, uint(StelCore::JPLHorizons),
     138, uint(StelCore::MeeusSimons),
     139, uint(StelCore::MontenbruckPfleger),
     140, uint(StelCore::ReingoldDershowitz),
     141, uint(StelCore::MorrisonStephenson2004),
     142, uint(StelCore::Reijs),
     143, uint(StelCore::EspenakMeeus),
     144, uint(StelCore::Banjevic),
     145, uint(StelCore::IslamSadiqQureshi),
     146, uint(StelCore::Custom),

       0        // eod
};

void StelCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelCore *_t = static_cast<StelCore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->locationChanged((*reinterpret_cast< StelLocation(*)>(_a[1]))); break;
        case 1: _t->timeRateChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setCurrentProjectionType((*reinterpret_cast< ProjectionType(*)>(_a[1]))); break;
        case 3: { ProjectionType _r = _t->getCurrentProjectionType();
            if (_a[0]) *reinterpret_cast< ProjectionType*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->getCurrentProjectionTypeKey();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: _t->setCurrentProjectionTypeKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { QStringList _r = _t->getAllProjectionTypeKeys();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 7: _t->setCurrentDeltaTAlgorithm((*reinterpret_cast< DeltaTAlgorithm(*)>(_a[1]))); break;
        case 8: { DeltaTAlgorithm _r = _t->getCurrentDeltaTAlgorithm();
            if (_a[0]) *reinterpret_cast< DeltaTAlgorithm*>(_a[0]) = _r; }  break;
        case 9: { QString _r = _t->getCurrentDeltaTAlgorithmDescription();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QString _r = _t->getCurrentDeltaTAlgorithmKey();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: _t->setCurrentDeltaTAlgorithmKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->setMaskType((*reinterpret_cast< StelProjector::StelProjectorMaskType(*)>(_a[1]))); break;
        case 13: _t->setFlagGravityLabels((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setDefautAngleForGravityText((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 15: _t->setFlipHorz((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->setFlipVert((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: { bool _r = _t->getFlipHorz();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: { bool _r = _t->getFlipVert();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { QString _r = _t->getDefaultLocationID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 20: _t->setDefaultLocationID((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->returnToDefaultLocation(); break;
        case 22: _t->returnToHome(); break;
        case 23: _t->setJDay((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: { double _r = _t->getJDay();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 25: _t->setMJDay((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: { double _r = _t->getMJDay();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 27: { double _r = _t->getPresetSkyTime();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 28: _t->setPresetSkyTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->setTimeRate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: { double _r = _t->getTimeRate();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 31: _t->increaseTimeSpeed(); break;
        case 32: _t->decreaseTimeSpeed(); break;
        case 33: _t->increaseTimeSpeedLess(); break;
        case 34: _t->decreaseTimeSpeedLess(); break;
        case 35: _t->setZeroTimeSpeed(); break;
        case 36: _t->setRealTimeSpeed(); break;
        case 37: _t->toggleRealTimeSpeed(); break;
        case 38: { bool _r = _t->getRealTimeSpeed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 39: _t->setTimeNow(); break;
        case 40: _t->setTodayTime((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 41: { bool _r = _t->getIsTimeNow();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 42: { QTime _r = _t->getInitTodayTime();
            if (_a[0]) *reinterpret_cast< QTime*>(_a[0]) = _r; }  break;
        case 43: _t->setInitTodayTime((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 44: _t->setPresetSkyTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 45: _t->addHour(); break;
        case 46: _t->addDay(); break;
        case 47: _t->addWeek(); break;
        case 48: _t->addSiderealDay(); break;
        case 49: _t->addSiderealWeek(); break;
        case 50: _t->addSiderealMonth(); break;
        case 51: _t->addSiderealYear(); break;
        case 52: _t->addSiderealCentury(); break;
        case 53: _t->subtractHour(); break;
        case 54: _t->subtractDay(); break;
        case 55: _t->subtractWeek(); break;
        case 56: _t->subtractSiderealDay(); break;
        case 57: _t->subtractSiderealWeek(); break;
        case 58: _t->subtractSiderealMonth(); break;
        case 59: _t->subtractSiderealYear(); break;
        case 60: _t->subtractSiderealCentury(); break;
        case 61: _t->addSynodicMonth(); break;
        case 62: _t->addDraconicYear(); break;
        case 63: _t->addDraconicMonth(); break;
        case 64: _t->addAnomalisticMonth(); break;
        case 65: _t->addTropicalMonth(); break;
        case 66: _t->addTropicalYear(); break;
        case 67: _t->addTropicalCentury(); break;
        case 68: _t->subtractSynodicMonth(); break;
        case 69: _t->subtractDraconicYear(); break;
        case 70: _t->subtractDraconicMonth(); break;
        case 71: _t->subtractAnomalisticMonth(); break;
        case 72: _t->subtractTropicalMonth(); break;
        case 73: _t->subtractTropicalYear(); break;
        case 74: _t->subtractTropicalCentury(); break;
        case 75: _t->addSolarDays((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 76: _t->addSiderealDays((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 77: _t->moveObserverToSelected(); break;
        case 78: _t->setDeltaTCustomYear((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 79: _t->setDeltaTCustomNDot((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 80: _t->setDeltaTCustomEquationCoefficients((*reinterpret_cast< Vec3f(*)>(_a[1]))); break;
        case 81: { float _r = _t->getDeltaTCustomYear();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 82: { float _r = _t->getDeltaTCustomNDot();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 83: { Vec3f _r = _t->getDeltaTCustomEquationCoefficients();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StelCore::*_t)(StelLocation );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelCore::locationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (StelCore::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelCore::timeRateChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StelCore *_t = static_cast<StelCore *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getFlipHorz(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getFlipVert(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StelCore *_t = static_cast<StelCore *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFlipHorz(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setFlipVert(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject StelCore::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StelCore.data,
      qt_meta_data_StelCore,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelCore::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelCore.stringdata0))
        return static_cast<void*>(const_cast< StelCore*>(this));
    return QObject::qt_metacast(_clname);
}

int StelCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 84)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 84;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 84)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 84;
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
void StelCore::locationChanged(StelLocation _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StelCore::timeRateChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
