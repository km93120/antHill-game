#ifndef ANT_H
#define ANT_H


#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "food.h"


class Food;


class Field;


class Ant : public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
protected:

     int         hitPoints;
     QTimer  *   movetimer;

     QPointF     dest;
     Field   *   field;


public:
     Ant(Field * field ,QGraphicsItem * parent=0);
    ~Ant();
     int getHitPoints() const;
     void setHitPoints(int value);


     void rotateToPoint();
     QTimer *getMovetimer() const;
     void setDest(const QPointF &);
     Field *getField() const;
signals:
     void isACorpse(QPointF deathPos);

public slots:
     void move();
};

#endif
