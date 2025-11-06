/****************************************************************************
** Meta object code from reading C++ file 'PulseSet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../PulseSet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PulseSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PulseSet_t {
    QByteArrayData data[20];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PulseSet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PulseSet_t qt_meta_stringdata_PulseSet = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PulseSet"
QT_MOC_LITERAL(1, 9, 13), // "GetPulseParam"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "cycleTime"
QT_MOC_LITERAL(4, 34, 12), // "pulseNumbers"
QT_MOC_LITERAL(5, 47, 14), // "QVector<float>"
QT_MOC_LITERAL(6, 62, 2), // "A0"
QT_MOC_LITERAL(7, 65, 2), // "A1"
QT_MOC_LITERAL(8, 68, 2), // "A2"
QT_MOC_LITERAL(9, 71, 18), // "GetPulseTimesParam"
QT_MOC_LITERAL(10, 90, 12), // "startTime0_0"
QT_MOC_LITERAL(11, 103, 10), // "ctuTime0_0"
QT_MOC_LITERAL(12, 114, 12), // "startTime1_0"
QT_MOC_LITERAL(13, 127, 10), // "ctuTime1_0"
QT_MOC_LITERAL(14, 138, 12), // "startTime1_1"
QT_MOC_LITERAL(15, 151, 10), // "ctuTime1_1"
QT_MOC_LITERAL(16, 162, 12), // "startTime2_0"
QT_MOC_LITERAL(17, 175, 10), // "ctuTime2_0"
QT_MOC_LITERAL(18, 186, 22), // "on_MouseMoveCustomplot"
QT_MOC_LITERAL(19, 209, 12) // "QMouseEvent*"

    },
    "PulseSet\0GetPulseParam\0\0cycleTime\0"
    "pulseNumbers\0QVector<float>\0A0\0A1\0A2\0"
    "GetPulseTimesParam\0startTime0_0\0"
    "ctuTime0_0\0startTime1_0\0ctuTime1_0\0"
    "startTime1_1\0ctuTime1_1\0startTime2_0\0"
    "ctuTime2_0\0on_MouseMoveCustomplot\0"
    "QMouseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PulseSet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   29,    2, 0x06 /* Public */,
       9,    8,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5,    3,    4,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   11,   12,   13,   14,   15,   16,   17,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 19,    2,

       0        // eod
};

void PulseSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PulseSet *_t = static_cast<PulseSet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetPulseParam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QVector<float>(*)>(_a[3])),(*reinterpret_cast< QVector<float>(*)>(_a[4])),(*reinterpret_cast< QVector<float>(*)>(_a[5]))); break;
        case 1: _t->GetPulseTimesParam((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 2: _t->on_MouseMoveCustomplot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
            case 3:
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PulseSet::*_t)(int , int , QVector<float> , QVector<float> , QVector<float> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PulseSet::GetPulseParam)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PulseSet::*_t)(int , int , int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PulseSet::GetPulseTimesParam)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject PulseSet::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PulseSet.data,
      qt_meta_data_PulseSet,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PulseSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PulseSet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PulseSet.stringdata0))
        return static_cast<void*>(const_cast< PulseSet*>(this));
    return QDialog::qt_metacast(_clname);
}

int PulseSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PulseSet::GetPulseParam(int _t1, int _t2, QVector<float> _t3, QVector<float> _t4, QVector<float> _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PulseSet::GetPulseTimesParam(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
