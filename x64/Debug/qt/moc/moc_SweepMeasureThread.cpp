/****************************************************************************
** Meta object code from reading C++ file 'SweepMeasureThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../SweepMeasureThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SweepMeasureThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SweepMeasureThread_t {
    QByteArrayData data[13];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SweepMeasureThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SweepMeasureThread_t qt_meta_stringdata_SweepMeasureThread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SweepMeasureThread"
QT_MOC_LITERAL(1, 19, 12), // "GetSweepData"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "value"
QT_MOC_LITERAL(4, 39, 7), // "cv::Mat"
QT_MOC_LITERAL(5, 47, 2), // "on"
QT_MOC_LITERAL(6, 50, 3), // "off"
QT_MOC_LITERAL(7, 54, 6), // "GetPic"
QT_MOC_LITERAL(8, 61, 7), // "showMat"
QT_MOC_LITERAL(9, 69, 16), // "stopSweepMeasure"
QT_MOC_LITERAL(10, 86, 7), // "lostPic"
QT_MOC_LITERAL(11, 94, 7), // "plusEnd"
QT_MOC_LITERAL(12, 102, 1) // "s"

    },
    "SweepMeasureThread\0GetSweepData\0\0value\0"
    "cv::Mat\0on\0off\0GetPic\0showMat\0"
    "stopSweepMeasure\0lostPic\0plusEnd\0s"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SweepMeasureThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       7,    1,   46,    2, 0x06 /* Public */,
       9,    0,   49,    2, 0x06 /* Public */,
      10,    0,   50,    2, 0x06 /* Public */,
      11,    1,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Void, 0x80000000 | 4,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void SweepMeasureThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SweepMeasureThread *_t = static_cast<SweepMeasureThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetSweepData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2])),(*reinterpret_cast< cv::Mat(*)>(_a[3]))); break;
        case 1: _t->GetPic((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->stopSweepMeasure(); break;
        case 3: _t->lostPic(); break;
        case 4: _t->plusEnd((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SweepMeasureThread::*_t)(double , cv::Mat , cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SweepMeasureThread::GetSweepData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SweepMeasureThread::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SweepMeasureThread::GetPic)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SweepMeasureThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SweepMeasureThread::stopSweepMeasure)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SweepMeasureThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SweepMeasureThread::lostPic)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SweepMeasureThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SweepMeasureThread::plusEnd)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject SweepMeasureThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SweepMeasureThread.data,
      qt_meta_data_SweepMeasureThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SweepMeasureThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SweepMeasureThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SweepMeasureThread.stringdata0))
        return static_cast<void*>(const_cast< SweepMeasureThread*>(this));
    return QThread::qt_metacast(_clname);
}

int SweepMeasureThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SweepMeasureThread::GetSweepData(double _t1, cv::Mat _t2, cv::Mat _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SweepMeasureThread::GetPic(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SweepMeasureThread::stopSweepMeasure()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SweepMeasureThread::lostPic()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SweepMeasureThread::plusEnd(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
