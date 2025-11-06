/****************************************************************************
** Meta object code from reading C++ file 'FixMeasureThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../FixMeasureThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FixMeasureThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FixMeasureThread_t {
    QByteArrayData data[6];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FixMeasureThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FixMeasureThread_t qt_meta_stringdata_FixMeasureThread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FixMeasureThread"
QT_MOC_LITERAL(1, 17, 6), // "GetMat"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 33, 14), // "stopFixMeasure"
QT_MOC_LITERAL(5, 48, 7) // "lostPic"

    },
    "FixMeasureThread\0GetMat\0\0cv::Mat\0"
    "stopFixMeasure\0lostPic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FixMeasureThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       4,    0,   34,    2, 0x06 /* Public */,
       5,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FixMeasureThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FixMeasureThread *_t = static_cast<FixMeasureThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetMat((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< cv::Mat(*)>(_a[2]))); break;
        case 1: _t->stopFixMeasure(); break;
        case 2: _t->lostPic(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FixMeasureThread::*_t)(cv::Mat , cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FixMeasureThread::GetMat)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FixMeasureThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FixMeasureThread::stopFixMeasure)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FixMeasureThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FixMeasureThread::lostPic)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FixMeasureThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FixMeasureThread.data,
      qt_meta_data_FixMeasureThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FixMeasureThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FixMeasureThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FixMeasureThread.stringdata0))
        return static_cast<void*>(const_cast< FixMeasureThread*>(this));
    return QThread::qt_metacast(_clname);
}

int FixMeasureThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FixMeasureThread::GetMat(cv::Mat _t1, cv::Mat _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FixMeasureThread::stopFixMeasure()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FixMeasureThread::lostPic()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
