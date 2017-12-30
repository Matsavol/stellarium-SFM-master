/****************************************************************************
** Meta object code from reading C++ file 'StelQuickStelItem.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/StelQuickStelItem.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelQuickStelItem.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainThreadProxy_t {
    QByteArrayData data[10];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainThreadProxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainThreadProxy_t qt_meta_stringdata_MainThreadProxy = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MainThreadProxy"
QT_MOC_LITERAL(1, 16, 21), // "setCurrentLandscapeID"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "value"
QT_MOC_LITERAL(4, 45, 23), // "setCurrentLandscapeName"
QT_MOC_LITERAL(5, 69, 11), // "setLocation"
QT_MOC_LITERAL(6, 81, 10), // "locationId"
QT_MOC_LITERAL(7, 92, 17), // "setManualPosition"
QT_MOC_LITERAL(8, 110, 8), // "latitude"
QT_MOC_LITERAL(9, 119, 9) // "longitude"

    },
    "MainThreadProxy\0setCurrentLandscapeID\0"
    "\0value\0setCurrentLandscapeName\0"
    "setLocation\0locationId\0setManualPosition\0"
    "latitude\0longitude"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainThreadProxy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x02 /* Public */,
       4,    1,   37,    2, 0x02 /* Public */,
       5,    1,   40,    2, 0x02 /* Public */,
       7,    2,   43,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    8,    9,

       0        // eod
};

void MainThreadProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainThreadProxy *_t = static_cast<MainThreadProxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCurrentLandscapeID((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setCurrentLandscapeName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setLocation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setManualPosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainThreadProxy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainThreadProxy.data,
      qt_meta_data_MainThreadProxy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainThreadProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainThreadProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainThreadProxy.stringdata0))
        return static_cast<void*>(const_cast< MainThreadProxy*>(this));
    return QObject::qt_metacast(_clname);
}

int MainThreadProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_StelQuickStelItem_t {
    QByteArrayData data[75];
    char stringdata0[1046];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelQuickStelItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelQuickStelItem_t qt_meta_stringdata_StelQuickStelItem = {
    {
QT_MOC_LITERAL(0, 0, 17), // "StelQuickStelItem"
QT_MOC_LITERAL(1, 18, 7), // "clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "timeChanged"
QT_MOC_LITERAL(4, 39, 15), // "timeRateChanged"
QT_MOC_LITERAL(5, 55, 21), // "selectedObjectChanged"
QT_MOC_LITERAL(6, 77, 25), // "selectedObjectInfoChanged"
QT_MOC_LITERAL(7, 103, 30), // "selectedObjectShortInfoChanged"
QT_MOC_LITERAL(8, 134, 19), // "trackingModeChanged"
QT_MOC_LITERAL(9, 154, 19), // "dragTimeModeChanged"
QT_MOC_LITERAL(10, 174, 15), // "draggingChanged"
QT_MOC_LITERAL(11, 190, 23), // "currentLandscapeChanged"
QT_MOC_LITERAL(12, 214, 24), // "currentSkyCultureChanged"
QT_MOC_LITERAL(13, 239, 31), // "currentSkyCultureBaseUrlChanged"
QT_MOC_LITERAL(14, 271, 15), // "positionChanged"
QT_MOC_LITERAL(15, 287, 21), // "guiScaleFactorChanged"
QT_MOC_LITERAL(16, 309, 15), // "gpsStateChanged"
QT_MOC_LITERAL(17, 325, 21), // "lightPollutionChanged"
QT_MOC_LITERAL(18, 347, 25), // "milkyWayBrightnessChanged"
QT_MOC_LITERAL(19, 373, 21), // "LinesThicknessChanged"
QT_MOC_LITERAL(20, 395, 6), // "update"
QT_MOC_LITERAL(21, 402, 14), // "unselectObject"
QT_MOC_LITERAL(22, 417, 4), // "zoom"
QT_MOC_LITERAL(23, 422, 9), // "direction"
QT_MOC_LITERAL(24, 432, 5), // "pinch"
QT_MOC_LITERAL(25, 438, 5), // "scale"
QT_MOC_LITERAL(26, 444, 7), // "started"
QT_MOC_LITERAL(27, 452, 5), // "touch"
QT_MOC_LITERAL(28, 458, 5), // "state"
QT_MOC_LITERAL(29, 464, 1), // "x"
QT_MOC_LITERAL(30, 466, 1), // "y"
QT_MOC_LITERAL(31, 468, 5), // "setJd"
QT_MOC_LITERAL(32, 474, 5), // "value"
QT_MOC_LITERAL(33, 480, 17), // "getLandscapeNames"
QT_MOC_LITERAL(34, 498, 20), // "getSkyCultureListI18"
QT_MOC_LITERAL(35, 519, 15), // "getCountryNames"
QT_MOC_LITERAL(36, 535, 12), // "getCityNames"
QT_MOC_LITERAL(37, 548, 7), // "country"
QT_MOC_LITERAL(38, 556, 17), // "setManualPosition"
QT_MOC_LITERAL(39, 574, 8), // "latitude"
QT_MOC_LITERAL(40, 583, 9), // "longitude"
QT_MOC_LITERAL(41, 593, 12), // "writeSetting"
QT_MOC_LITERAL(42, 606, 3), // "key"
QT_MOC_LITERAL(43, 610, 6), // "search"
QT_MOC_LITERAL(44, 617, 4), // "name"
QT_MOC_LITERAL(45, 622, 10), // "gotoObject"
QT_MOC_LITERAL(46, 633, 10), // "objectName"
QT_MOC_LITERAL(47, 644, 5), // "isDay"
QT_MOC_LITERAL(48, 650, 13), // "resetSettings"
QT_MOC_LITERAL(49, 664, 13), // "forwardClicks"
QT_MOC_LITERAL(50, 678, 18), // "selectedObjectName"
QT_MOC_LITERAL(51, 697, 23), // "selectedObjectShortInfo"
QT_MOC_LITERAL(52, 721, 18), // "selectedObjectInfo"
QT_MOC_LITERAL(53, 740, 8), // "tracking"
QT_MOC_LITERAL(54, 749, 2), // "jd"
QT_MOC_LITERAL(55, 752, 12), // "dragTimeMode"
QT_MOC_LITERAL(56, 765, 8), // "timeRate"
QT_MOC_LITERAL(57, 774, 13), // "printableTime"
QT_MOC_LITERAL(58, 788, 3), // "fps"
QT_MOC_LITERAL(59, 792, 20), // "currentLandscapeName"
QT_MOC_LITERAL(60, 813, 31), // "currentLandscapeHtmlDescription"
QT_MOC_LITERAL(61, 845, 20), // "currentSkyCultureI18"
QT_MOC_LITERAL(62, 866, 32), // "currentSkyCultureHtmlDescription"
QT_MOC_LITERAL(63, 899, 24), // "currentSkyCultureBaseUrl"
QT_MOC_LITERAL(64, 924, 8), // "location"
QT_MOC_LITERAL(65, 933, 14), // "guiScaleFactor"
QT_MOC_LITERAL(66, 948, 3), // "fov"
QT_MOC_LITERAL(67, 952, 7), // "version"
QT_MOC_LITERAL(68, 960, 5), // "model"
QT_MOC_LITERAL(69, 966, 13), // "autoGotoNight"
QT_MOC_LITERAL(70, 980, 7), // "desktop"
QT_MOC_LITERAL(71, 988, 8), // "gpsState"
QT_MOC_LITERAL(72, 997, 14), // "lightPollution"
QT_MOC_LITERAL(73, 1012, 18), // "milkyWayBrightness"
QT_MOC_LITERAL(74, 1031, 14) // "linesThickness"

    },
    "StelQuickStelItem\0clicked\0\0timeChanged\0"
    "timeRateChanged\0selectedObjectChanged\0"
    "selectedObjectInfoChanged\0"
    "selectedObjectShortInfoChanged\0"
    "trackingModeChanged\0dragTimeModeChanged\0"
    "draggingChanged\0currentLandscapeChanged\0"
    "currentSkyCultureChanged\0"
    "currentSkyCultureBaseUrlChanged\0"
    "positionChanged\0guiScaleFactorChanged\0"
    "gpsStateChanged\0lightPollutionChanged\0"
    "milkyWayBrightnessChanged\0"
    "LinesThicknessChanged\0update\0"
    "unselectObject\0zoom\0direction\0pinch\0"
    "scale\0started\0touch\0state\0x\0y\0setJd\0"
    "value\0getLandscapeNames\0getSkyCultureListI18\0"
    "getCountryNames\0getCityNames\0country\0"
    "setManualPosition\0latitude\0longitude\0"
    "writeSetting\0key\0search\0name\0gotoObject\0"
    "objectName\0isDay\0resetSettings\0"
    "forwardClicks\0selectedObjectName\0"
    "selectedObjectShortInfo\0selectedObjectInfo\0"
    "tracking\0jd\0dragTimeMode\0timeRate\0"
    "printableTime\0fps\0currentLandscapeName\0"
    "currentLandscapeHtmlDescription\0"
    "currentSkyCultureI18\0"
    "currentSkyCultureHtmlDescription\0"
    "currentSkyCultureBaseUrl\0location\0"
    "guiScaleFactor\0fov\0version\0model\0"
    "autoGotoNight\0desktop\0gpsState\0"
    "lightPollution\0milkyWayBrightness\0"
    "linesThickness"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelQuickStelItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
      28,  246, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  184,    2, 0x06 /* Public */,
       3,    0,  185,    2, 0x06 /* Public */,
       4,    0,  186,    2, 0x06 /* Public */,
       5,    0,  187,    2, 0x06 /* Public */,
       6,    0,  188,    2, 0x06 /* Public */,
       7,    0,  189,    2, 0x06 /* Public */,
       8,    0,  190,    2, 0x06 /* Public */,
       9,    0,  191,    2, 0x06 /* Public */,
      10,    0,  192,    2, 0x06 /* Public */,
      11,    0,  193,    2, 0x06 /* Public */,
      12,    0,  194,    2, 0x06 /* Public */,
      13,    0,  195,    2, 0x06 /* Public */,
      14,    0,  196,    2, 0x06 /* Public */,
      15,    0,  197,    2, 0x06 /* Public */,
      16,    0,  198,    2, 0x06 /* Public */,
      17,    0,  199,    2, 0x06 /* Public */,
      18,    0,  200,    2, 0x06 /* Public */,
      19,    0,  201,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,  202,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      21,    0,  203,    2, 0x02 /* Public */,
      22,    1,  204,    2, 0x02 /* Public */,
      24,    2,  207,    2, 0x02 /* Public */,
      27,    3,  212,    2, 0x02 /* Public */,
      31,    1,  219,    2, 0x02 /* Public */,
      33,    0,  222,    2, 0x02 /* Public */,
      34,    0,  223,    2, 0x02 /* Public */,
      35,    0,  224,    2, 0x02 /* Public */,
      36,    1,  225,    2, 0x02 /* Public */,
      38,    2,  228,    2, 0x02 /* Public */,
      41,    2,  233,    2, 0x02 /* Public */,
      43,    1,  238,    2, 0x02 /* Public */,
      45,    1,  241,    2, 0x02 /* Public */,
      47,    0,  244,    2, 0x02 /* Public */,
      48,    0,  245,    2, 0x02 /* Public */,

 // signals: parameters
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

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Float, QMetaType::Bool,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float,   28,   29,   30,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::QStringList, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   39,   40,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   42,   32,
    QMetaType::QStringList, QMetaType::QString,   44,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Bool,
    QMetaType::Void,

 // properties: name, type, flags
      49, QMetaType::Bool, 0x00095103,
      50, QMetaType::QString, 0x00495001,
      51, QMetaType::QString, 0x00495001,
      52, QMetaType::QString, 0x00495001,
      53, QMetaType::Bool, 0x00495001,
      54, QMetaType::Double, 0x00495103,
      55, QMetaType::Bool, 0x00495103,
      56, QMetaType::Double, 0x00495103,
      57, QMetaType::QString, 0x00495001,
      58, QMetaType::Int, 0x00495001,
      59, QMetaType::QString, 0x00495103,
      60, QMetaType::QString, 0x00495001,
      61, QMetaType::QString, 0x00495103,
      62, QMetaType::QString, 0x00495001,
      63, QMetaType::QString, 0x00495001,
      64, QMetaType::QString, 0x00495103,
      39, QMetaType::Double, 0x00495001,
      40, QMetaType::Double, 0x00495001,
      65, QMetaType::Float, 0x00495001,
      66, QMetaType::Float, 0x00495001,
      67, QMetaType::QString, 0x00095401,
      68, QMetaType::QString, 0x00095401,
      69, QMetaType::Bool, 0x00095103,
      70, QMetaType::Bool, 0x00095401,
      71, QMetaType::QString, 0x00495001,
      72, QMetaType::Int, 0x00495103,
      73, QMetaType::Int, 0x00495103,
      74, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       3,
       5,
       4,
       6,
       1,
       7,
       2,
       1,
       1,
       9,
       9,
      10,
      10,
      11,
      12,
      12,
      12,
      13,
       1,
       0,
       0,
       0,
       0,
      14,
      15,
      16,
      17,

       0        // eod
};

void StelQuickStelItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelQuickStelItem *_t = static_cast<StelQuickStelItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->timeChanged(); break;
        case 2: _t->timeRateChanged(); break;
        case 3: _t->selectedObjectChanged(); break;
        case 4: _t->selectedObjectInfoChanged(); break;
        case 5: _t->selectedObjectShortInfoChanged(); break;
        case 6: _t->trackingModeChanged(); break;
        case 7: _t->dragTimeModeChanged(); break;
        case 8: _t->draggingChanged(); break;
        case 9: _t->currentLandscapeChanged(); break;
        case 10: _t->currentSkyCultureChanged(); break;
        case 11: _t->currentSkyCultureBaseUrlChanged(); break;
        case 12: _t->positionChanged(); break;
        case 13: _t->guiScaleFactorChanged(); break;
        case 14: _t->gpsStateChanged(); break;
        case 15: _t->lightPollutionChanged(); break;
        case 16: _t->milkyWayBrightnessChanged(); break;
        case 17: _t->LinesThicknessChanged(); break;
        case 18: _t->update(); break;
        case 19: _t->unselectObject(); break;
        case 20: _t->zoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->pinch((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 22: _t->touch((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 23: _t->setJd((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: { QStringList _r = _t->getLandscapeNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 25: { QStringList _r = _t->getSkyCultureListI18();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 26: { QStringList _r = _t->getCountryNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 27: { QStringList _r = _t->getCityNames((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 28: _t->setManualPosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 29: _t->writeSetting((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: { QStringList _r = _t->search((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 31: _t->gotoObject((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: { bool _r = _t->isDay();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 33: _t->resetSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::timeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::timeRateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::selectedObjectChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::selectedObjectInfoChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::selectedObjectShortInfoChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::trackingModeChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::dragTimeModeChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::draggingChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::currentLandscapeChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::currentSkyCultureChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::currentSkyCultureBaseUrlChanged)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::positionChanged)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::guiScaleFactorChanged)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::gpsStateChanged)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::lightPollutionChanged)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::milkyWayBrightnessChanged)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (StelQuickStelItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickStelItem::LinesThicknessChanged)) {
                *result = 17;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StelQuickStelItem *_t = static_cast<StelQuickStelItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getForwardClicks(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getSelectedObjectName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getSelectedObjectShortInfo(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getSelectedObjectInfo(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getTracking(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->getJd(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->getDragTimeMode(); break;
        case 7: *reinterpret_cast< double*>(_v) = _t->getTimeRate(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->getPrintableTime(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getFps(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->getCurrentLandscapeName(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->getCurrentLandscapeHtmlDescription(); break;
        case 12: *reinterpret_cast< QString*>(_v) = _t->getCurrentSkyCultureI18(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->getCurrentSkyCultureHtmlDescription(); break;
        case 14: *reinterpret_cast< QString*>(_v) = _t->getCurrentSkyCultureBaseUrl(); break;
        case 15: *reinterpret_cast< QString*>(_v) = _t->getLocation(); break;
        case 16: *reinterpret_cast< double*>(_v) = _t->getLatitude(); break;
        case 17: *reinterpret_cast< double*>(_v) = _t->getLongitude(); break;
        case 18: *reinterpret_cast< float*>(_v) = _t->getGuiScaleFactor(); break;
        case 19: *reinterpret_cast< float*>(_v) = _t->getFov(); break;
        case 20: *reinterpret_cast< QString*>(_v) = _t->getVersion(); break;
        case 21: *reinterpret_cast< QString*>(_v) = _t->getModel(); break;
        case 22: *reinterpret_cast< bool*>(_v) = _t->getAutoGotoNight(); break;
        case 23: *reinterpret_cast< bool*>(_v) = _t->isDesktop(); break;
        case 24: *reinterpret_cast< QString*>(_v) = _t->getGpsState(); break;
        case 25: *reinterpret_cast< int*>(_v) = _t->getLightPollution(); break;
        case 26: *reinterpret_cast< int*>(_v) = _t->getMilkyWayBrightness(); break;
        case 27: *reinterpret_cast< int*>(_v) = _t->getLinesThickness(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StelQuickStelItem *_t = static_cast<StelQuickStelItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setForwardClicks(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setJd(*reinterpret_cast< double*>(_v)); break;
        case 6: _t->setDragTimeMode(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setTimeRate(*reinterpret_cast< double*>(_v)); break;
        case 10: _t->setCurrentLandscapeName(*reinterpret_cast< QString*>(_v)); break;
        case 12: _t->setCurrentSkyCultureI18(*reinterpret_cast< QString*>(_v)); break;
        case 15: _t->setLocation(*reinterpret_cast< QString*>(_v)); break;
        case 22: _t->setAutoGotoNight(*reinterpret_cast< bool*>(_v)); break;
        case 25: _t->setLightPollution(*reinterpret_cast< int*>(_v)); break;
        case 26: _t->setMilkyWayBrightness(*reinterpret_cast< int*>(_v)); break;
        case 27: _t->setLinesThickness(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject StelQuickStelItem::staticMetaObject = {
    { &QQuickItem::staticMetaObject, qt_meta_stringdata_StelQuickStelItem.data,
      qt_meta_data_StelQuickStelItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelQuickStelItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelQuickStelItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelQuickStelItem.stringdata0))
        return static_cast<void*>(const_cast< StelQuickStelItem*>(this));
    return QQuickItem::qt_metacast(_clname);
}

int StelQuickStelItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 34;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 28;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 28;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 28;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 28;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 28;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void StelQuickStelItem::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void StelQuickStelItem::timeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void StelQuickStelItem::timeRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void StelQuickStelItem::selectedObjectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void StelQuickStelItem::selectedObjectInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void StelQuickStelItem::selectedObjectShortInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void StelQuickStelItem::trackingModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void StelQuickStelItem::dragTimeModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void StelQuickStelItem::draggingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void StelQuickStelItem::currentLandscapeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void StelQuickStelItem::currentSkyCultureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void StelQuickStelItem::currentSkyCultureBaseUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void StelQuickStelItem::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void StelQuickStelItem::guiScaleFactorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}

// SIGNAL 14
void StelQuickStelItem::gpsStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void StelQuickStelItem::lightPollutionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void StelQuickStelItem::milkyWayBrightnessChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, Q_NULLPTR);
}

// SIGNAL 17
void StelQuickStelItem::LinesThicknessChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
