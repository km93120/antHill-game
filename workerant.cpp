#include "workerant.h"



void WorkerAnt::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    qDebug() << "j'ai le focus !";
    setFocus();
    qDebug() << event->scenePos();
}

void WorkerAnt::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0;i < colliding_items.size();i++)
    {
        if(dynamic_cast<Food*>(colliding_items[i]))
        {
            colliding_items[i]->setPos(this->x(),this->y() );

        }
    }



}

WorkerAnt::WorkerAnt(Field*field) : Ant(field)
{
    setPixmap(QPixmap(":/frmi.jpg").scaled(QSize(25,25)));
    setZValue(1);
    setHitPoints(100);
    setFlag(QGraphicsItem :: ItemIsSelectable);


    QTimer * moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()),this,SLOT(move()));
    moveTimer->start(10);



}



WorkerAnt::~WorkerAnt()
{

}

void WorkerAnt::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 1024)
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
            setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
            setPos(x(),y()+10);
    }
}


