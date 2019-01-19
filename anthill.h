#ifndef ANTHILL_H
#define ANTHILL_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QProgressBar>

#include "constants.h"
#include "enemy.h"


class AntHill : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int             hitPoints;
    int             food;
    QProgressBar *  healthBar;
    Field        *  field;

public:
    AntHill(Field * field, QGraphicsItem * parent=0);
   ~AntHill();

    int  getFood() const;
    void setFood(int value);
    void setHitpoints(int);
    int  getHitPoints() const;

    QProgressBar *getHealthBar() const;

signals:
   void hitPointsValueChanged();
   void anthillDESTROYED();
   void foodGathered();
public slots:

    void closeFood();

    void updateHealthBar();



};

#endif // AntHill_H
