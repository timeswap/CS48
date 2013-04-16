#ifndef SIMPLETOWER_H
#define SIMPLETOWER_H

#include <QtCore>
#include <QGraphicsRectItem>

class MobileUnit;

class SimpleTower : public QGraphicsRectItem
{
public:
    SimpleTower();
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
    QImage m_TowerImage;
};

#endif // SIMPLETOWER_H
