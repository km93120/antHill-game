#include "food.h"

Food::Food(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/food.jpg").scaled(QSize(20,20)));
    qreal x,y;
    setZValue(2);
   do
    {
        x = rand() % SCENE_WIDTH;
        y = rand() % SCENE_HEIGHT;

    }while((x >ANTHILL_POS_X_AXIS - 250   && x < ANTHILL_POS_X_AXIS + 250) && (y > ANTHILL_POS_Y_AXIS -250  && y < ANTHILL_POS_Y_AXIS +250));

    setPos(x,y);



}


Food::~Food()
{

}
