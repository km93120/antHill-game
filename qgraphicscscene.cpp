#include "qgraphicscscene.h"
#include <QGraphicsView>
QGraphicsCScene::QGraphicsCScene(Field*field) : QGraphicsScene(), field(field)
{
    connect(this,SIGNAL(destinationPoint(QPointF)),field,SLOT(moveSlctedAnts(QPointF)));

}

void QGraphicsCScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

            qDebug() << "yaay";
            field->setDragMode(QGraphicsView::RubberBandDrag);
            QList <QGraphicsItem*> slctedAntsTemp = this->selectedItems();
            qDebug() <<"yooy";



             field->setSlctedAnts(slctedAntsTemp);




    qDebug() << "scene clicked at " << mouseEvent->scenePos();
    QPointF dest = mouseEvent->scenePos();
    emit destinationPoint(dest);
    qDebug() << slctedAntsTemp.length();
    qDebug() << field->getSlctedAnts().length();


}



QGraphicsCScene::~QGraphicsCScene()
{

}
