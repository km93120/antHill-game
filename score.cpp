 #include "score.h"

int Score::getScore() const
{
    return score;
}

void Score::setScore(int value)
{
    score = value;
}

void Score::increaseScore()
{
    setPlainText("Score :" + QString::number(++score));

}



Score::Score(QGraphicsItem *parent)
{
    score = 0;

    setPlainText("Score :" + QString::number(score) );
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

}
