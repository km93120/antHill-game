#include "anthill.h"

int AntHill::getFood()const
{
    return food;
}

void AntHill::setFood(int value)
{
    food = value;
}

void AntHill::setHitpoints(int value)
{
      hitPoints -= value;
      emit hitPointsValueChanged();
}

QProgressBar *AntHill::getHealthBar() const
{
    return healthBar;
}

void AntHill::closeFood()
{
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size();i++)
    {
        if(dynamic_cast<Food*>(colliding_items[i]))
        {
           food += 100;

           delete colliding_items[i];
           emit foodGathered();
        }
    }
}

void AntHill::updateHealthBar()
{
    if(hitPoints <= 0)
    {
        delete healthBar;
        scene()->removeItem(this);
        delete this;
        return;
    }
    healthBar->setValue(hitPoints);
    healthBar->setFormat(QString::number(hitPoints) + "/" + QString::number(HITPOINTS_MAX_ANTHILL) );

}

int AntHill::getHitPoints() const
{
    return hitPoints;
}

AntHill::AntHill(Field* field,QGraphicsItem *parent): QObject(),QGraphicsPixmapItem (parent),field(field)
{

        hitPoints = HITPOINTS_MAX_ANTHILL;
        food = 3000;
        QPixmap *pixmap = new QPixmap(":/images.jpg");
        setPixmap(*pixmap);
        setPos(ANTHILL_POS_X_AXIS-(pixmap->width()/2),ANTHILL_POS_Y_AXIS-(pixmap->height()/2));

        healthBar = new QProgressBar();
        healthBar->setOrientation(Qt::Horizontal);
        healthBar->setRange(0,hitPoints);
        healthBar->setToolTip("Health");
        healthBar->setGeometry(ANTHILL_POS_X_AXIS-(pixmap->width()/2), ANTHILL_POS_Y_AXIS + (pixmap->height()/2),pixmap->width(),20);
        healthBar->setValue(hitPoints);
        healthBar->setFormat(QString::number(hitPoints) + "/" + QString::number(HITPOINTS_MAX_ANTHILL));


        connect(this,SIGNAL(hitPointsValueChanged()),this,SLOT(updateHealthBar()));
        QTimer * closeFoodCheckTimer = new QTimer(this);
        connect(closeFoodCheckTimer,SIGNAL(timeout()),this,SLOT(closeFood()));
        closeFoodCheckTimer->start(1000);

        connect(this,SIGNAL(anthillDESTROYED()),field,SLOT(endWorld()));

        connect(this,SIGNAL(foodGathered()),field,SLOT(updateFood()));
}

AntHill::~AntHill()
{
    emit anthillDESTROYED();
}
