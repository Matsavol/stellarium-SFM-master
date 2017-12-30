/****************************************************************************
** Meta object code from reading C++ file 'StelMovementMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelMovementMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelMovementMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelMovementMgr_t {
    QByteArrayData data[71];
    char stringdata0[1006];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelMovementMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelMovementMgr_t qt_meta_stringdata_StelMovementMgr = {
    {
QT_MOC_LITERAL(0, 0, 15), // "StelMovementMgr"
QT_MOC_LITERAL(1, 16, 15), // "toggleMountMode"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "setEquatorialMount"
QT_MOC_LITERAL(4, 52, 1), // "b"
QT_MOC_LITERAL(5, 54, 15), // "setFlagTracking"
QT_MOC_LITERAL(6, 70, 15), // "getFlagTracking"
QT_MOC_LITERAL(7, 86, 17), // "setFlagLockEquPos"
QT_MOC_LITERAL(8, 104, 17), // "getFlagLockEquPos"
QT_MOC_LITERAL(9, 122, 7), // "panView"
QT_MOC_LITERAL(10, 130, 7), // "deltaAz"
QT_MOC_LITERAL(11, 138, 8), // "deltaAlt"
QT_MOC_LITERAL(12, 147, 19), // "setAutoMoveDuration"
QT_MOC_LITERAL(13, 167, 1), // "f"
QT_MOC_LITERAL(14, 169, 19), // "getAutoMoveDuration"
QT_MOC_LITERAL(15, 189, 33), // "setFlagAutoZoomOutResetsDirec..."
QT_MOC_LITERAL(16, 223, 33), // "getFlagAutoZoomOutResetsDirec..."
QT_MOC_LITERAL(17, 257, 21), // "getFlagEnableZoomKeys"
QT_MOC_LITERAL(18, 279, 21), // "setFlagEnableZoomKeys"
QT_MOC_LITERAL(19, 301, 21), // "getFlagEnableMoveKeys"
QT_MOC_LITERAL(20, 323, 21), // "setFlagEnableMoveKeys"
QT_MOC_LITERAL(21, 345, 29), // "getFlagEnableMoveAtScreenEdge"
QT_MOC_LITERAL(22, 375, 29), // "setFlagEnableMoveAtScreenEdge"
QT_MOC_LITERAL(23, 405, 28), // "getFlagEnableMouseNavigation"
QT_MOC_LITERAL(24, 434, 28), // "setFlagEnableMouseNavigation"
QT_MOC_LITERAL(25, 463, 11), // "moveToJ2000"
QT_MOC_LITERAL(26, 475, 5), // "Vec3d"
QT_MOC_LITERAL(27, 481, 3), // "aim"
QT_MOC_LITERAL(28, 485, 12), // "moveDuration"
QT_MOC_LITERAL(29, 498, 7), // "zooming"
QT_MOC_LITERAL(30, 506, 12), // "moveToObject"
QT_MOC_LITERAL(31, 519, 11), // "StelObjectP"
QT_MOC_LITERAL(32, 531, 6), // "target"
QT_MOC_LITERAL(33, 538, 6), // "zoomTo"
QT_MOC_LITERAL(34, 545, 6), // "aimFov"
QT_MOC_LITERAL(35, 552, 13), // "getCurrentFov"
QT_MOC_LITERAL(36, 566, 10), // "getInitFov"
QT_MOC_LITERAL(37, 577, 10), // "setInitFov"
QT_MOC_LITERAL(38, 588, 3), // "fov"
QT_MOC_LITERAL(39, 592, 23), // "getInitViewingDirection"
QT_MOC_LITERAL(40, 616, 29), // "setInitViewDirectionToCurrent"
QT_MOC_LITERAL(41, 646, 21), // "getViewDirectionJ2000"
QT_MOC_LITERAL(42, 668, 21), // "setViewDirectionJ2000"
QT_MOC_LITERAL(43, 690, 1), // "v"
QT_MOC_LITERAL(44, 692, 9), // "setMaxFov"
QT_MOC_LITERAL(45, 702, 3), // "max"
QT_MOC_LITERAL(46, 706, 9), // "getMaxFov"
QT_MOC_LITERAL(47, 716, 10), // "autoZoomIn"
QT_MOC_LITERAL(48, 727, 15), // "allowManualZoom"
QT_MOC_LITERAL(49, 743, 11), // "autoZoomOut"
QT_MOC_LITERAL(50, 755, 4), // "full"
QT_MOC_LITERAL(51, 760, 9), // "getAimFov"
QT_MOC_LITERAL(52, 770, 9), // "turnRight"
QT_MOC_LITERAL(53, 780, 8), // "turnLeft"
QT_MOC_LITERAL(54, 789, 6), // "turnUp"
QT_MOC_LITERAL(55, 796, 8), // "turnDown"
QT_MOC_LITERAL(56, 805, 8), // "moveSlow"
QT_MOC_LITERAL(57, 814, 6), // "zoomIn"
QT_MOC_LITERAL(58, 821, 7), // "zoomOut"
QT_MOC_LITERAL(59, 829, 12), // "setMountMode"
QT_MOC_LITERAL(60, 842, 9), // "MountMode"
QT_MOC_LITERAL(61, 852, 1), // "m"
QT_MOC_LITERAL(62, 854, 12), // "getMountMode"
QT_MOC_LITERAL(63, 867, 18), // "getEquatorialMount"
QT_MOC_LITERAL(64, 886, 15), // "setDragTimeMode"
QT_MOC_LITERAL(65, 902, 15), // "getDragTimeMode"
QT_MOC_LITERAL(66, 918, 20), // "selectedObjectChange"
QT_MOC_LITERAL(67, 939, 34), // "StelModule::StelModuleSelectA..."
QT_MOC_LITERAL(68, 974, 6), // "action"
QT_MOC_LITERAL(69, 981, 15), // "equatorialMount"
QT_MOC_LITERAL(70, 997, 8) // "tracking"

    },
    "StelMovementMgr\0toggleMountMode\0\0"
    "setEquatorialMount\0b\0setFlagTracking\0"
    "getFlagTracking\0setFlagLockEquPos\0"
    "getFlagLockEquPos\0panView\0deltaAz\0"
    "deltaAlt\0setAutoMoveDuration\0f\0"
    "getAutoMoveDuration\0"
    "setFlagAutoZoomOutResetsDirection\0"
    "getFlagAutoZoomOutResetsDirection\0"
    "getFlagEnableZoomKeys\0setFlagEnableZoomKeys\0"
    "getFlagEnableMoveKeys\0setFlagEnableMoveKeys\0"
    "getFlagEnableMoveAtScreenEdge\0"
    "setFlagEnableMoveAtScreenEdge\0"
    "getFlagEnableMouseNavigation\0"
    "setFlagEnableMouseNavigation\0moveToJ2000\0"
    "Vec3d\0aim\0moveDuration\0zooming\0"
    "moveToObject\0StelObjectP\0target\0zoomTo\0"
    "aimFov\0getCurrentFov\0getInitFov\0"
    "setInitFov\0fov\0getInitViewingDirection\0"
    "setInitViewDirectionToCurrent\0"
    "getViewDirectionJ2000\0setViewDirectionJ2000\0"
    "v\0setMaxFov\0max\0getMaxFov\0autoZoomIn\0"
    "allowManualZoom\0autoZoomOut\0full\0"
    "getAimFov\0turnRight\0turnLeft\0turnUp\0"
    "turnDown\0moveSlow\0zoomIn\0zoomOut\0"
    "setMountMode\0MountMode\0m\0getMountMode\0"
    "getEquatorialMount\0setDragTimeMode\0"
    "getDragTimeMode\0selectedObjectChange\0"
    "StelModule::StelModuleSelectAction\0"
    "action\0equatorialMount\0tracking"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelMovementMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
       2,  446, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  299,    2, 0x0a /* Public */,
       3,    1,  300,    2, 0x0a /* Public */,
       5,    1,  303,    2, 0x0a /* Public */,
       5,    0,  306,    2, 0x2a /* Public | MethodCloned */,
       6,    0,  307,    2, 0x0a /* Public */,
       7,    1,  308,    2, 0x0a /* Public */,
       8,    0,  311,    2, 0x0a /* Public */,
       9,    2,  312,    2, 0x0a /* Public */,
      12,    1,  317,    2, 0x0a /* Public */,
      14,    0,  320,    2, 0x0a /* Public */,
      15,    1,  321,    2, 0x0a /* Public */,
      16,    0,  324,    2, 0x0a /* Public */,
      17,    0,  325,    2, 0x0a /* Public */,
      18,    1,  326,    2, 0x0a /* Public */,
      19,    0,  329,    2, 0x0a /* Public */,
      20,    1,  330,    2, 0x0a /* Public */,
      21,    0,  333,    2, 0x0a /* Public */,
      22,    1,  334,    2, 0x0a /* Public */,
      23,    0,  337,    2, 0x0a /* Public */,
      24,    1,  338,    2, 0x0a /* Public */,
      25,    3,  341,    2, 0x0a /* Public */,
      25,    2,  348,    2, 0x2a /* Public | MethodCloned */,
      25,    1,  353,    2, 0x2a /* Public | MethodCloned */,
      30,    3,  356,    2, 0x0a /* Public */,
      30,    2,  363,    2, 0x2a /* Public | MethodCloned */,
      30,    1,  368,    2, 0x2a /* Public | MethodCloned */,
      33,    2,  371,    2, 0x0a /* Public */,
      33,    1,  376,    2, 0x2a /* Public | MethodCloned */,
      35,    0,  379,    2, 0x0a /* Public */,
      36,    0,  380,    2, 0x0a /* Public */,
      37,    1,  381,    2, 0x0a /* Public */,
      39,    0,  384,    2, 0x0a /* Public */,
      40,    0,  385,    2, 0x0a /* Public */,
      41,    0,  386,    2, 0x0a /* Public */,
      42,    1,  387,    2, 0x0a /* Public */,
      44,    1,  390,    2, 0x0a /* Public */,
      46,    0,  393,    2, 0x0a /* Public */,
      47,    2,  394,    2, 0x0a /* Public */,
      47,    1,  399,    2, 0x2a /* Public | MethodCloned */,
      47,    0,  402,    2, 0x2a /* Public | MethodCloned */,
      49,    2,  403,    2, 0x0a /* Public */,
      49,    1,  408,    2, 0x2a /* Public | MethodCloned */,
      49,    0,  411,    2, 0x2a /* Public | MethodCloned */,
      51,    0,  412,    2, 0x0a /* Public */,
      52,    1,  413,    2, 0x0a /* Public */,
      53,    1,  416,    2, 0x0a /* Public */,
      54,    1,  419,    2, 0x0a /* Public */,
      55,    1,  422,    2, 0x0a /* Public */,
      56,    1,  425,    2, 0x0a /* Public */,
      57,    1,  428,    2, 0x0a /* Public */,
      58,    1,  431,    2, 0x0a /* Public */,
      59,    1,  434,    2, 0x0a /* Public */,
      62,    0,  437,    2, 0x0a /* Public */,
      63,    0,  438,    2, 0x0a /* Public */,
      64,    1,  439,    2, 0x0a /* Public */,
      65,    0,  442,    2, 0x0a /* Public */,
      66,    1,  443,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   10,   11,
    QMetaType::Void, QMetaType::Float,   13,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 26, QMetaType::Float, QMetaType::Int,   27,   28,   29,
    QMetaType::Void, 0x80000000 | 26, QMetaType::Float,   27,   28,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 31, QMetaType::Float, QMetaType::Int,   32,   28,   29,
    QMetaType::Void, 0x80000000 | 31, QMetaType::Float,   32,   28,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, QMetaType::Double, QMetaType::Float,   34,   28,
    QMetaType::Void, QMetaType::Double,   34,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Double,   38,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 26,
    QMetaType::Void, 0x80000000 | 26,   43,
    QMetaType::Void, QMetaType::Double,   45,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Float, QMetaType::Bool,   28,   48,
    QMetaType::Void, QMetaType::Float,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Bool,   28,   50,
    QMetaType::Void, QMetaType::Float,   28,
    QMetaType::Void,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 60,   61,
    0x80000000 | 60,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 67,   68,

 // properties: name, type, flags
      69, QMetaType::Bool, 0x00095103,
      70, QMetaType::Bool, 0x00095003,

       0        // eod
};

void StelMovementMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelMovementMgr *_t = static_cast<StelMovementMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toggleMountMode(); break;
        case 1: _t->setEquatorialMount((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setFlagTracking((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setFlagTracking(); break;
        case 4: { bool _r = _t->getFlagTracking();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->setFlagLockEquPos((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: { bool _r = _t->getFlagLockEquPos();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->panView((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->setAutoMoveDuration((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: { float _r = _t->getAutoMoveDuration();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 10: _t->setFlagAutoZoomOutResetsDirection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: { bool _r = _t->getFlagAutoZoomOutResetsDirection();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->getFlagEnableZoomKeys();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: _t->setFlagEnableZoomKeys((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: { bool _r = _t->getFlagEnableMoveKeys();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: _t->setFlagEnableMoveKeys((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: { bool _r = _t->getFlagEnableMoveAtScreenEdge();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: _t->setFlagEnableMoveAtScreenEdge((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: { bool _r = _t->getFlagEnableMouseNavigation();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: _t->setFlagEnableMouseNavigation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->moveToJ2000((*reinterpret_cast< const Vec3d(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 21: _t->moveToJ2000((*reinterpret_cast< const Vec3d(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 22: _t->moveToJ2000((*reinterpret_cast< const Vec3d(*)>(_a[1]))); break;
        case 23: _t->moveToObject((*reinterpret_cast< const StelObjectP(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 24: _t->moveToObject((*reinterpret_cast< const StelObjectP(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 25: _t->moveToObject((*reinterpret_cast< const StelObjectP(*)>(_a[1]))); break;
        case 26: _t->zoomTo((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 27: _t->zoomTo((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: { double _r = _t->getCurrentFov();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 29: { double _r = _t->getInitFov();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 30: _t->setInitFov((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->getInitViewingDirection(); break;
        case 32: _t->setInitViewDirectionToCurrent(); break;
        case 33: { Vec3d _r = _t->getViewDirectionJ2000();
            if (_a[0]) *reinterpret_cast< Vec3d*>(_a[0]) = _r; }  break;
        case 34: _t->setViewDirectionJ2000((*reinterpret_cast< const Vec3d(*)>(_a[1]))); break;
        case 35: _t->setMaxFov((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: { double _r = _t->getMaxFov();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 37: _t->autoZoomIn((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 38: _t->autoZoomIn((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 39: _t->autoZoomIn(); break;
        case 40: _t->autoZoomOut((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 41: _t->autoZoomOut((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 42: _t->autoZoomOut(); break;
        case 43: { double _r = _t->getAimFov();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 44: _t->turnRight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->turnLeft((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->turnUp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->turnDown((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->moveSlow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->zoomIn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->zoomOut((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->setMountMode((*reinterpret_cast< MountMode(*)>(_a[1]))); break;
        case 52: { MountMode _r = _t->getMountMode();
            if (_a[0]) *reinterpret_cast< MountMode*>(_a[0]) = _r; }  break;
        case 53: { bool _r = _t->getEquatorialMount();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 54: _t->setDragTimeMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: { bool _r = _t->getDragTimeMode();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 56: _t->selectedObjectChange((*reinterpret_cast< StelModule::StelModuleSelectAction(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 56:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< StelModule::StelModuleSelectAction >(); break;
            }
            break;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StelMovementMgr *_t = static_cast<StelMovementMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getEquatorialMount(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getFlagTracking(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StelMovementMgr *_t = static_cast<StelMovementMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEquatorialMount(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setFlagTracking(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject StelMovementMgr::staticMetaObject = {
    { &StelModule::staticMetaObject, qt_meta_stringdata_StelMovementMgr.data,
      qt_meta_data_StelMovementMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelMovementMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelMovementMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelMovementMgr.stringdata0))
        return static_cast<void*>(const_cast< StelMovementMgr*>(this));
    return StelModule::qt_metacast(_clname);
}

int StelMovementMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StelModule::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
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
