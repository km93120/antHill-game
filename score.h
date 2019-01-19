#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
    int score;
public:
    Score(QGraphicsItem * parent=0);
    int getScore() const;
    void setScore(int value);
    void increaseScore();

};

#endif // SCORE_H
