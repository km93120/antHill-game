#ifndef FIELD_H
#define FIELD_H


#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QPushButton>
#include <QMessageBox>
#include <QMediaPlayer>

#include "warriorant.h"
#include "constants.h"
#include "anthill.h"
#include "ant.h"
#include "enemy.h"
#include "food.h"
#include "workerant.h"
#include "qgraphicscscene.h"
#include "score.h"
#include "control.h"
#include "boss.h"
#include "menu.h"


class Boss;
class Ant;
class Control;
class AntHill;
class Enemy;
class QGraphicsCScene;


class Field : public QGraphicsView
{
    Q_OBJECT



private :

    Control            *          control;

    QList <Ant *>                 ants;
    QList <Enemy *>               enemies;
    QList <Food *>                foods;
    QList <QGraphicsItem *>       slctedAnts;

    QGraphicsCScene*    scene;
    AntHill        *    antHill;
    QPushButton    *    button1;
    QPushButton    *    button2;
    QPushButton    *    button3;
    QPushButton    *    button4;

    QMediaPlayer   *    music = new QMediaPlayer();
    Score          *    score;
    Boss            *   boss;

    QGraphicsTextItem * foodtext;




public:

     Field();
    ~Field();

     QList <Ant *> getAnts() const;
     AntHill *getAntHill();
     QGraphicsCScene *getScene() const;

     void setControl(Control *control) {
         this->control = control;
     }





     QList<Food *> getFoods() const;


     QList<QGraphicsItem *> getSlctedAnts() const;

     void setSlctedAnts(const QList<QGraphicsItem *> &value);

     QList<Enemy *> getEnemies() const;

     Score *getScore() const;
     void bossBattle();



     void displayMainMenu();
protected:

signals:
     void destinationPoint(QPointF);
     void foodSpent();

public slots:

    void spawnWorkerAnt();
    void spawnWarriorAnt();
    void spawnEnemy();
    void spawnFood();
    void moveSlctedAnts(QPointF destinationPoint);
    void spawnCorpseFood(QPointF deathPos);
    void endWorld();
    void updateScore();
    void endGame();
    void musicc();
    void updateFood();



};

#endif // FIELD_H
