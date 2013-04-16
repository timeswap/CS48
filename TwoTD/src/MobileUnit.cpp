#include "MobileUnit.h"
#include <QPainter>
#include <QGraphicsScene>
#include <math.h>

#include <QImage>

MobileUnit::MobileUnit()
    : QGraphicsRectItem()
    , m_LifePoints(30) //Monster lifepoints
    , m_Alpha(0)
    , m_DirX(1.0)
    , m_DirY(0.)
    , m_Speed(1)
    , m_IsFinished(false)
    , m_IsExploding(false)
    , m_ExplosionDuration(100)
    , m_RedExplosion(0.0, 0.0, 600.0, 0.0, -150.0)
    , m_Time(0, 0)
    , m_Image(QImage(":/Images/pyramid.png"))
{

    //determines angle of monster spawning, values can be changed
    m_Alpha= static_cast<qreal> (90); //angle which monster approaches (straight)
    qreal speed= static_cast<qreal> (50); //speed of monster advancing
    m_DirY=cos(m_Alpha/180.0*M_PI ); //90-up and down, 180-right to left,
    m_DirX=sin(m_Alpha/180.0*M_PI);
    m_Alpha= -m_Alpha+90 ;
    m_Speed=1.0+speed*0.1; //1+
    setRect(-10.0, -10.0, 20.0, 20.0);//-10 -10 20 20
    m_Time.start();

    m_RedExplosion.setColorAt(0.0, Qt::white);
    m_RedExplosion.setColorAt(0.2, QColor(255, 255, 100, 255));
    m_RedExplosion.setColorAt(0.4, QColor(255, 80, 0, 200));
    m_RedExplosion.setColorAt(1.0, QColor(255, 255, 255, 0));
}


MobileUnit::MobileUnit(QString s)
    : QGraphicsRectItem()
    , m_LifePoints(30) //Monster lifepoints
    , m_Alpha(0)
    , m_DirX(1.0)
    , m_DirY(0.0)
    , m_Speed(1)
    , m_IsFinished(false)
    , m_IsExploding(false)
    , m_ExplosionDuration(1000)
    , m_RedExplosion(-10.0, -75.0, 90.0, -20.0, -15.0)
    , m_Time(0, 0)
    , m_Image(QImage(""))
{


    //determines angle of monster spawning, values can be changed
    m_Alpha= static_cast<qreal> (90); //angle which monster approaches (straight)
    qreal speed= static_cast<qreal> (50); //speed of monster advancing
    m_DirY=cos(m_Alpha/180.0*M_PI ); //90-up and down, 180-right to left,
    m_DirX=sin(m_Alpha/180.0*M_PI);
    m_Alpha= -m_Alpha+90 ;
    m_Speed=1.0+speed*0.1; //1+
    setRect(-10.0, -10.0, 20.0, 20.0);//-10 -10 20 20
    m_Time.start();

    m_RedExplosion.setColorAt(0.0, QColor(255, 255, 255, 0));
    m_RedExplosion.setColorAt(0.25, QColor(255, 255, 100, 255));
    m_RedExplosion.setColorAt(0.3, Qt::yellow);
    m_RedExplosion.setColorAt(0.5, QColor(255, 80, 0, 200));
    m_RedExplosion.setColorAt(0.65, Qt::darkRed);
    m_RedExplosion.setColorAt(0.75, Qt::darkGray);

    if(s == "GhostMonster")
    {
        m_LifePoints = 25;
        speed= static_cast<qreal> (60);
        m_Image = QImage(":/Images/ghost.png");
    }
    else if(s == "RobotMonster")
    {
        m_LifePoints = 40;
        speed= static_cast<qreal> (50);
        m_Image = QImage(":/Images/robot.png");
    }
    else if(s == "SlimeMonster")
    {
        m_LifePoints = 60;
        speed= static_cast<qreal> (40);
        m_Image = QImage(":/Images/slime.png");
    }
}

void MobileUnit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);

    if (!m_IsExploding)
    {
        painter->rotate(m_Alpha);
        painter->drawImage(-50,-50, m_Image);
    }
    else
    {
        painter->setBrush(QBrush(m_RedExplosion));
        qreal explosionRadius= 13.0 - (m_Time.elapsed()/8) / 10;
        painter->drawEllipse(-60 + (m_Time.elapsed()/16), explosionRadius - 110, 8.0*explosionRadius, 8.0*explosionRadius);
    }
}

void MobileUnit::advance(int phase)
{
    if (phase==0)
    {
        qreal xx=x(); qreal yy=y();
        if ( (xx<0.0)  ) // ((xx<0.0)|| (xx > scene()->width()) allows flip around (right to left)
        {   // rebound
            m_DirX=-m_DirX;
            m_Alpha=-m_Alpha;
        }
        if ( (yy<0.0) ) //(yy<0.0) || (yy > scene()->height()) allows flip around (top to bot)
        {   // rebound
            m_DirY=-m_DirY;
            m_Alpha=180-m_Alpha;
        }
        if (m_IsExploding)
        {
            m_Speed*=.5;  // decrease speed
            if (m_Time.elapsed() > m_ExplosionDuration)
                m_IsFinished=true;  // is dead
        }
        if( pos().x() > 800)
        {
            m_IsFinished = true;
        }
        //setPos(x()==0, y(0)) makes pictures stay at left of screen
        setPos(x()+m_DirX*m_Speed, y()+m_DirY*m_Speed);
    }
}

void MobileUnit::touched (int hurtPoints)
{
    m_LifePoints -=hurtPoints; // decrease life
    if (m_LifePoints<0) m_LifePoints=0;
    if (m_LifePoints==0)
    {
        m_Time.start();
        m_IsExploding=true;
    }
}
