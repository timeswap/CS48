#ifndef MOBILEUNIT_H
#define MOBILEUNIT_H

#include <QtCore>
#include <QGraphicsRectItem>
#include <QRadialGradient>
class MobileUnit : public QGraphicsRectItem
{
public:
    MobileUnit();
    MobileUnit(QString s);
    inline int lifePoints() { return m_LifePoints;}
    inline bool isFinished() const { return m_IsFinished; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //paints the unit
    void advance(int phase); //advances the unit in the system
    void touched (int hurtPoints); //called when unit gets attacked

private:
    int m_LifePoints;
    qreal m_Alpha;
    qreal m_DirX;
    qreal m_DirY;
    qreal m_Speed;
    bool m_IsFinished;
    bool m_IsExploding;
    int m_ExplosionDuration;
    QRadialGradient m_RedExplosion;
    QTime m_Time;

    QImage m_SpacecraftImage;
    QImage m_GhostImage;
    QImage m_SlimeImage;
    QImage m_RobotImage;
    QImage m_Image;
};

#endif // MOBILEUNIT_H
