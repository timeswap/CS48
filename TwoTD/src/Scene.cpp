#include "Scene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QTime>



Scene::Scene()
    : QGraphicsScene()
    , m_TicTacTime(0)
    , m_P1Lives(15)
    , m_P1Resources(10)
    , m_P2Resources(10)
    , m_inTowerBuildMode(false)
    , m_inGame(false)
    , m_towerToBeBuilt("")
    , m_monsterSelected("")
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

Scene::Scene(bool running)
    : QGraphicsScene()
    , m_TicTacTime(0)
    , m_P1Lives(15)
    , m_P1Resources(10)
    , m_P2Resources(10)
    , m_inTowerBuildMode(false)
    , m_inGame(running)
    , m_towerToBeBuilt("")
    , m_monsterSelected("")
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}


void Scene::advance()
{
    if(m_P1Lives <= 0 || m_TicTacTime >= 4500) //4500 = 25*60*3, with 25 tictacs per second
    {
        this->m_inGame = false; //game is over
        if(m_TicTacTime >= 4500)
        {
            emit P1Win();
        }
        else if(m_P1Lives<= 0)
        {
            emit P2Win();
        }

    }

    m_TicTacTime++; //advance timer counter
    //setFocus(Qt::OtherFocusReason); //not sure why scene doesn't want to maintain focus

        // delete killed objects
     QGraphicsItem *item=NULL;
     MobileUnit * unit=NULL;
     int i=0;
     while (i<items().count())
     {
         item=items().at(i);
         unit=dynamic_cast<MobileUnit* > (item);
         if ( ( unit!=NULL) && (unit->isFinished()==true))
         {
             if((unit->scenePos()).x() > 800)
             {               
                 m_P1Lives--;
                 if(m_P1Lives >= 0)
                 {
                    emit updateP1Lives("Lives: " + QString::number(m_P1Lives));
                 }
             }
             removeItem(item);
             delete unit;
         }

         else ++i;
      }

    //this handles resources
    if(m_TicTacTime%25 == 0 && m_inGame)
    {
        m_P1Resources++;
        emit updateP1Resources("Resources: " + QString::number(m_P1Resources));

        //gives P2 more money the longer the time is because P1 will have more towers
        m_P2Resources+=(2+(m_TicTacTime/300));
        emit updateP2Resources("Resources: " + QString::number(m_P2Resources));
    }

    //update the timer
    if(m_TicTacTime%25 == 0 && m_inGame) //currently updates every 40ms, so 25 updates is one second
    {
        emit updateTimer("Time Left: " + QString::number(180 - (m_TicTacTime/25)));
    }


    /*
    // Add new units every 5 tictacs
    // CAUTION: MAY CAUSE OVERFLOW ISSUES
    if(m_TicTacTime % 5 == 0)
    {
        // qDebug() << "add unit";
        MobileUnit * mobileUnit= new MobileUnit();
        qreal h=static_cast<qreal>( qrand() % static_cast<int>(height()) );
        //mobileUnit->setPos(width(), h);
        mobileUnit->setPos(0, h); //draws monsters on left and advances left to right
        addItem(mobileUnit);


    }*/

    QGraphicsScene::advance();
    update();
}


