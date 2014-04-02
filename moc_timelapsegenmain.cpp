/****************************************************************************
** Meta object code from reading C++ file 'timelapsegenmain.h'
**
** Created: Sat Mar 29 11:57:58 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "timelapsegenmain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timelapsegenmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_imageEnhanceDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   20,   19,   19, 0x08,
      64,   20,   19,   19, 0x08,
     100,   20,   19,   19, 0x08,
     138,   19,   19,   19, 0x08,
     173,  164,   19,   19, 0x08,
     210,   19,   19,   19, 0x08,
     247,  164,   19,   19, 0x08,
     282,  164,   19,   19, 0x08,
     319,   19,   19,   19, 0x08,
     354,   19,   19,   19, 0x08,
     391,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_imageEnhanceDialog[] = {
    "imageEnhanceDialog\0\0value\0"
    "on_sliderBrightness_valueChanged(int)\0"
    "on_sliderContrast_valueChanged(int)\0"
    "on_sliderSaturation_valueChanged(int)\0"
    "on_pushButton_2_clicked()\0position\0"
    "on_sliderBrightness_sliderMoved(int)\0"
    "on_sliderBrightness_sliderReleased()\0"
    "on_sliderContrast_sliderMoved(int)\0"
    "on_sliderSaturation_sliderMoved(int)\0"
    "on_sliderContrast_sliderReleased()\0"
    "on_sliderSaturation_sliderReleased()\0"
    "on_pushButton_clicked()\0"
};

void imageEnhanceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        imageEnhanceDialog *_t = static_cast<imageEnhanceDialog *>(_o);
        switch (_id) {
        case 0: _t->on_sliderBrightness_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_sliderContrast_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_sliderSaturation_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_sliderBrightness_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_sliderBrightness_sliderReleased(); break;
        case 6: _t->on_sliderContrast_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_sliderSaturation_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_sliderContrast_sliderReleased(); break;
        case 9: _t->on_sliderSaturation_sliderReleased(); break;
        case 10: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData imageEnhanceDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject imageEnhanceDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_imageEnhanceDialog,
      qt_meta_data_imageEnhanceDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &imageEnhanceDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *imageEnhanceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *imageEnhanceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_imageEnhanceDialog))
        return static_cast<void*>(const_cast< imageEnhanceDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int imageEnhanceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
static const uint qt_meta_data_Preferences[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      36,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Preferences[] = {
    "Preferences\0\0on_BtnCancel_clicked()\0"
    "on_BtnRender_clicked()\0"
};

void Preferences::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Preferences *_t = static_cast<Preferences *>(_o);
        switch (_id) {
        case 0: _t->on_BtnCancel_clicked(); break;
        case 1: _t->on_BtnRender_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Preferences::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Preferences::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Preferences,
      qt_meta_data_Preferences, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Preferences::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Preferences::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Preferences::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Preferences))
        return static_cast<void*>(const_cast< Preferences*>(this));
    return QDialog::qt_metacast(_clname);
}

int Preferences::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_TimeLapseGenMain[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   17,   17,   17, 0x08,
      69,   17,   17,   17, 0x08,
      92,   17,   17,   17, 0x08,
     129,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TimeLapseGenMain[] = {
    "TimeLapseGenMain\0\0filesSelected()\0"
    "on_actionSelect_Images_triggered()\0"
    "loadImagesIntoMemory()\0"
    "on_action_Enhance_Images_triggered()\0"
    "on_actionGenerate_Timelapse_triggered()\0"
};

void TimeLapseGenMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimeLapseGenMain *_t = static_cast<TimeLapseGenMain *>(_o);
        switch (_id) {
        case 0: _t->filesSelected(); break;
        case 1: _t->on_actionSelect_Images_triggered(); break;
        case 2: _t->loadImagesIntoMemory(); break;
        case 3: _t->on_action_Enhance_Images_triggered(); break;
        case 4: _t->on_actionGenerate_Timelapse_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TimeLapseGenMain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TimeLapseGenMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TimeLapseGenMain,
      qt_meta_data_TimeLapseGenMain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TimeLapseGenMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TimeLapseGenMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TimeLapseGenMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TimeLapseGenMain))
        return static_cast<void*>(const_cast< TimeLapseGenMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TimeLapseGenMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TimeLapseGenMain::filesSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
