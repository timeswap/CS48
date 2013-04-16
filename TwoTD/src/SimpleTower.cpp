#include <QPainter>
#include <QGraphicsScene>
#include "SimpleTower.h"
#include "MobileUnit.h"

SimpleTower::SimpleTower()
    : QGraphicsRectItem()
    , m_DetectionDistance(100.0)
    , m_Time(0, 0)
    , m_ReloadTime(200)
    , m_ShootIsActive(false)
    , m_Target(NULL)
    , m_TowerImage(QImage(":/Images/effiel_tower.png"))
{
    setRect(-15.0, -15.0, 100.0, 100.0);
    m_Time.start();
}

void SimpleTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(-15,-15,m_TowerImage);
    if ( (m_Target!=NULL) && (m_ShootIsActive) )
    {   // laser beam
        QPointF towerPoint = mapFromScene(pos());
        QPointF target = mapFromScene(m_Target->pos());
        painter->setPen(QPen(Qt::yellow,8.0,Qt::SolidLine));
        painter->drawLine(towerPoint.x(), towerPoint.y(), target.x(), target.y());
        painter->setPen(QPen(Qt::red,5.0,Qt::SolidLine));
        painter->drawLine(towerPoint.x(), towerPoint.y(), target.x(), target.y());
        painter->setPen(QPen(Qt::white,2.0,Qt::SolidLine));
        painter->drawLine(towerPoint.x(), towerPoint.y(), target.x(), target.y());
        m_ShootIsActive=false;
    }
}

void SimpleTower::advance(int phase)
{
    if (phase==0)
    {
        searchTarget();
        if ( (m_Target!=NULL) && (m_Time.elapsed()> m_ReloadTime) )
            shoot();
    }
}

void SimpleTower::searchTarget()
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

void SimpleTower::shoot()
{
    m_ShootIsActive=true;
    m_Target->touched(5); //5
    m_Time.restart();
}
