#include "MainWindow.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <Scene.h>
#include <SimpleTower.h>
#include <QTimer>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , p1Button1( new QPushButton( tr( "Eiffel Tower"), this) )       //Buttons
    , p1Button2( new QPushButton( tr( "Liberty Tower"), this) )
    , p1Button3( new QPushButton( tr( "Pyramid Tower"), this) )

    , p2Button1( new QPushButton( tr( "Ghost Monster (1)"), this) )
    , p2Button2( new QPushButton( tr( "Robot Monster (2)" ), this) )
    , p2Button3( new QPushButton( tr( "Slime Monster (3)" ), this) )

    , p1Desc( new QLabel( tr( "\n\n\n" ), this) )          //Labels
    , p1Res( new QLabel( tr( "Resources: 10" ), this) )
    , p1Lives( new QLabel( tr( "Lives: 15" ), this) )

    , p2Desc( new QLabel( tr( "\n\n\n" ), this) )
    , p2Res( new QLabel( tr( "Resources: 10" ), this) )
    , p0Timer( new QLabel(tr("Time Left: 180"), this))

{


    // Vertical layout governs all contents of window
    QVBoxLayout * const vLayout = new QVBoxLayout();

    // Set up GraphicsView
    view = new QGraphicsView();
    Scene *start = new Scene();
    start->setSceneRect( 0.0, 0.0, 800.0, 600.0 );
    start->setBackgroundBrush(QPixmap(":/Images/startscreen.png"));
    view->setScene( start );

    scene = new Scene(true);
    scene->setSceneRect( 0.0, 0.0, 800.0, 600.0 );
    scene->setBackgroundBrush(QPixmap(":/Images/bg.png"));

    //try to connect buttons to actions on scene
    connect(p1Button1, SIGNAL (clicked()), scene, SLOT (setTowerBuildModeOn())); //if pressed, go into tower build mode
    connect(p1Button1, SIGNAL (clicked()), scene, SLOT (setTower1ToBeBuilt()));

    connect(p1Button2, SIGNAL (clicked()), scene, SLOT (setTowerBuildModeOn())); //if pressed, go into tower build mode
    connect(p1Button2, SIGNAL (clicked()), scene, SLOT (setTower2ToBeBuilt()));

    connect(p1Button3, SIGNAL (clicked()), scene, SLOT (setTowerBuildModeOn())); //if pressed, go into tower build mode
    connect(p1Button3, SIGNAL (clicked()), scene, SLOT (setTower3ToBeBuilt()));

    //connect the labels to update with time
    connect(scene, SIGNAL (updateP1Resources(QString)), p1Res, SLOT (setText(QString)));
    connect(scene, SIGNAL (updateP2Resources(QString)), p2Res, SLOT (setText(QString)));

    connect(scene, SIGNAL(updateP1Lives(QString)),p1Lives, SLOT(setText(QString)));
    connect(scene, SIGNAL (updateTimer(QString)), p0Timer, SLOT(setText(QString)));

    //connect the description labels based on what is selected
    connect(scene, SIGNAL (updateP1Desc(QString)), p1Desc, SLOT (setText(QString)));
    connect(scene, SIGNAL (updateP2Desc(QString)), p2Desc, SLOT (setText(QString)));

    //setting the game to start on input
    connect(start, SIGNAL (startGame()), this, SLOT(startScreen()));

    //setting the winscreen
    connect(scene, SIGNAL (P1Win()), this, SLOT(P1WinScreen()));
    connect(scene, SIGNAL (P2Win()), this, SLOT(P2WinScreen()));

    timer = new QTimer( this );
    QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));


    // Horizontal layout contains P1 Buttons, description, resources/lives
    QHBoxLayout * const hLayout = new QHBoxLayout;
        hLayout->addWidget( p1Button1 );        //Add Buttons to layout, set fixed size
        p1Button1->setFixedSize( 100, 30 );
        hLayout->addWidget( p1Button2 );
        p1Button2->setFixedSize( 100, 30 );
        hLayout->addWidget( p1Button3 );
        p1Button3->setFixedSize( 110, 30);

        hLayout->addWidget( p1Desc );       //Add Labels to layout
        hLayout->addWidget( p1Res );
        hLayout->addWidget( p1Lives );

    // Second horiz layout contains p2's buttons, desc, etc...
    QHBoxLayout * const hLayout2 = new QHBoxLayout;
        hLayout2->addWidget( p2Button1 );
        p2Button1->setFixedSize( 130, 30 );
        hLayout2->addWidget( p2Button2 );
        p2Button2->setFixedSize( 130, 30 );
        hLayout2->addWidget( p2Button3 );
        p2Button3->setFixedSize( 130, 30 );

        hLayout2->addWidget( p2Desc );
        hLayout2->addWidget( p2Res );
        hLayout2->addWidget( p0Timer );

    vLayout->addLayout( hLayout );      // Add horiz top layout to vertical layout
    vLayout->addWidget( view );         // Add GraphicsView to vertical layout
    vLayout->addLayout( hLayout2 );     // Add horiz bottom layout to vertical layout


    QWidget * w = new QWidget();
    w->setLayout(vLayout);
    w->setFixedSize(824,766);
    w->show();
}

void MainWindow::startScreen()
{   
    this->view->setScene( this->scene );
    this->timer->start(40);
}

void MainWindow::P1WinScreen()
{
    Scene *end1 = new Scene();
    end1->setSceneRect( 0.0, 0.0, 800.0, 600.0 );
    end1->setBackgroundBrush(QPixmap(":/Images/p1Wins.png"));
    this->view->setScene( end1 );
}

void MainWindow::P2WinScreen()
{
    Scene *end2 = new Scene();
    end2->setSceneRect( 0.0, 0.0, 800.0, 600.0 );
    end2->setBackgroundBrush(QPixmap(":/Images/p2Wins.png"));
    this->view->setScene( end2 );
}

MainWindow::~MainWindow()
{

}






