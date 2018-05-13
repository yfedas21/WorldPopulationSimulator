/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WorldPopulationSimulator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "updateAnim"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 16), // "updatePopulation"
QT_MOC_LITERAL(4, 40, 15), // "simCalcFinished"
QT_MOC_LITERAL(5, 56, 22), // "on_beginSimBtn_clicked"
QT_MOC_LITERAL(6, 79, 22), // "on_resetSimBtn_clicked"
QT_MOC_LITERAL(7, 102, 29), // "on_simRuntimeInput_textEdited"
QT_MOC_LITERAL(8, 132, 4), // "arg1"
QT_MOC_LITERAL(9, 137, 31), // "on_enableDisastersInput_toggled"
QT_MOC_LITERAL(10, 169, 7), // "checked"
QT_MOC_LITERAL(11, 177, 31), // "on_enableMigrationInput_toggled"
QT_MOC_LITERAL(12, 209, 41), // "on_continentFocusInput_curren..."
QT_MOC_LITERAL(13, 251, 29), // "on_startDateInput_dateChanged"
QT_MOC_LITERAL(14, 281, 4) // "date"

    },
    "MainWindow\0updateAnim\0\0updatePopulation\0"
    "simCalcFinished\0on_beginSimBtn_clicked\0"
    "on_resetSimBtn_clicked\0"
    "on_simRuntimeInput_textEdited\0arg1\0"
    "on_enableDisastersInput_toggled\0checked\0"
    "on_enableMigrationInput_toggled\0"
    "on_continentFocusInput_currentTextChanged\0"
    "on_startDateInput_dateChanged\0date"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    1,   69,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      11,    1,   75,    2, 0x08 /* Private */,
      12,    1,   78,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QDate,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateAnim(); break;
        case 1: _t->updatePopulation(); break;
        case 2: _t->simCalcFinished(); break;
        case 3: _t->on_beginSimBtn_clicked(); break;
        case 4: _t->on_resetSimBtn_clicked(); break;
        case 5: _t->on_simRuntimeInput_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_enableDisastersInput_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_enableMigrationInput_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_continentFocusInput_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_startDateInput_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
