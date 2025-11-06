/****************************************************************************
** Meta object code from reading C++ file 'CurrentSource.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../CurrentSource.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurrentSource.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CurrentSource_t {
    QByteArrayData data[11];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurrentSource_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurrentSource_t qt_meta_stringdata_CurrentSource = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CurrentSource"
QT_MOC_LITERAL(1, 14, 20), // "GetCurrentAndVoltage"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "_current"
QT_MOC_LITERAL(4, 45, 7), // "voltage"
QT_MOC_LITERAL(5, 53, 12), // "setCurrentOK"
QT_MOC_LITERAL(6, 66, 12), // "setVoltageOK"
QT_MOC_LITERAL(7, 79, 8), // "setOutOK"
QT_MOC_LITERAL(8, 88, 22), // "setCurrentAndVoltageOK"
QT_MOC_LITERAL(9, 111, 20), // "getCurrentAndVoltage"
QT_MOC_LITERAL(10, 132, 11) // "onReadyRead"

    },
    "CurrentSource\0GetCurrentAndVoltage\0\0"
    "_current\0voltage\0setCurrentOK\0"
    "setVoltageOK\0setOutOK\0setCurrentAndVoltageOK\0"
    "getCurrentAndVoltage\0onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurrentSource[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    0,   54,    2, 0x06 /* Public */,
       6,    0,   55,    2, 0x06 /* Public */,
       7,    0,   56,    2, 0x06 /* Public */,
       8,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CurrentSource::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurrentSource *_t = static_cast<CurrentSource *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetCurrentAndVoltage((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->setCurrentOK(); break;
        case 2: _t->setVoltageOK(); break;
        case 3: _t->setOutOK(); break;
        case 4: _t->setCurrentAndVoltageOK(); break;
        case 5: _t->getCurrentAndVoltage(); break;
        case 6: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CurrentSource::*_t)(float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CurrentSource::GetCurrentAndVoltage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CurrentSource::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CurrentSource::setCurrentOK)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CurrentSource::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CurrentSource::setVoltageOK)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CurrentSource::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CurrentSource::setOutOK)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CurrentSource::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CurrentSource::setCurrentAndVoltageOK)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject CurrentSource::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CurrentSource.data,
      qt_meta_data_CurrentSource,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CurrentSource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurrentSource::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurrentSource.stringdata0))
        return static_cast<void*>(const_cast< CurrentSource*>(this));
    return QObject::qt_metacast(_clname);
}

int CurrentSource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CurrentSource::GetCurrentAndVoltage(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CurrentSource::setCurrentOK()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CurrentSource::setVoltageOK()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CurrentSource::setOutOK()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CurrentSource::setCurrentAndVoltageOK()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
