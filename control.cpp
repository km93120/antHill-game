#include "control.h"

Control::Control( Field *field)
{

    field->setControl(this);

    QTimer * enemySpawntimer = new QTimer(this);
    QTimer * foodSpawntimer  = new QTimer(this);
    QTimer * musicTimer =      new QTimer(this);
    connect(enemySpawntimer,SIGNAL(timeout()),field,SLOT(spawnEnemy()));
    connect(foodSpawntimer,SIGNAL(timeout()),field,SLOT(spawnFood()));
    connect(musicTimer,SIGNAL(timeout()),field,SLOT(musicc()));
    QTimer::singleShot(500,field,SLOT(musicc()));
    enemySpawntimer->start(5000);
    foodSpawntimer ->start(5000);
    musicTimer->start(79000);


}




Control::~Control()
{

}
