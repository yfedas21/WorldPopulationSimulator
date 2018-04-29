#ifndef WORLDMAPANIMATION_H
#define WORLDMAPANIMATION_H

#include <QPixmap>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsView>
#include <QDebug>
#include <algorithm>

class worldMapFillLayer
{
private:
    QPixmap fillImage;
    int fillOpacity;
    std::string continentName;
    double landArea;
    double fillMultiplier;

public:
    //Constructors for the fill layers
    worldMapFillLayer();
    worldMapFillLayer(std::string continent,
                      double area,
                      double fillMultiplier = 1.0,
                      double initOpacity = 0.0);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void calculateState(bool running, double populationLandRatio);

    void getPixmap(QString landName = "Other");

    //[ACCESSORS/MUTATORS]
    QPixmap getFillImage();
};

#endif // WORLDMAPANIMATION_H
