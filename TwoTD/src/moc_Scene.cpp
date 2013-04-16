/****************************************************************************
** Meta object code from reading C++ file 'Scene.h'
**
** Created: Fri Mar 11 00:49:29 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Scene.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Scene[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      22,   19,    6,    6, 0x05,
      52,   49,    6,    6, 0x05,
      82,   79,    6,    6, 0x05,
     107,  104,    6,    6, 0x05,
     132,  129,    6,    6, 0x05,
     157,  155,    6,    6, 0x05,
     178,    6,    6,    6, 0x05,
     186,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     194,    6,    6,    6, 0x0a,
     210,  204,    6,    6, 0x0a,
     236,  204,    6,    6, 0x0a,
     279,    6,    6,    6, 0x0a,
     299,  295,    6,    6, 0x0a,
     324,    6,    6,    6, 0x0a,
     346,    6,    6,    6, 0x0a,
     367,    6,    6,    6, 0x0a,
     388,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Scene[] = {
    "Scene\0\0startGame()\0r1\0updateP1Resources(QString)\0"
    "r2\0updateP2Resources(QString)\0d1\0"
    "updateP1Desc(QString)\0d2\0updateP2Desc(QString)\0"
    "l1\0updateP1Lives(QString)\0t\0"
    "updateTimer(QString)\0P1Win()\0P2Win()\0"
    "advance()\0event\0keyPressEvent(QKeyEvent*)\0"
    "mousePressEvent(QGraphicsSceneMouseEvent*)\0"
    "createMonster()\0x,y\0createTower(qreal,qreal)\0"
    "setTowerBuildModeOn()\0setTower1ToBeBuilt()\0"
    "setTower2ToBeBuilt()\0setTower3ToBeBuilt()\0"
};

const QMetaObject Scene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_Scene,
      qt_meta_data_Scene, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Scene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Scene))
        return static_cast<void*>(const_cast< Scene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startGame(); break;
        case 1: updateP1Resources((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: updateP2Resources((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: updateP1Desc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: updateP2Desc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: updateP1Lives((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: updateTimer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: P1Win(); break;
        case 8: P2Win(); break;
        case 9: advance(); break;
        case 10: keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 11: mousePressEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 12: createMonster(); break;
        case 13: createTower((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 14: setTowerBuildModeOn(); break;
        case 15: setTower1ToBeBuilt(); break;
        case 16: setTower2ToBeBuilt(); break;
        case 17: setTower3ToBeBuilt(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Scene::startGame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Scene::updateP1Resources(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Scene::updateP2Resources(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Scene::updateP1Desc(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Scene::updateP2Desc(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Scene::updateP1Lives(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Scene::updateTimer(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Scene::P1Win()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Scene::P2Win()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
