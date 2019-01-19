#include "warriorant.h"

WarriorAnt::WarriorAnt(Field*field):Ant(field)
{
    setPixmap(QPixmap(":/fireantt.png").scaled(QSize(35,35)));

    setZValue(1);
    setHitPoints(100);
    setFlag(QGraphicsItem :: ItemIsSelectable);
    setFlag(QGraphicsItem :: ItemIsFocusable);

    QTimer * attackEnemyTimer = new QTimer(this);
    connect(attackEnemyTimer,SIGNAL(timeout()),this,SLOT(attack()));
    attackEnemyTimer->start(1000);

}

void WarriorAnt::attack()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size();i++)
    {
        if(dynamic_cast<Enemy*>(colliding_items[i]))
           {
                dynamic_cast<Enemy*>(colliding_items[i])->setHitpoints(getHitPoints() - 50);
           }

        if(dynamic_cast<Boss*>(colliding_items[i]))
           {
                dynamic_cast<Boss*>(colliding_items[i])->setHitpoints(  50);
           }

    }
}
