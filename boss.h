#ifndef BOSS_H
#define BOSS_H

#include "constants.h"
#include <QObject>
#include "enemy.h"
#include "field.h"


class Boss : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
     Field *field;
     int hitpoints;
     QProgressBar *  healthBar;


public:
    Boss(Field*field,QGraphicsItem * parent = 0);
    ~Boss();

    QProgressBar * getHealthBar() const;


    int getHitpoints() const;
    void setHitpoints(int value);

    void rotateToPoint(QPointF p);
public slots:

    void attack();
    void updateHealthBar();

    void move();

signals:

  void hitpointsValueChanged();
  void victory();



};

#endif // BOSS_H
