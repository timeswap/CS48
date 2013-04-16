#ifndef LIBERTYTOWER_H
#define LIBERTYTOWER_H

#include <QtCore>
#include <QGraphicsRectItem>

class MobileUnit;
class GhostMonster;
class RobotMonster;
class SlimeMonster;

class LibertyTower :public QGraphicsRectItem
{
public:
    LibertyTower();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase); //advances the unit in the system
private:
    void searchTarget();
    void shoot();
private:
    qreal m_DetectionDistance;
    QTime m_Time;
    QTime s_Time;
    int m_ReloadTime;
    bool m_ShootIsActive;
    int m_ShotTime;

    MobileUnit * m_Target;
    //RobotMonster * m_Target;
    //GhostMonster * m_Target;
    //SlimeMonster * m_Target;

    QImage m_TowerImage;
};

#endif // LIBERTYTOWER_H
