#ifndef WORKERANT_H
#define WORKERANT_H

#include <QObject>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "ant.h"
#include "constants.h"
#include "food.h"
#include <QKeyEvent>

class WorkerAnt : public Ant
{
    Q_OBJECT



   // QMouseEvent                 mouseEvent;

protected :
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:

public slots:


    void move();
public:






    WorkerAnt(Field * field);
    ~WorkerAnt();
    void keyPressEvent(QKeyEvent *event);
};

#endif // WORKERANT_H
