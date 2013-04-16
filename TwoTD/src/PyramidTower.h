#ifndef PYRAMIDTOWER_H
#define PYRAMIDTOWER_H

#include <QtCore>
#include <QGraphicsRectItem>

class MobileUnit;
class GhostMonster;
class RobotMonster;
class SlimeMonster;

class PyramidTower : public QGraphicsRectItem
{
public:
    PyramidTower();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //paints the tower
    void advance(int phase); //advances the unit in the system
private:
    void searchTarget();
    void shoot();
private:
    qreal m_DetectionDistance;
    QTime m_Time;
    int m_ReloadTime;
    bool m_ShootIsActive;

    MobileUnit * m_Target;
    //RobotMonster * m_Target;
    //GhostMonster * m_Target;
    //SlimeMonster * m_Target;

    QImage m_TowerImage;
};
#endif // PYRAMIDTOWER_H
