#ifndef POPULATIONGRAPHICLABEL_H
#define POPULATIONGRAPHICLABEL_H

#include <QGraphicsTextItem>
#include <Qpainter>

class PopulationGraphicLabel : public QGraphicsTextItem
{
public:
    PopulationGraphicLabel(const QString &text) : QGraphicsTextItem(text){}

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // POPULATIONGRAPHICLABEL_H
