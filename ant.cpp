#include "ant.h"
#include "field.h"
#include <qmath.h>


int Ant::getHitPoints() const
{
    return hitPoints;
}

void Ant::setHitPoints(int value)
{
    hitPoints = value;

    if(hitPoints <= 0)
    {
       field->getAnts().removeOne(this);
       scene()->removeItem(this);
       QPointF deathPos = this->scenePos();
       emit isACorpse(deathPos);

       delete this;
       return;
    }
}



void Ant::move()
{
    qreal x_dest = dest.x() ;
    qreal y_dest = dest.y() ;


    qreal x      = this->scenePos().x();
    qreal y      = this->scenePos().y();

     qreal dx = (x_dest - x);
     qreal dy = (y_dest - y);

     QLineF ln(pos(),dest);

        rotateToPoint();
        int STEP_SIZE = 1;
        double theta = rotation(); // degrees
        qreal angle = asin(ln.dy()/sqrt(ln.dx()*ln.dx() + ln.dy() * ln.dy()));
        dy = STEP_SIZE * qSin(qDegreesToRadians(angle));
        dx = STEP_SIZE * qCos(qDegreesToRadians(angle));
       // qreal compensateFactorX=  2/ln.dx();
        //qreal compensateFactorY=  2/ln.dy();

        setPos(this->x()+ln.dx()/20, this->y()+ln.dy()/20);


    /*if(1)
    {
        if(this->scenePos().x() < x_dest)
        {rotateToPoint();setPos(x + cos(angle)*10,y+sin(angle)*10);}
        else
        {rotateToPoint();setPos(x - cos(angle)*10,y+sin(angle)*10);}

    }
    else{return;}*/



}

void Ant::rotateToPoint()
{
    QLineF ln(pos(),dest);
    setRotation(-1 * ln.angle() + 90);
}





QTimer *Ant::getMovetimer() const
{
    return movetimer;
}

void Ant::setDest(const QPointF &value)
{
    dest = value;
}

Field *Ant::getField() const
{
    return field;
}

Ant::Ant(Field * field,QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent), field(field)
{
    movetimer = new QTimer(this);
    connect(movetimer,SIGNAL(timeout()),this,SLOT(move()));
    connect(this,SIGNAL(isACorpse(QPointF)),field,SLOT(spawnCorpseFood(QPointF)));
    movetimer->start(50);
    setPos(ANTHILL_POS_X_AXIS - 100 + rand() % 200,ANTHILL_POS_Y_AXIS + -100 + rand() % 200);
    setFlag(QGraphicsItem::ItemIsSelectable, true);


}

Ant::~Ant()
{

}