void Scene::createMonster()
{
    //precondition: inGame is true
        if(m_monsterSelected == "GhostMonster" && m_P2Resources >= 4)
        {
            MobileUnit *m = new MobileUnit("GhostMonster");
            int high = 25;
            int low = -25;
            int offset =  qrand() % ((high + 1) - low) + low;
            m->setPos(0,324+offset);
            addItem(m);
            m_P2Resources -= 4;
            emit updateP2Resources("Resources: " + QString::number(m_P2Resources));

        }
        else if(m_monsterSelected == "RobotMonster" && m_P2Resources >= 6)
        {
            MobileUnit *m = new MobileUnit("RobotMonster");
            int high = 25;
            int low = -25;
            int offset =  qrand() % ((high + 1) - low) + low;
            m->setPos(0,324+offset);
            addItem(m);
            m_P2Resources -= 6;
            emit updateP2Resources("Resources: " + QString::number(m_P2Resources));
        }
        else if(m_monsterSelected == "SlimeMonster"&& m_P2Resources >= 8)
        {
            MobileUnit *m = new MobileUnit("SlimeMonster");
            int high = 25;
            int low = -25;
            int offset =  qrand() % ((high + 1) - low) + low;
            m->setPos(0,324+offset);
            addItem(m);
            m_P2Resources -= 8;
            emit updateP2Resources("Resources: " + QString::number(m_P2Resources));
        }
}



void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        emit startGame();
    }
    else if(event->key() == Qt::Key_1 && m_inGame)
    {
        m_monsterSelected = "GhostMonster";
        emit updateP2Desc("Name: Ghost\nHealth: 25\nSpeed: 60\nCost: 4");
    }
    else if(event->key() == Qt::Key_2 && m_inGame)
    {
        m_monsterSelected = "RobotMonster";
        emit updateP2Desc("Name: Robot\nHealth: 40\nSpeed: 50\nCost: 6");
    }
    else if(event->key() == Qt::Key_3 && m_inGame)
    {
        m_monsterSelected = "SlimeMonster";
        emit updateP2Desc("Name: Slime\nHealth: 60\nSpeed: 40\nCost: 8");
    }
    else if(event->key() == Qt::Key_Space && m_inGame)
    {
        createMonster();
    }
    else
    {
        return;
    }

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_inGame)
   {
        QPointF p = event->scenePos();
        if(m_inTowerBuildMode)
        {
            if(!(p.y()>234.0 && p.y() < 350.0)) //to make sure you can't build on the path!
                createTower(p.x()-16, p.y()-16); //-16 to make sure images are centered when built
        }
    }
}

void Scene::createTower(qreal x, qreal y)
{
    //precondition: in game
    //builds a tower at clicked location
    if(m_towerToBeBuilt == "EiffelTower" && m_P1Resources >= 5)
    {
        EiffelTower *t = new EiffelTower();
        t->setPos(x, y);
        addItem(t);
        m_P1Resources -= 5;
        emit updateP1Resources("Resources: " + QString::number(m_P1Resources));
        //m_inTowerBuildMode = false;
    }
    else if(m_towerToBeBuilt == "LibertyTower" && m_P1Resources >= 8)
    {
        LibertyTower *t= new LibertyTower();
        t->setPos(x, y);
        addItem(t);
        m_P1Resources -= 8;
        emit updateP1Resources("Resources: " + QString::number(m_P1Resources));
        //m_inTowerBuildMode = false;
    }
    else if(m_towerToBeBuilt == "PyramidTower" && m_P1Resources >= 13)
    {
        PyramidTower *t = new PyramidTower();
        t->setPos(x, y);
        addItem(t);
        m_P1Resources -= 13;
        emit updateP1Resources("Resources: " + QString::number(m_P1Resources));
        //m_inTowerBuildMode = false;
    }
}

void Scene::setTowerBuildModeOn()
{
    m_inTowerBuildMode = true;
}

void Scene::setTower1ToBeBuilt()
{
    emit updateP1Desc("Name: Eiffel\nRange: 300\nDamage: 3\nCost: 5");
    m_towerToBeBuilt = "EiffelTower";
}

void Scene::setTower2ToBeBuilt()
{
    emit updateP1Desc("Name: Liberty\nRange: 350\nDamage: 5\nCost: 8");
    m_towerToBeBuilt = "LibertyTower";
}

void Scene::setTower3ToBeBuilt()
{
    emit updateP1Desc("Name: Pyramid\nRange: 400\nDamage: 10\nCost: 13");
    m_towerToBeBuilt = "PyramidTower";
}

