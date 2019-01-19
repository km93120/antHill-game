#include "Menu.h"
#include <QGraphicsTextItem>
#include <QBrush>

Menu::Menu(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,200,50);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::green);
        setBrush(brush);

        // draw the text
        text = new QGraphicsTextItem(name,this);
        int xPos = rect().width()/2 - text->boundingRect().width()/2;
        int yPos = rect().height()/2 - text->boundingRect().height()/2;
        text->setPos(xPos,yPos);

        // allow responding to hover events
        setAcceptHoverEvents(true);
}

void Menu::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Menu::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}

void Menu::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    setBrush(brush);
}
