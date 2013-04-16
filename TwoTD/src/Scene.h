#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QString>
#include <QKeyEvent>
#include <QMouseEvent>
#include "MobileUnit.h"
#include "SimpleTower.h"
#include "EiffelTower.h"
#include "LibertyTower.h"
#include "PyramidTower.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
    Scene(bool running);
public slots:
    void advance();
    void keyPressEvent(QKeyEvent *event); //handles key presses
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //handles mouse clicks

    //this set triggers when buttons are pressed
    void createMonster(); //creates monsters
    void createTower(qreal x, qreal y); //creates towers at the position
    void setTowerBuildModeOn(); //tells that a tower building button has been pressed
    void setTower1ToBeBuilt(); //tells that the first button has been clicked
    void setTower2ToBeBuilt(); //tells that the second button has been clicked
    void setTower3ToBeBuilt(); //tells that the third button has been clicked

signals:
    void startGame();
    void updateP1Resources(QString r1);
    void updateP2Resources(QString r2);
    void updateP1Desc(QString d1);
    void updateP2Desc(QString d2);
    void updateP1Lives(QString l1);
    void updateTimer(QString t);
    void P1Win();
    void P2Win();

private:
    int m_TicTacTime;
    int m_P1Lives;
    int m_P1Resources;
    int m_P2Resources;
    bool m_inTowerBuildMode;
    bool m_inGame;
    QString m_towerToBeBuilt;
    QString m_monsterSelected;
};

#endif // SCENE_H
