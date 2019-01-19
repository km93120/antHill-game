#ifndef FOOD_H
#define FOOD_H

#include "constants.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Food : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

    int pointsDeVie;




public:
    Food(QGraphicsItem * parent=0);
      ~Food();

public slots:

};

#endif // FOOD_H
