/****************************************************************************
** Meta object code from reading C++ file 'imgwin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imgwin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImgWin_t {
    QByteArrayData data[13];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImgWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImgWin_t qt_meta_stringdata_ImgWin = {
    {
QT_MOC_LITERAL(0, 0, 6), // "ImgWin"
QT_MOC_LITERAL(1, 7, 7), // "closing"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 8), // "QAction*"
QT_MOC_LITERAL(4, 25, 12), // "scaleChanged"
QT_MOC_LITERAL(5, 38, 13), // "mouseOverInfo"
QT_MOC_LITERAL(6, 52, 14), // "mousePressInfo"
QT_MOC_LITERAL(7, 67, 8), // "setScale"
QT_MOC_LITERAL(8, 76, 11), // "setMenuItem"
QT_MOC_LITERAL(9, 88, 1), // "a"
QT_MOC_LITERAL(10, 90, 14), // "labelMouseInfo"
QT_MOC_LITERAL(11, 105, 1), // "p"
QT_MOC_LITERAL(12, 107, 19) // "labelMousePressInfo"

    },
    "ImgWin\0closing\0\0QAction*\0scaleChanged\0"
    "mouseOverInfo\0mousePressInfo\0setScale\0"
    "setMenuItem\0a\0labelMouseInfo\0p\0"
    "labelMousePressInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImgWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    1,   60,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   66,    2, 0x0a /* Public */,
       8,    1,   69,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, QMetaType::QPoint,   11,
    QMetaType::Void, QMetaType::QPoint,   11,

       0        // eod
};

void ImgWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImgWin *_t = static_cast<ImgWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closing((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->scaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mouseOverInfo((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->mousePressInfo((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->setScale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setMenuItem((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->labelMouseInfo((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->labelMousePressInfo((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImgWin::*_t)(QAction * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImgWin::closing)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImgWin::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImgWin::scaleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ImgWin::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImgWin::mouseOverInfo)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ImgWin::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImgWin::mousePressInfo)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ImgWin::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_ImgWin.data,
      qt_meta_data_ImgWin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ImgWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImgWin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImgWin.stringdata0))
        return static_cast<void*>(const_cast< ImgWin*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int ImgWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void ImgWin::closing(QAction * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImgWin::scaleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImgWin::mouseOverInfo(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImgWin::mousePressInfo(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
