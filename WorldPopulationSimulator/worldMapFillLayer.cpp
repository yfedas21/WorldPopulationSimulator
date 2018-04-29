#include "worldMapFillLayer.h"

//[Constructors]
worldMapFillLayer::worldMapFillLayer()
{
    continentName = "Other";
    fillOpacity = 0.0;
    landArea = 10.0;
    fillMultiplier = 1.0;
    qCritical("Error: DO NOT DECLARE A FILL LAYER W/O ANY IMAGE - Loaded default values");
};

worldMapFillLayer::worldMapFillLayer(std::string continent,
                                     double area,
                                     double fillMultiplier,
                                     double initOpacity)
{
    continentName = continent;
    fillOpacity = initOpacity;
    this->fillMultiplier = fillMultiplier;
    landArea = area;
}

//Updates the opacity for current fill layer
//@param: running - tells wether animation is running
//@param: population - amount of people on the continent
//@param: population - amount of people on the continent
void worldMapFillLayer::calculateState(bool running, double pop)
{
    if(!running)
        return;

    fillOpacity = std::fmin(1, (pop/landArea) * fillMultiplier);
}

//Paints the layer on the map
void worldMapFillLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qInfo("The Map Overlay was repainted");
    painter->setOpacity(fillOpacity);
    painter->drawPixmap(0,0,1510,744, fillImage);
}

//Loads in the needed image
//@param: landName - if not given a parameter will return full overlay
void worldMapFillLayer::getPixmap(QString landName)
{
    //Locate file in directory
    QString location;
    if(landName == "Other")
    {
        location = "://Resources/WorldMapFilled.png";
        qInfo("Warning: the entrire map fill layer was loaded.");
    }
    else //FIXME add checks to see if files actually there
    {
        location = "://Resources/" + landName + ".png";
    }

    //Convert found image to a pix map and store w/ correct resolution
    fillImage = QPixmap(location);
    fillImage = fillImage.scaled(1510, 744, Qt::IgnoreAspectRatio, Qt::FastTransformation);
}


//[ACCESSOR(S)/MUTATOR(S)]
QPixmap worldMapFillLayer::getFillImage()
{
    return fillImage;
}
