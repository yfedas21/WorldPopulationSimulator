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
    setPixmap(continentName);
    fillOpacity = initOpacity;
    this->fillMultiplier = fillMultiplier;
    landArea = area;
    addSampleDisasterIndicators();
}

//DEBUG FUNCTION FOR DISASTER INDICATORS
void worldMapFillLayer::addSampleDisasterIndicators()
{
    if(continentName != "Africa")
        return;

    for(int i = 0; i < 100; i++)
    {
        disasterOcurance * curDisasterDot = new disasterOcurance();
        //FIXME: Adjust or make adjustable by users (size of dots)
        curDisasterDot->magnitude = (rand() % 100)/3;
        //FIXME: Use the within elipse formula for more visually apealing results
        //May even want to go further to have the disasters actually cluster where they do in real life
        //https://math.stackexchange.com/questions/76457/check-if-a-point-is-within-an-ellipse
        curDisasterDot->xPos = rand() % 1510; //FIXME: For now anywhere on screen horizontally
        curDisasterDot->yPos = rand() % 744; //FIXME: For now anywhere on screen vertically
        curDisasterDot->color = determineDisasterDotColor("debug");
        curDisasterDot->day = rand() % 1000;
        disasterDots.push_back(curDisasterDot);
    }

}

//Updates the opacity for current fill layer
//@param: running - tells wether animation is running
//@param: population - amount of people on the continent
void worldMapFillLayer::calculateState(bool running, double population, int day)
{
    if(!running) //FIXME: add check to see if sim is complete
        fillOpacity = 0.0;

    fillOpacity = std::fmin(1, (population/landArea) * fillMultiplier);

    simDay = day;

    //DEBUG CODE
    //std::cout << std::showpoint << std::fixed << std::setprecision(4) << fillOpacity
    //          << population << "/" << landArea << " * " << fillMultiplier << std::endl;
    //std::cout << "FillOpacity updated: " << std::showpoint << std::fixed << std::setprecision(4) << fillOpacity << std::endl;
}

//Adds any disaster infos queued up for disaster dot list
void worldMapFillLayer::grabDisasterInfo()
{
    if(backendContinent == NULL)
        return;

    //FIXME: Finish implementation when backend complete
    //Continent->setDataRetrival(true); //may need if multithreading issues arrise
    //Want to transfer all info to plot data erasing the data in backend
    /*while(disasterPendingPlot.front() != NULL)
    {
        disasterOcurance * curDisasterDot = new disasterOcurance();
        //FIXME: Adjust or make adjustable by users (size of dots)
        curDisasterDot->magnitude = disasterPendingPlot.front().deaths / 30;
        //FIXME: Use the within elipse formula for more visually apealing results
        //May even want to go further to have the disasters actually cluster where they do in real life
        //https://math.stackexchange.com/questions/76457/check-if-a-point-is-within-an-ellipse
        curDisasterDot->xPos = rand() % 1510;//FIXME: For now anywhere on screen horizontally
        curDisasterDot->yPos = rand() % 744;//FIXME: For now anywhere on screen vertically
        curDisasterDot->color = determineDisasterDotColor(disasterPendingPlot.front().type);
        disasterDots.push_back(curDisasterDot);
        curDisasterDot->day = disasterPendingPlot.front().dayOccured;
        disasterPendingPlot.pop();
    }*/
    //Continent->setDataRetrival(false); //may need if multithreading issues arrise
}

//Finds the correct disaster indicator color for painter to apply when drawing the dot
//@param: type - the type of disaster by name
//return: Qcolor of the repective disaster (or/and magnitude)
QColor worldMapFillLayer::determineDisasterDotColor(std::string type)
{
    //FIXME: Complete implementation so different disaster types have different color
    //FIXME: Possible to change this to color based on magnitude of dot (experiment)
    QColor resultColor = QColor(0, 0, 0, 255);
    return resultColor; //black for now
}

//Paints the continent content layer on to the map
void worldMapFillLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //DEBUG CODE
    //std::cout << "Repainted with fill opacity: " << std::showpoint
    //          << std::fixed << std::setprecision(4)<< fillOpacity << std::endl;

    painter->setOpacity(fillOpacity);
    painter->drawPixmap(0,0,1510,744, fillImage);

    painter->setOpacity(1);//full opasity for diaster indicators
    for (auto dot: disasterDots)
    {
        //FIXME: might want to place old indicators into a seperate
        //untouched container for effieciency purposes
        //Skip idicator if too old
        if(dot->day + 30 < simDay)
            continue;

        painter->setBrush(dot->color);
        painter->setOpacity(getIndicatorOpacity(dot->day,simDay));
        painter->drawEllipse(dot->xPos,dot->yPos,dot->magnitude,dot->magnitude);
    }
}

//Gets the current animation day
//(should be a thread safe operation if end up using threads)
//return: the amount of days after animation start
int worldMapFillLayer::grabAnimDay(){

    return simDay;
}

//Returns the opasity for a particular indicator at particular day
//@param: dotDay - the tested diaster day info
//@param: animDay - the current simulation day
//return: calculated opasity of the disaster (based on days passed
double worldMapFillLayer::getIndicatorOpacity(int dotDay, int animDay)
{
    //FIXME: may want to design a "pulsing" animation
    //Disaster dots fading out over the course of 30 days
    int daysPassed = (double) animDay - (double) dotDay;
    //FIXME: check if Qt automatically makes negative opacity a zero
    return std::max(1 - (daysPassed/30), 0);
}

//Loads in the needed image
//@param: landName - the name of globe part to get overlay layer for
void worldMapFillLayer::setPixmap(std::string landName)
{
    //Locate file in directory
    std::string location;
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
    QString strLocation = QString::fromUtf8(location.c_str());
    fillImage = QPixmap(strLocation);
    fillImage = fillImage.scaled(1510, 744, Qt::IgnoreAspectRatio, Qt::FastTransformation);
}


QRectF worldMapFillLayer::boundingRect() const
{
    //All overlays are same dimesion as full map for positioning purposes
    return QRect(0,0,1510,744);
}

//[ACCESSOR(S)/MUTATOR(S)]
QPixmap worldMapFillLayer::getFillImage()
{
    return fillImage;
}

