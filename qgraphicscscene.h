#ifndef QGRAPHICSCSCENE_H
#define QGRAPHICSCSCENE_H
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QRubberBand>
#include <field.h>

class Field;

class QGraphicsCScene : public QGraphicsScene   //custom scene
{
    Q_OBJECT
    Field * field;

   void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) override;

public:
    QGraphicsCScene(Field * field);




    ~QGraphicsCScene();

signals:
    void destinationPoint(QPointF dest);
};

#endif // QGRAPHICSCSCENE_H
