#include "field.h"



QList<Ant *> Field::getAnts() const
{
    return ants;

}

void Field::spawnWorkerAnt()
{
    qDebug() << antHill->getHitPoints();
    qDebug() << ants.size();
    if(antHill->getFood() >= 100)
    {

       // WorkerAnt *ant = new WorkerAnt(this);
        ants << new WorkerAnt(this);
        scene->addItem(ants.last());// test plantage
        antHill->setFood(antHill->getFood()-100);
         emit foodSpent();
    }




}

void Field::spawnWarriorAnt()
{
    if(antHill->getFood() >= 100)
    {

       // WarriorAnt *ant = new WarriorAnt(this);
        ants << new WarriorAnt(this);
        scene-> addItem(ants.last());
        antHill->setFood(antHill->getFood()-100);
       emit foodSpent();
    }

}

void Field :: spawnEnemy()
{


       // Enemy * enemy = new Enemy(this);
        enemies << new Enemy(this);
        scene->addItem(enemies.last());
        foodSpent();




}

void Field::spawnFood()
{
    if(foods.count() < 4)
    {
        Food * food = new Food();
        foods << food;
        scene->addItem(food);
    }
    else{return;}


}

void Field::moveSlctedAnts(QPointF destinationPoint)
{
     for(int i = 0;i < slctedAnts.length();i++)
     {

            dynamic_cast<Ant*>(slctedAnts[i])->setDest(destinationPoint);








     }
}

void Field::spawnCorpseFood(QPointF deathPos)
{
    Food * food = new Food();
    foods << food;
    food->setPos(deathPos.x(),deathPos.y());
    scene->addItem(food);
}

void Field::endWorld()
{
    QMessageBox::information(this,"dommage","vous avez perdu");
    delete this;


}

void Field::updateScore()
{
    this->score->increaseScore();
    if(score->getScore() == 2)
    {
        bossBattle();
    }
}

void Field::endGame()
{
    QMessageBox::information(this,"bravo","vous avez gagné");
    delete this;
}

void Field::musicc()
{

    music->setMedia(QUrl("qrc:/bruitcigale.mp3"));
    music->play();
}

void Field::updateFood()
{
    foodtext->setPlainText("Food : " + QString::number(antHill->getFood()));
}



AntHill *Field::getAntHill()
{
    return antHill;
}

QGraphicsCScene *Field::getScene() const
{
    return scene;
}


QList<Food *> Field::getFoods() const
{
    return foods;
}

QList<QGraphicsItem *> Field::getSlctedAnts() const
{
    return slctedAnts;
}

void Field::setSlctedAnts(const QList<QGraphicsItem *> &value)
{
    slctedAnts = value;

}

QList<Enemy *> Field::getEnemies() const
{
    return enemies;
}

Score *Field::getScore() const
{
    return score;
}

void Field::bossBattle()
{
   boss = new Boss(this);

   scene->addItem(boss);
   scene->addWidget(boss->getHealthBar());
   boss->setPos(250,250);

}



 Field::Field()
 {
     antHill = new AntHill(this);
     scene = new QGraphicsCScene(this);

     scene->setSceneRect(0,0,SCENE_WIDTH,SCENE_HEIGHT);
     this->setFixedSize(SCENE_WIDTH,SCENE_HEIGHT);
     setBackgroundBrush(QBrush(QImage(":/aze.png")));
     setScene(scene);
    foodtext = new QGraphicsTextItem("Food :" + QString::number(antHill->getFood()));
    foodtext->setDefaultTextColor(Qt::white);
    foodtext->setFont(QFont("times",16));


    scene->addItem(antHill);
    scene->addItem(foodtext);
    foodtext->setPos(400,930);



    button1 = new QPushButton("ouvriere(A)");
    button2 = new QPushButton("guerriere(Z)");
    button3 = new QPushButton("distance(E)");
    button4 = new QPushButton("tank(R)");

    button1->setShortcut(Qt::Key_A);
    button2->setShortcut(Qt::Key_Z);
    button3->setShortcut(Qt::Key_E);
    button4->setShortcut(Qt::Key_R);

    button1->setGeometry(600,930,100,50);
    button2->setGeometry(700,930,100,50);
    button3->setGeometry(800,930,100,50);
    button4->setGeometry(900,930,100,50);

    score = new Score();
    scene->addItem(score);
    score->setPos(280,930);

    scene->addWidget(antHill->getHealthBar());
    scene->addWidget(button1);
    scene->addWidget(button2);
    scene->addWidget(button3);
    scene->addWidget(button4);




    connect(button1,&QPushButton::clicked,this,&Field::spawnWorkerAnt);
    connect(button2,&QPushButton::clicked,this,&Field::spawnWarriorAnt);
    connect(this,SIGNAL(foodSpent()),this,SLOT(updateFood()));




}



Field::~Field()
{

}
