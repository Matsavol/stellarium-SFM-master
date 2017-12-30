/****************************************************************************
** Meta object code from reading C++ file 'LandscapeMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/modules/LandscapeMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LandscapeMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LandscapeMgr_t {
    QByteArrayData data[74];
    char stringdata0[1366];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LandscapeMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LandscapeMgr_t qt_meta_stringdata_LandscapeMgr = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LandscapeMgr"
QT_MOC_LITERAL(1, 13, 26), // "atmosphereDisplayedChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "displayed"
QT_MOC_LITERAL(4, 51, 31), // "cardinalsPointsDisplayedChanged"
QT_MOC_LITERAL(5, 83, 19), // "fogDisplayedChanged"
QT_MOC_LITERAL(6, 103, 25), // "landscapeDisplayedChanged"
QT_MOC_LITERAL(7, 129, 16), // "landscapeChanged"
QT_MOC_LITERAL(8, 146, 2), // "id"
QT_MOC_LITERAL(9, 149, 17), // "landscapesChanged"
QT_MOC_LITERAL(10, 167, 17), // "errorUnableToOpen"
QT_MOC_LITERAL(11, 185, 4), // "path"
QT_MOC_LITERAL(12, 190, 15), // "errorNotArchive"
QT_MOC_LITERAL(13, 206, 14), // "errorNotUnique"
QT_MOC_LITERAL(14, 221, 8), // "nameOrID"
QT_MOC_LITERAL(15, 230, 19), // "errorRemoveManually"
QT_MOC_LITERAL(16, 250, 20), // "getAllLandscapeNames"
QT_MOC_LITERAL(17, 271, 18), // "getAllLandscapeIDs"
QT_MOC_LITERAL(18, 290, 19), // "getUserLandscapeIDs"
QT_MOC_LITERAL(19, 310, 21), // "getCurrentLandscapeID"
QT_MOC_LITERAL(20, 332, 21), // "setCurrentLandscapeID"
QT_MOC_LITERAL(21, 354, 23), // "getCurrentLandscapeName"
QT_MOC_LITERAL(22, 378, 23), // "setCurrentLandscapeName"
QT_MOC_LITERAL(23, 402, 4), // "name"
QT_MOC_LITERAL(24, 407, 21), // "getDefaultLandscapeID"
QT_MOC_LITERAL(25, 429, 21), // "setDefaultLandscapeID"
QT_MOC_LITERAL(26, 451, 34), // "getCurrentLandscapeHtmlDescri..."
QT_MOC_LITERAL(27, 486, 14), // "getDescription"
QT_MOC_LITERAL(28, 501, 16), // "getFlagLandscape"
QT_MOC_LITERAL(29, 518, 16), // "setFlagLandscape"
QT_MOC_LITERAL(30, 535, 26), // "getIsLandscapeFullyVisible"
QT_MOC_LITERAL(31, 562, 10), // "getFlagFog"
QT_MOC_LITERAL(32, 573, 10), // "setFlagFog"
QT_MOC_LITERAL(33, 584, 28), // "getFlagLandscapeSetsLocation"
QT_MOC_LITERAL(34, 613, 28), // "setFlagLandscapeSetsLocation"
QT_MOC_LITERAL(35, 642, 1), // "b"
QT_MOC_LITERAL(36, 644, 31), // "getFlagLandscapeNightBrightness"
QT_MOC_LITERAL(37, 676, 31), // "setFlagLandscapeNightBrightness"
QT_MOC_LITERAL(38, 708, 22), // "getFlagCardinalsPoints"
QT_MOC_LITERAL(39, 731, 22), // "setFlagCardinalsPoints"
QT_MOC_LITERAL(40, 754, 22), // "getColorCardinalPoints"
QT_MOC_LITERAL(41, 777, 5), // "Vec3f"
QT_MOC_LITERAL(42, 783, 22), // "setColorCardinalPoints"
QT_MOC_LITERAL(43, 806, 1), // "v"
QT_MOC_LITERAL(44, 808, 17), // "getFlagAtmosphere"
QT_MOC_LITERAL(45, 826, 17), // "setFlagAtmosphere"
QT_MOC_LITERAL(46, 844, 25), // "getAtmosphereFadeDuration"
QT_MOC_LITERAL(47, 870, 25), // "setAtmosphereFadeDuration"
QT_MOC_LITERAL(48, 896, 1), // "f"
QT_MOC_LITERAL(49, 898, 33), // "setAtmosphereBortleLightPollu..."
QT_MOC_LITERAL(50, 932, 6), // "bIndex"
QT_MOC_LITERAL(51, 939, 33), // "getAtmosphereBortleLightPollu..."
QT_MOC_LITERAL(52, 973, 12), // "setZRotation"
QT_MOC_LITERAL(53, 986, 1), // "d"
QT_MOC_LITERAL(54, 988, 27), // "installLandscapeFromArchive"
QT_MOC_LITERAL(55, 1016, 19), // "pathToSourceArchive"
QT_MOC_LITERAL(56, 1036, 7), // "display"
QT_MOC_LITERAL(57, 1044, 11), // "forAllUsers"
QT_MOC_LITERAL(58, 1056, 15), // "removeLandscape"
QT_MOC_LITERAL(59, 1072, 11), // "landscapeID"
QT_MOC_LITERAL(60, 1084, 17), // "loadLandscapeName"
QT_MOC_LITERAL(61, 1102, 17), // "loadLandscapeSize"
QT_MOC_LITERAL(62, 1120, 29), // "getFlagLandscapeAutoSelection"
QT_MOC_LITERAL(63, 1150, 29), // "setFlagLandscapeAutoSelection"
QT_MOC_LITERAL(64, 1180, 16), // "enableAutoSelect"
QT_MOC_LITERAL(65, 1197, 12), // "setStelStyle"
QT_MOC_LITERAL(66, 1210, 7), // "section"
QT_MOC_LITERAL(67, 1218, 10), // "updateI18n"
QT_MOC_LITERAL(68, 1229, 29), // "getInitialLandscapeBrightness"
QT_MOC_LITERAL(69, 1259, 29), // "setInitialLandscapeBrightness"
QT_MOC_LITERAL(70, 1289, 19), // "atmosphereDisplayed"
QT_MOC_LITERAL(71, 1309, 24), // "cardinalsPointsDisplayed"
QT_MOC_LITERAL(72, 1334, 12), // "fogDisplayed"
QT_MOC_LITERAL(73, 1347, 18) // "landscapeDisplayed"

    },
    "LandscapeMgr\0atmosphereDisplayedChanged\0"
    "\0displayed\0cardinalsPointsDisplayedChanged\0"
    "fogDisplayedChanged\0landscapeDisplayedChanged\0"
    "landscapeChanged\0id\0landscapesChanged\0"
    "errorUnableToOpen\0path\0errorNotArchive\0"
    "errorNotUnique\0nameOrID\0errorRemoveManually\0"
    "getAllLandscapeNames\0getAllLandscapeIDs\0"
    "getUserLandscapeIDs\0getCurrentLandscapeID\0"
    "setCurrentLandscapeID\0getCurrentLandscapeName\0"
    "setCurrentLandscapeName\0name\0"
    "getDefaultLandscapeID\0setDefaultLandscapeID\0"
    "getCurrentLandscapeHtmlDescription\0"
    "getDescription\0getFlagLandscape\0"
    "setFlagLandscape\0getIsLandscapeFullyVisible\0"
    "getFlagFog\0setFlagFog\0"
    "getFlagLandscapeSetsLocation\0"
    "setFlagLandscapeSetsLocation\0b\0"
    "getFlagLandscapeNightBrightness\0"
    "setFlagLandscapeNightBrightness\0"
    "getFlagCardinalsPoints\0setFlagCardinalsPoints\0"
    "getColorCardinalPoints\0Vec3f\0"
    "setColorCardinalPoints\0v\0getFlagAtmosphere\0"
    "setFlagAtmosphere\0getAtmosphereFadeDuration\0"
    "setAtmosphereFadeDuration\0f\0"
    "setAtmosphereBortleLightPollution\0"
    "bIndex\0getAtmosphereBortleLightPollution\0"
    "setZRotation\0d\0installLandscapeFromArchive\0"
    "pathToSourceArchive\0display\0forAllUsers\0"
    "removeLandscape\0landscapeID\0"
    "loadLandscapeName\0loadLandscapeSize\0"
    "getFlagLandscapeAutoSelection\0"
    "setFlagLandscapeAutoSelection\0"
    "enableAutoSelect\0setStelStyle\0section\0"
    "updateI18n\0getInitialLandscapeBrightness\0"
    "setInitialLandscapeBrightness\0"
    "atmosphereDisplayed\0cardinalsPointsDisplayed\0"
    "fogDisplayed\0landscapeDisplayed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LandscapeMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       4,  398, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  279,    2, 0x06 /* Public */,
       4,    1,  282,    2, 0x06 /* Public */,
       5,    1,  285,    2, 0x06 /* Public */,
       6,    1,  288,    2, 0x06 /* Public */,
       7,    1,  291,    2, 0x06 /* Public */,
       9,    0,  294,    2, 0x06 /* Public */,
      10,    1,  295,    2, 0x06 /* Public */,
      12,    0,  298,    2, 0x06 /* Public */,
      13,    1,  299,    2, 0x06 /* Public */,
      15,    1,  302,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  305,    2, 0x0a /* Public */,
      17,    0,  306,    2, 0x0a /* Public */,
      18,    0,  307,    2, 0x0a /* Public */,
      19,    0,  308,    2, 0x0a /* Public */,
      20,    1,  309,    2, 0x0a /* Public */,
      21,    0,  312,    2, 0x0a /* Public */,
      22,    1,  313,    2, 0x0a /* Public */,
      24,    0,  316,    2, 0x0a /* Public */,
      25,    1,  317,    2, 0x0a /* Public */,
      26,    0,  320,    2, 0x0a /* Public */,
      27,    0,  321,    2, 0x0a /* Public */,
      28,    0,  322,    2, 0x0a /* Public */,
      29,    1,  323,    2, 0x0a /* Public */,
      30,    0,  326,    2, 0x0a /* Public */,
      31,    0,  327,    2, 0x0a /* Public */,
      32,    1,  328,    2, 0x0a /* Public */,
      33,    0,  331,    2, 0x0a /* Public */,
      34,    1,  332,    2, 0x0a /* Public */,
      36,    0,  335,    2, 0x0a /* Public */,
      37,    1,  336,    2, 0x0a /* Public */,
      38,    0,  339,    2, 0x0a /* Public */,
      39,    1,  340,    2, 0x0a /* Public */,
      40,    0,  343,    2, 0x0a /* Public */,
      42,    1,  344,    2, 0x0a /* Public */,
      44,    0,  347,    2, 0x0a /* Public */,
      45,    1,  348,    2, 0x0a /* Public */,
      46,    0,  351,    2, 0x0a /* Public */,
      47,    1,  352,    2, 0x0a /* Public */,
      49,    1,  355,    2, 0x0a /* Public */,
      51,    0,  358,    2, 0x0a /* Public */,
      52,    1,  359,    2, 0x0a /* Public */,
      54,    3,  362,    2, 0x0a /* Public */,
      54,    2,  369,    2, 0x2a /* Public | MethodCloned */,
      54,    1,  374,    2, 0x2a /* Public | MethodCloned */,
      58,    1,  377,    2, 0x0a /* Public */,
      60,    1,  380,    2, 0x0a /* Public */,
      61,    1,  383,    2, 0x0a /* Public */,
      62,    0,  386,    2, 0x0a /* Public */,
      63,    1,  387,    2, 0x0a /* Public */,
      65,    1,  390,    2, 0x08 /* Private */,
      67,    0,  393,    2, 0x08 /* Private */,
      68,    0,  394,    2, 0x08 /* Private */,
      69,    1,  395,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    3,
    0x80000000 | 41,
    QMetaType::Void, 0x80000000 | 41,   43,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Float,   48,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Float,   53,
    QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   55,   56,   57,
    QMetaType::QString, QMetaType::QString, QMetaType::Bool,   55,   56,
    QMetaType::QString, QMetaType::QString,   55,
    QMetaType::Bool, QMetaType::QString,   59,
    QMetaType::QString, QMetaType::QString,   59,
    QMetaType::ULongLong, QMetaType::QString,   59,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   64,
    QMetaType::Void, QMetaType::QString,   66,
    QMetaType::Void,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Float,   35,

 // properties: name, type, flags
      70, QMetaType::Bool, 0x00495003,
      71, QMetaType::Bool, 0x00495003,
      72, QMetaType::Bool, 0x00495003,
      73, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void LandscapeMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LandscapeMgr *_t = static_cast<LandscapeMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->atmosphereDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->cardinalsPointsDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 2: _t->fogDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 3: _t->landscapeDisplayedChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->landscapeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->landscapesChanged(); break;
        case 6: _t->errorUnableToOpen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->errorNotArchive(); break;
        case 8: _t->errorNotUnique((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->errorRemoveManually((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: { QStringList _r = _t->getAllLandscapeNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 11: { QStringList _r = _t->getAllLandscapeIDs();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 12: { QStringList _r = _t->getUserLandscapeIDs();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 13: _t->getCurrentLandscapeID(); break;
        case 14: { bool _r = _t->setCurrentLandscapeID((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { QString _r = _t->getCurrentLandscapeName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->setCurrentLandscapeName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: _t->getDefaultLandscapeID(); break;
        case 18: { bool _r = _t->setDefaultLandscapeID((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { QString _r = _t->getCurrentLandscapeHtmlDescription();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 20: { QString _r = _t->getDescription();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 21: { bool _r = _t->getFlagLandscape();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: _t->setFlagLandscape((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 23: { bool _r = _t->getIsLandscapeFullyVisible();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: { bool _r = _t->getFlagFog();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 25: _t->setFlagFog((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 26: { bool _r = _t->getFlagLandscapeSetsLocation();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 27: _t->setFlagLandscapeSetsLocation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: { bool _r = _t->getFlagLandscapeNightBrightness();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: _t->setFlagLandscapeNightBrightness((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: { bool _r = _t->getFlagCardinalsPoints();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 31: _t->setFlagCardinalsPoints((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 32: { Vec3f _r = _t->getColorCardinalPoints();
            if (_a[0]) *reinterpret_cast< Vec3f*>(_a[0]) = _r; }  break;
        case 33: _t->setColorCardinalPoints((*reinterpret_cast< const Vec3f(*)>(_a[1]))); break;
        case 34: { bool _r = _t->getFlagAtmosphere();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 35: _t->setFlagAtmosphere((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 36: { float _r = _t->getAtmosphereFadeDuration();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 37: _t->setAtmosphereFadeDuration((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 38: _t->setAtmosphereBortleLightPollution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: { int _r = _t->getAtmosphereBortleLightPollution();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 40: _t->setZRotation((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 41: { QString _r = _t->installLandscapeFromArchive((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 42: { QString _r = _t->installLandscapeFromArchive((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 43: { QString _r = _t->installLandscapeFromArchive((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 44: { bool _r = _t->removeLandscape((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 45: { QString _r = _t->loadLandscapeName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 46: { quint64 _r = _t->loadLandscapeSize((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint64*>(_a[0]) = _r; }  break;
        case 47: { bool _r = _t->getFlagLandscapeAutoSelection();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 48: _t->setFlagLandscapeAutoSelection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->setStelStyle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 50: _t->updateI18n(); break;
        case 51: { float _r = _t->getInitialLandscapeBrightness();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 52: _t->setInitialLandscapeBrightness((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LandscapeMgr::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::atmosphereDisplayedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::cardinalsPointsDisplayedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::fogDisplayedChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)(const bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::landscapeDisplayedChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::landscapeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::landscapesChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::errorUnableToOpen)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::errorNotArchive)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::errorNotUnique)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (LandscapeMgr::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LandscapeMgr::errorRemoveManually)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        LandscapeMgr *_t = static_cast<LandscapeMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getFlagAtmosphere(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getFlagCardinalsPoints(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getFlagFog(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->getFlagLandscape(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        LandscapeMgr *_t = static_cast<LandscapeMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFlagAtmosphere(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setFlagCardinalsPoints(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setFlagFog(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setFlagLandscape(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject LandscapeMgr::staticMetaObject = {
    { &StelModule::staticMetaObject, qt_meta_stringdata_LandscapeMgr.data,
      qt_meta_data_LandscapeMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LandscapeMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LandscapeMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LandscapeMgr.stringdata0))
        return static_cast<void*>(const_cast< LandscapeMgr*>(this));
    return StelModule::qt_metacast(_clname);
}

int LandscapeMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StelModule::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 53)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 53;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LandscapeMgr::atmosphereDisplayedChanged(const bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LandscapeMgr::cardinalsPointsDisplayedChanged(const bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LandscapeMgr::fogDisplayedChanged(const bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LandscapeMgr::landscapeDisplayedChanged(const bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LandscapeMgr::landscapeChanged(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LandscapeMgr::landscapesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void LandscapeMgr::errorUnableToOpen(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void LandscapeMgr::errorNotArchive()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void LandscapeMgr::errorNotUnique(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void LandscapeMgr::errorRemoveManually(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
