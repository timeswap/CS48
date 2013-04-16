#include <QPainter>
#include <QGraphicsScene>
#include "LibertyTower.h"
#include "MobileUnit.h"

LibertyTower::LibertyTower()
    : QGraphicsRectItem()
    , m_DetectionDistance(350.0)
    , m_Time(0, 0)
    , m_ReloadTime(200.0)
    , m_ShootIsActive(false)
    , m_Target(NULL)
    , m_TowerImage(QImage(":/Images/liberty.png"))
    , m_ShotTime(15)
{
    setRect(-15.0, -15.0, 100.0, 100.0);
    m_Time.start();
}

void LibertyTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(-15,-15,m_TowerImage);

    if ( (m_Target!=NULL) && (m_ShootIsActive) )
    {   // laser beam
        QPointF towerPoint = mapFromScene(pos());
        QPointF target = mapFromScene(m_Target->pos());
        painter->setPen(QPen(Qt::black, 20.0,Qt::SolidLine, Qt::RoundCap));
        painter->drawLine(towerPoint.x() + 5, towerPoint.y() - 12, target.x() - 25, target.y() - 25 );
        painter->setPen(QPen(Qt::blue, 19.0,Qt::SolidLine, Qt::RoundCap) );
        painter->drawLine(towerPoint.x() + 5, towerPoint.y() - 12, target.x() - 25, target.y() - 25);
        painter->setPen(QPen(Qt::cyan, 14.0,Qt::SolidLine, Qt::RoundCap) );
        painter->drawLine(towerPoint.x() + 5, towerPoint.y() - 12, target.x() - 25, target.y() - 25);
        painter->setPen(QPen(Qt::yellow, 8.0,Qt::SolidLine, Qt::RoundCap) );
        painter->drawLine(towerPoint.x() + 5, towerPoint.y() - 12, target.x() - 25, target.y() - 25);
        painter->setPen(QPen(Qt::white, 5.0,Qt::SolidLine, Qt::RoundCap) );
        painter->drawLine(towerPoint.x() + 5, towerPoint.y() - 12, target.x() - 25, target.y() - 25);

        //m_ShootIsActive = false;

    }

}

void LibertyTower::advance(int phase)
{
    if (phase==0)
    {
        searchTarget();
        if ( (m_Target!=NULL) && (m_Time.elapsed()> m_ReloadTime) )
            shoot();
    }
}

void LibertyTower::searchTarget()
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

void LibertyTower::shoot()
{
    m_ShootIsActive=true;
    m_Target->touched(5); //5
    m_Time.restart();
}

