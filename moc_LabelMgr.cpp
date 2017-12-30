/****************************************************************************
** Meta object code from reading C++ file 'LabelMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/modules/LabelMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LabelMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LabelMgr_t {
    QByteArrayData data[22];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LabelMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LabelMgr_t qt_meta_stringdata_LabelMgr = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LabelMgr"
QT_MOC_LITERAL(1, 9, 11), // "labelObject"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "text"
QT_MOC_LITERAL(4, 27, 10), // "objectName"
QT_MOC_LITERAL(5, 38, 7), // "visible"
QT_MOC_LITERAL(6, 46, 8), // "fontSize"
QT_MOC_LITERAL(7, 55, 9), // "fontColor"
QT_MOC_LITERAL(8, 65, 4), // "side"
QT_MOC_LITERAL(9, 70, 13), // "labelDistance"
QT_MOC_LITERAL(10, 84, 5), // "style"
QT_MOC_LITERAL(11, 90, 11), // "labelScreen"
QT_MOC_LITERAL(12, 102, 1), // "x"
QT_MOC_LITERAL(13, 104, 1), // "y"
QT_MOC_LITERAL(14, 106, 12), // "getLabelShow"
QT_MOC_LITERAL(15, 119, 2), // "id"
QT_MOC_LITERAL(16, 122, 12), // "setLabelShow"
QT_MOC_LITERAL(17, 135, 4), // "show"
QT_MOC_LITERAL(18, 140, 12), // "setLabelText"
QT_MOC_LITERAL(19, 153, 7), // "newText"
QT_MOC_LITERAL(20, 161, 11), // "deleteLabel"
QT_MOC_LITERAL(21, 173, 15) // "deleteAllLabels"

    },
    "LabelMgr\0labelObject\0\0text\0objectName\0"
    "visible\0fontSize\0fontColor\0side\0"
    "labelDistance\0style\0labelScreen\0x\0y\0"
    "getLabelShow\0id\0setLabelShow\0show\0"
    "setLabelText\0newText\0deleteLabel\0"
    "deleteAllLabels"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabelMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    8,   94,    2, 0x0a /* Public */,
       1,    7,  111,    2, 0x2a /* Public | MethodCloned */,
       1,    6,  126,    2, 0x2a /* Public | MethodCloned */,
       1,    5,  139,    2, 0x2a /* Public | MethodCloned */,
       1,    4,  150,    2, 0x2a /* Public | MethodCloned */,
       1,    3,  159,    2, 0x2a /* Public | MethodCloned */,
       1,    2,  166,    2, 0x2a /* Public | MethodCloned */,
      11,    6,  171,    2, 0x0a /* Public */,
      11,    5,  184,    2, 0x2a /* Public | MethodCloned */,
      11,    4,  195,    2, 0x2a /* Public | MethodCloned */,
      11,    3,  204,    2, 0x2a /* Public | MethodCloned */,
      14,    1,  211,    2, 0x0a /* Public */,
      16,    2,  214,    2, 0x0a /* Public */,
      18,    2,  219,    2, 0x0a /* Public */,
      20,    1,  224,    2, 0x0a /* Public */,
      21,    0,  227,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Float, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Float, QMetaType::QString, QMetaType::QString, QMetaType::Double,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Float, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Float, QMetaType::QString,    3,    4,    5,    6,    7,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Float,    3,    4,    5,    6,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,    4,    5,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Float, QMetaType::QString,    3,   12,   13,    5,    6,    7,
    QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Float,    3,   12,   13,    5,    6,
    QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    3,   12,   13,    5,
    QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,   12,   13,
    QMetaType::Bool, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   15,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   15,   19,
    QMetaType::Bool, QMetaType::Int,   15,
    QMetaType::Int,

       0        // eod
};

void LabelMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LabelMgr *_t = static_cast<LabelMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->labelObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->labelObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->labelObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->labelObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->labelObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->labelObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->labelObject((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->labelScreen((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = _t->labelScreen((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->labelScreen((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->labelScreen((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->getLabelShow((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: _t->setLabelShow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->setLabelText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 14: { bool _r = _t->deleteLabel((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { int _r = _t->deleteAllLabels();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject LabelMgr::staticMetaObject = {
    { &StelModule::staticMetaObject, qt_meta_stringdata_LabelMgr.data,
      qt_meta_data_LabelMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LabelMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabelMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LabelMgr.stringdata0))
        return static_cast<void*>(const_cast< LabelMgr*>(this));
    return StelModule::qt_metacast(_clname);
}

int LabelMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = StelModule::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
