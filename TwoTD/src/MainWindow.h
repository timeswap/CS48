#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QWidget>
#include <Scene.h>
#include <QKeyEvent>

class QPushButton;
class QLabel;
class QGraphicsView;
class Scene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:
    void startScreen(); //puts up the screen after the game starts
    void P1WinScreen(); //puts up the screen if p1 wins
    void P2WinScreen();  //puts up the screen if p2 wins

private:
    Scene *scene;
    QTimer *timer;
    QGraphicsView *view;
    QPushButton* p1Button1;
    QPushButton* p1Button2;
    QPushButton* p1Button3;
    QPushButton* p2Button1;
    QPushButton* p2Button2;
    QPushButton* p2Button3;
    QLabel* p1Desc;
    QLabel* p1Res;
    QLabel* p1Lives;
    QLabel* p2Desc;
    QLabel* p2Res;
    QLabel* p0Timer;

};

#endif // MAINWINDOW_H
