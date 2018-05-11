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
#include <random>
#include <list>
#include "continent.h"
//Debug
#include <iostream>
#include <iomanip>


struct disasterOcurance
{
    int xPos;      //amount right
    int yPos;      //amount down
    int magnitude; //based on disater casualties amount
    QColor color;     //based on disaster type

    disasterOcurance(){} //FIX ME: add default values as needed
};


class worldMapFillLayer : public QGraphicsItem
{
private:
    std::string continentName;
    QPixmap fillImage;
    float fillOpacity;          //How much opacity the population overlay has
    float landArea;             //Continent's total land area (used for opacity)
    float fillMultiplier;       //Increase opacity growth rate (equal for all continents = unbiased)

    std::list<disasterOcurance*> disasterDots;
    Continent* backendContinent; //Pointer to apropriate continent object w/ calculations

public:
    //Constructors for the fill layers
    worldMapFillLayer();
    worldMapFillLayer(std::string continent,
                      double area,
                      double fillMultiplier = 1.0,
                      double initOpacity = 0.0);

    //DEBUG disaster indicators
    void addSampleDisasterIndicators();

    //~worldMapFillLayer(); (Possibly handled by QT)
    //(disasterOcurance pointers might need to be deleted)

    //Required to set the size of image
    QRectF boundingRect() const;

    //Repaints continent layers upon repaint event or request by timer
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    //Grabs the current population amount
    void calculateState(bool running, double population);

    //Adds any disaster infos queued up for disaster dot list
    void grabDisasterInfo();

    //Returns the correct disaster indicator color for painter to apply
    QColor determineDisasterDotColor(std::string type);

    //Sets the image of the population overlay
    void setPixmap(std::string landName = "Other");

    //[ACCESSORS/MUTATORS]
    QPixmap getFillImage();
};

#endif // WORLDMAPANIMATION_H
