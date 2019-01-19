#include "enemy.h"


int Enemy::getHitpoints() const
{
    return hitpoints;
}

void Enemy::setHitpoints(int value)
{
    hitpoints = value;
    if(hitpoints <= 0)
    {
       field->getEnemies().removeOne(this);
       scene()->removeItem(this);
       QPointF deathPos = this->scenePos();
       emit isACorpse(deathPos);

       delete this;
       return;
    }
}

Enemy::Enemy(Field * field, QGraphicsItem *parent) : QObject(),QGraphicsPixmapItem(parent),field(field)
{
    hitpoints = 200;
    setPixmap(QPixmap(":/enemyy.png").scaled(QSize(30,30)));
    qreal x,y;
    setZValue(2);
   do
    {
        x = rand() % SCENE_WIDTH;
        y = rand() % SCENE_HEIGHT;

    }while((x > ANTHILL_POS_X_AXIS - 300 && x < ANTHILL_POS_X_AXIS + 300) && (y >ANTHILL_POS_Y_AXIS - 300 && y < ANTHILL_POS_Y_AXIS + 300));

    setPos(x,y);

    QTimer * moveEnemyTimer = new QTimer(this);
    connect(moveEnemyTimer,SIGNAL(timeout()),this,SLOT(move()));
    moveEnemyTimer->start(500);

    QTimer * attackEnemyTimer = new QTimer(this);
    connect(attackEnemyTimer,SIGNAL(timeout()),this,SLOT(attack()));
    attackEnemyTimer->start(5000);

    connect(this,SIGNAL(isACorpse(QPointF)),field,SLOT(spawnCorpseFood(QPointF)));
    connect(this,SIGNAL(isDead()),field,SLOT(updateScore()));




}



void Enemy::move()
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

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle() + 90);
}



Enemy::~Enemy()
{
    emit isDead();
}

void Enemy::attack()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size();i++)
        {
        if(dynamic_cast<AntHill*>(colliding_items[i]))
           {field->getAntHill()->setHitpoints(20);}
        if(dynamic_cast<Ant*>(colliding_items[i]))
           {
             /* for(int j = 0; j < field->getEnemies().size(); j++)
            {
                if(colliding_items[i] == field->getEnemies().at(j))
                {field->getEnemies().at(j)->setHitpoints(field->getEnemies().at(j)->getHitpoints()- 20);}
            }*/

             dynamic_cast<Ant*>(colliding_items[i])->setHitPoints(getHitpoints() - 20);
            }
        }

}

