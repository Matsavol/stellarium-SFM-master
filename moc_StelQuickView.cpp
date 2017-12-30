/****************************************************************************
** Meta object code from reading C++ file 'StelQuickView.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/StelQuickView.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StelQuickView.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QmlGuiActionItem_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QmlGuiActionItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QmlGuiActionItem_t qt_meta_stringdata_QmlGuiActionItem = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QmlGuiActionItem"
QT_MOC_LITERAL(1, 17, 7), // "changed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "trigger"
QT_MOC_LITERAL(4, 34, 6), // "action"
QT_MOC_LITERAL(5, 41, 7), // "checked"
QT_MOC_LITERAL(6, 49, 9), // "checkable"
QT_MOC_LITERAL(7, 59, 4) // "text"

    },
    "QmlGuiActionItem\0changed\0\0trigger\0"
    "action\0checked\0checkable\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QmlGuiActionItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       4,   26, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00095103,
       5, QMetaType::Bool, 0x00495103,
       6, QMetaType::Bool, 0x00495001,
       7, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

void QmlGuiActionItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QmlGuiActionItem *_t = static_cast<QmlGuiActionItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changed(); break;
        case 1: _t->trigger(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QmlGuiActionItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QmlGuiActionItem::changed)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QmlGuiActionItem *_t = static_cast<QmlGuiActionItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getAction(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isChecked(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isCheckable(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getText(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QmlGuiActionItem *_t = static_cast<QmlGuiActionItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAction(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setChecked(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject QmlGuiActionItem::staticMetaObject = {
    { &QQuickItem::staticMetaObject, qt_meta_stringdata_QmlGuiActionItem.data,
      qt_meta_data_QmlGuiActionItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QmlGuiActionItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmlGuiActionItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QmlGuiActionItem.stringdata0))
        return static_cast<void*>(const_cast< QmlGuiActionItem*>(this));
    return QQuickItem::qt_metacast(_clname);
}

int QmlGuiActionItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
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
void QmlGuiActionItem::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_StelQuickView_t {
    QByteArrayData data[11];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StelQuickView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StelQuickView_t qt_meta_stringdata_StelQuickView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "StelQuickView"
QT_MOC_LITERAL(1, 14, 11), // "initialized"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "nightModeChanged"
QT_MOC_LITERAL(4, 44, 12), // "handleResize"
QT_MOC_LITERAL(5, 57, 5), // "paint"
QT_MOC_LITERAL(6, 63, 14), // "afterRendering"
QT_MOC_LITERAL(7, 78, 11), // "synchronize"
QT_MOC_LITERAL(8, 90, 7), // "showGui"
QT_MOC_LITERAL(9, 98, 11), // "requestQuit"
QT_MOC_LITERAL(10, 110, 9) // "nightMode"

    },
    "StelQuickView\0initialized\0\0nightModeChanged\0"
    "handleResize\0paint\0afterRendering\0"
    "synchronize\0showGui\0requestQuit\0"
    "nightMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StelQuickView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   58,    2, 0x09 /* Protected */,
       5,    0,   59,    2, 0x09 /* Protected */,
       6,    0,   60,    2, 0x09 /* Protected */,
       7,    0,   61,    2, 0x09 /* Protected */,
       8,    0,   62,    2, 0x09 /* Protected */,
       9,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

void StelQuickView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StelQuickView *_t = static_cast<StelQuickView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initialized(); break;
        case 1: _t->nightModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->handleResize(); break;
        case 3: _t->paint(); break;
        case 4: _t->afterRendering(); break;
        case 5: _t->synchronize(); break;
        case 6: _t->showGui(); break;
        case 7: _t->requestQuit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StelQuickView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickView::initialized)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (StelQuickView::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StelQuickView::nightModeChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        StelQuickView *_t = static_cast<StelQuickView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getNightMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        StelQuickView *_t = static_cast<StelQuickView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNightMode(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject StelQuickView::staticMetaObject = {
    { &QQuickView::staticMetaObject, qt_meta_stringdata_StelQuickView.data,
      qt_meta_data_StelQuickView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StelQuickView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StelQuickView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StelQuickView.stringdata0))
        return static_cast<void*>(const_cast< StelQuickView*>(this));
    return QQuickView::qt_metacast(_clname);
}

int StelQuickView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickView::qt_metacall(_c, _id, _a);
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
void StelQuickView::initialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void StelQuickView::nightModeChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
