#include "boss.h"

QProgressBar * Boss::getHealthBar() const
{
    return healthBar;
}

int Boss::getHitpoints() const
{
    return hitpoints;
}

void Boss::setHitpoints(int value)
{
    hitpoints -= value;
    emit hitpointsValueChanged();
}

void Boss::attack()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size();i++)
        {
       qDebug() << "attaque bosss";
        if(dynamic_cast<AntHill*>(colliding_items[i]))
           {field->getAntHill()->setHitpoints(100);}
        if(dynamic_cast<Ant*>(colliding_items[i]))
           {

              dynamic_cast<Ant*>(colliding_items[i])->setHitPoints(dynamic_cast<Ant*>(colliding_items[i])->getHitPoints() - 5 );
           }
        }
}

void Boss::updateHealthBar()
{
    if(hitpoints <= 0)
    {
        delete healthBar;
        scene()->removeItem(this);
        delete this;
        return;
    }
    healthBar->setValue(hitpoints);
    healthBar->setFormat(QString::number(hitpoints) + "/" + QString::number(HITPOINTS_MAX_BOSS));
}


void Boss::move()
{

    qreal x_dest = ANTHILL_POS_X_AXIS ;
    qreal y_dest = ANTHILL_POS_Y_AXIS ;


    qreal x      = this->scenePos().x();
    qreal y      = this->scenePos().y();

    qreal dx = (x_dest - x);
    qreal dy = (y_dest - y);


    QPointF dest(x_dest,y_dest);

    qreal angle = asin(dy/sqrt(dx*dx + dy * dy));
    if(this->scenePos().x() < ANTHILL_POS_X_AXIS)
    {rotateToPoint(dest);setPos(x + cos(angle)*10,y+sin(angle)*10);}
    else
    {rotateToPoint(dest);setPos(x - cos(angle)*10,y+sin(angle)*10);}



}

void Boss::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle() + 90);
}


Boss::Boss(Field * field,QGraphicsItem *parent) : QObject(),QGraphicsPixmapItem(parent),field(field)
{


    hitpoints = 20000;
    setPos(250,250);
    setPixmap(QPixmap(":/mygale.jpg").scaled(250,250));
    healthBar = new QProgressBar();
    healthBar->setOrientation(Qt::Horizontal);
    healthBar->setRange(0,hitpoints);
    healthBar->setToolTip("Health");
    healthBar->setGeometry(5,20,800,20);
    healthBar->setValue(hitpoints);
    healthBar->setFormat(QString::number(hitpoints) + "/" + QString::number(HITPOINTS_MAX_BOSS));
    connect(this,SIGNAL(hitpointsValueChanged()),this,SLOT(updateHealthBar()));
    connect(this,SIGNAL(victory()),field,SLOT(endGame()));
    QTimer * moveTimer = new QTimer(this);
    connect(moveTimer,SIGNAL(timeout()),this,SLOT(move()));
    moveTimer->start(1000);

    QTimer * attackTimer = new QTimer(this);
    connect(attackTimer,SIGNAL(timeout()),this,SLOT(attack()));
    attackTimer->start(500);












}

Boss::~Boss()
{
    emit victory();
}
