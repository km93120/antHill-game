#ifndef ENEMY_H
#define ENEMY_H

#include "field.h"
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPoint>
#include <QTimer>
#include <cstdlib>
#include "constants.h"
#include "anthill.h"

class Field;


class AntHill;

class Enemy : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
protected:

   Field    *      field;
   int             hitpoints;



public:

    Enemy(Field *field, QGraphicsItem * parent=0);
    ~Enemy();


    void rotateToPoint(QPointF p);





    int getHitpoints() const;
    void setHitpoints(int value);

public slots:
    void attack();
    void move();
signals:
    void isDead();
    void isACorpse(QPointF);
};

#endif // ENEMY_H
