/****************************************************************************
** Meta object code from reading C++ file 'StelActionMgr.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/core/StelActionMgr.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelActionMgr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StelAction_t {
    QByteArrayData data[11];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelAction_t qt_meta_stringdata_StelAction = {
    {
QT_MOC_LITERAL(0, 0, 10), // "StelAction"
QT_MOC_LITERAL(1, 11, 7), // "toggled"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "triggered"
QT_MOC_LITERAL(4, 30, 7), // "changed"
QT_MOC_LITERAL(5, 38, 10), // "setChecked"
QT_MOC_LITERAL(6, 49, 7), // "trigger"
QT_MOC_LITERAL(7, 57, 6), // "toggle"
QT_MOC_LITERAL(8, 64, 15), // "propertyChanged"
QT_MOC_LITERAL(9, 80, 8), // "reparent"
QT_MOC_LITERAL(10, 89, 7) // "checked"

    },
    "StelAction\0toggled\0\0triggered\0changed\0"
    "setChecked\0trigger\0toggle\0propertyChanged\0"
    "reparent\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    0,   57,    2, 0x06 /* Public */,
       4,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   59,    2, 0x0a /* Public */,
       6,    0,   62,    2, 0x0a /* Public */,
       7,    0,   63,    2, 0x0a /* Public */,
       8,    1,   64,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       9,    0,   67,    2, 0x00 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void StelAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelAction *_t = static_cast<StelAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->triggered(); break;
        case 2: _t->changed(); break;
        case 3: _t->setChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->trigger(); break;
        case 5: _t->toggle(); break;
        case 6: _t->propertyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->reparent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StelAction::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelAction::toggled)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (StelAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelAction::triggered)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (StelAction::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelAction::changed)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StelAction *_t = static_cast<StelAction *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isChecked(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StelAction *_t = static_cast<StelAction *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setChecked(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject StelAction::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StelAction.data,
      qt_meta_data_StelAction,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelAction::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelAction.stringdata0))
        return static_cast<void*>(const_cast< StelAction*>(this));
    return QObject::qt_metacast(_clname);
}

int StelAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
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

// SIGNAL 0
void StelAction::toggled(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StelAction::triggered()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void StelAction::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
struct qt_meta_stringdata_StelActionMgr_t {
    QByteArrayData data[4];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelActionMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelActionMgr_t qt_meta_stringdata_StelActionMgr = {
    {
QT_MOC_LITERAL(0, 0, 13), // "StelActionMgr"
QT_MOC_LITERAL(1, 14, 20), // "setAllActionsEnabled"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5) // "value"

    },
    "StelActionMgr\0setAllActionsEnabled\0\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelActionMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void StelActionMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelActionMgr *_t = static_cast<StelActionMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setAllActionsEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject StelActionMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StelActionMgr.data,
      qt_meta_data_StelActionMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelActionMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelActionMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelActionMgr.stringdata0))
        return static_cast<void*>(const_cast< StelActionMgr*>(this));
    return QObject::qt_metacast(_clname);
}

int StelActionMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
