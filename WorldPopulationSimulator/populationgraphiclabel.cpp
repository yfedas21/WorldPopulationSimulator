#include "populationGraphicLabel.h"

//Adapted from...
//https://stackoverflow.com/questions/15684277/how-to-change-background-of-qgraphicstextitem

void PopulationGraphicLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *o, QWidget *w)
{

    painter->setOpacity(.5);
    painter->setBrush(Qt::yellow);
    painter->drawRect(boundingRect());
    painter->setOpacity(1);
    QGraphicsTextItem::paint(painter,o,w);
}
