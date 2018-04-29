#ifndef WORLDMAPFILLLAYER_H
#define WORLDMAPFILLLAYER_H

#include <QPixmap>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <algorithm>
#include <string>
//Debug
#include <iostream>
#include <iomanip>

class worldMapFillLayer : public QGraphicsItem
{
private:
    QPixmap fillImage;
    float fillOpacity;
    std::string continentName;
    float landArea;
    float fillMultiplier;

public:
    //Constructors for the fill layers
    worldMapFillLayer();
    worldMapFillLayer(std::string continent,
                      double area,
                      double fillMultiplier = 1.0,
                      double initOpacity = 0.0);

    QRectF boundingRect() const;//Required to set the size of image

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void calculateState(bool running, double population);

    void setPixmap(std::string landName = "Other");

    //[ACCESSORS/MUTATORS]
    QPixmap getFillImage();
};

#endif // WORLDMAPANIMATION_H
