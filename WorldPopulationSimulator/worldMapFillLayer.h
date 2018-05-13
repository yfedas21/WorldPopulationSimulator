#ifndef WORLDMAPFILLLAYER_H
#define WORLDMAPFILLLAYER_H

#pragma once

#include <QPixmap>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <random>
#include <list>
#include "continent.h"
#include "disasterOccurance.h"
//Debug
#include <iostream>
#include <iomanip>

class worldMapFillLayer : public QGraphicsItem
{
private:
    std::string continentName;
    QPixmap fillImage;
    float fillOpacity;          //How much opacity the population overlay has
    float landArea;             //Continent's total land area (used for opacity)
    float fillMultiplier;       //Increase opacity growth rate (equal for all continents = unbiased)

    std::list<disasterOcurance*> disasterDots;
    QPoint continentCenter;
    QPoint continentSize;
    Continent* backendContinent; //Pointer to apropriate continent object w/ calculations
    int simDay;

public:
    //Constructors for the fill layers
    worldMapFillLayer();
    worldMapFillLayer(std::string continent,
                      double area,
                      double fillMultiplier = 1.0,
                      double initOpacity = 0.0,
                      QPoint continentCenter = QPoint(0,0),
                      QPoint continentSize = QPoint(10,10));

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
    void calculateState(bool running, double population, int day);

    //Adds any disaster infos queued up for disaster dot list
    void grabDisasterInfo();

    //Returns the correct disaster indicator color for painter to apply
    QColor determineDisasterDotColor(std::string type);

    //Returns the opasity for a particular indicator at particular day
    double getIndicatorOpacity(int dotDay, int animDay);

    //Returns a disater point position within continent range
    QPoint getNewIndicatorPosition();

    //Sets the image of the population overlay
    void setPixmap(std::string landName = "Other");

    //[ACCESSORS/MUTATORS]
    QPixmap getFillImage();
};

#endif // WORLDMAPANIMATION_H
