#include <QPainter>
#include <QGraphicsScene>
#include "PyramidTower.h"
#include <cmath>

#include "MobileUnit.h"

PyramidTower::PyramidTower()
    : QGraphicsRectItem()
    , m_DetectionDistance(400.0)
    , m_Time(0, 0)
    , m_ReloadTime(200)
    , m_ShootIsActive(false)
    , m_Target(NULL)
    , m_TowerImage(QImage(":/Images/pyramid.png"))
{
    setRect(-15.0, -15.0, 100.0, 100.0);
    m_Time.start();
}

void PyramidTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(-15,-15,m_TowerImage);
    if ( (m_Target!=NULL) && (m_ShootIsActive) )
    {   // laser beam
        QPointF towerPoint = mapFromScene(pos());
        QPointF target = mapFromScene(m_Target->pos());

         painter->setPen(QPen(Qt::black, 23.5,Qt::SolidLine, Qt::RoundCap));
         painter->drawLine(towerPoint.x() + 15, towerPoint.y() + 5, target.x() - 25, target.y() - 25 ); // 7
         painter->setPen(QPen(Qt::darkMagenta, 23.0,Qt::SolidLine, Qt::RoundCap));
         painter->drawLine(towerPoint.x() + 15, towerPoint.y() + 5, target.x() - 25, target.y() - 25 ); // 9
         painter->setPen(QPen(Qt::magenta, 17.0,Qt::SolidLine, Qt::RoundCap));
         painter->drawLine(towerPoint.x() + 15, towerPoint.y() + 5, target.x() - 25, target.y() - 25); //11
         painter->setPen(QPen(Qt::yellow, 10.0,Qt::SolidLine, Qt::RoundCap));
         painter->drawLine(towerPoint.x() + 15, towerPoint.y() + 5, target.x() - 25, target.y() - 25); //13
         painter->setPen(QPen(Qt::white, 6.0,Qt::SolidLine, Qt::RoundCap));
         painter->drawLine(towerPoint.x() + 15, towerPoint.y() + 5, target.x() - 25, target.y() - 25); //15

         //m_ShootIsActive=false;
    }
}

void PyramidTower::advance(int phase)
{
    if (phase==0)
    {
        searchTarget();
        if ( (m_Target!=NULL) && (m_Time.elapsed()> m_ReloadTime) )
            shoot();
    }
}

void PyramidTower::searchTarget()
{
    m_Target=NULL;
    QList<QGraphicsItem* > itemList = scene()->items();
    int i = itemList.count()-1;
    qreal dx, dy, sqrDist;
    qreal sqrDetectionDist = m_DetectionDistance * m_DetectionDistance;
    MobileUnit * unit=NULL;
    while( (i>=0) && (NULL==m_Target) )
    {
        QGraphicsItem * item = itemList.at(i);
        unit = dynamic_cast<MobileUnit * >(item);
        if ( (unit!=NULL) && ( unit->lifePoints()>0 ) )
        {
            dx = unit->x()-x();
            dy = unit->y()-y();
            sqrDist = dx*dx+dy*dy;
            if (sqrDist < sqrDetectionDist)
                m_Target=unit;
        }
        --i;
    }
}

void PyramidTower::shoot()
{
    m_ShootIsActive=true;
    m_Target->touched(10); //9
    m_Time.restart();
}


