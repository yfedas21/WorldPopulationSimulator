#include "worldMapFillLayer.h"


//[Constructors]
worldMapFillLayer::worldMapFillLayer()
{
    name = "Other";
    fillOpacity = 0.0;
    landArea = 10.0;
    fillMultiplier = 1.0;
    qCritical("Error: DO NOT DECLARE A FILL LAYER W/O ANY IMAGE - Loaded default values");
};

/**
 * @brief worldMapFillLayer::worldMapFillLayer - main constructor used for
 * creating overlay layers with basic info on the continent they cover
 * @param continent - name of the globe's continent
 * @param area - land area for the particular continent (10^-6 scale)
 * @param fillMultiplier - fill amount per (population/area)
 * @param initOpacity - initial fill of continent
 * @param continentCenter - center of continent region on QGraphicsView
 * @param continentSize - size of continent region in QGrapicsView
 */
worldMapFillLayer::worldMapFillLayer(QGraphicsTextItem* shownPop,
                                     std::string continent,
                                     double area,
                                     SimDeltaOutcome* animInfo,
                                     double fillMultiplier,
                                     double initOpacity,
                                     QPoint continentCenter,
                                     QPoint continentSize)
{
    this->shownPop = shownPop;
    name = continent;
    setPixmap(name);
    landArea = area * 1000000; //conversion to actual area
    info = animInfo;
    this->fillMultiplier = fillMultiplier;
    fillOpacity = initOpacity;
    this->continentCenter = continentCenter;
    this->continentSize = continentSize;
}

/**
    @brief worldMapFillLayer::updateLayers - Updates the opacity for current fill layer
    @param day - tells which day to update the animation for
*/
void worldMapFillLayer::updateLayers(int day)
{
    if(info->snapshots.empty()){
        fillOpacity = 0;
        shownPop->setPlainText("0");
        return;
    }

    //Update Values for next frame
    // - Layer opacity
    fillOpacity = std::fmin(1, (info->snapshots[day].continents[name].totalPop/landArea) * fillMultiplier);
    // - Simulation day
    simDay = day;

    //Configure any incomplete disaster dots
    for(std::list<disasterOccurrence>::iterator iterator = info->snapshots[day].continents[name].disasters.begin();
        iterator != info->snapshots[day].continents[name].disasters.end(); ++iterator){
        if(!(*iterator).complete)
        {
            (*iterator).dotPos = getNewIndicatorPosition();
            (*iterator).color = determineDisasterDotColor("default"); //FIXME: Add different colors for different types
            (*iterator).complete = true;
        }
    }

    //Population # label
    shownPop->setPlainText(QString::number(info->snapshots[simDay].continents[name].totalPop));

    //DEBUG CODE
    //if(name == "NorthAmerica"){
    //   std::cout << std::showpoint << std::fixed << std::setprecision(4)
    //              << info->snapshots[day].continents[name].totalPop << "/" << landArea << " * " << fillMultiplier << std::endl;
    //    std::cout << "FillOpacity updated: " << std::showpoint << std::fixed << std::setprecision(4) << fillOpacity << std::endl;
    //}
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

/** @brief Uses equation of inside an elipse to create disaster dots only
 * in the region of the continent on the globe map
 */
QPoint worldMapFillLayer::getNewIndicatorPosition()
{
    int x,y = 0;

    //FIXME: maybe better algorithm exists to fit contraints (than just random)
    while (!(((pow(x-continentCenter.x(),2)/pow(continentSize.x(),2))+(pow(y-continentCenter.y(),2)/pow(continentSize.y(),2)))<1))
    {
        x = rand() % 1510;
        y = rand() % 744;
    }

    return QPoint(x,y);
}

//Paints the continent content layer on to the map
void worldMapFillLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    //Overlay pop intensity layer (red)
    painter->setOpacity(fillOpacity);
    painter->drawPixmap(0,0,1510,744, fillImage);

    //Disaster indicators (past 30 days)
    int counter = simDay - 30;
    while(simDay >= counter || counter <= 0)
    {
        for(auto dot: info->snapshots[counter].continents[name].disasters)
        {
            painter->setBrush(dot.color);
            painter->setOpacity(getIndicatorOpacity(dot.day,simDay));
            painter->drawEllipse(dot.dotPos,(int)dot.magnitude,(int)dot.magnitude);
        }
        counter++;
    }
}

/**
    Returns the opasity for a particular indicator at particular day
    @param dotDay - the tested diaster day info
    @param animDay - the current simulation day
    return calculated opasity of the disaster (based on days passed
*/
double worldMapFillLayer::getIndicatorOpacity(int dotDay, int animDay)
{
    //FIXME: may want to design a "pulsing" animation
    //Disaster dots fading out over the course of 30 days
    double daysPassed = (double) (animDay - dotDay);
    //FIXME: check if Qt automatically makes negative opacity a zero
    return std::max(1 - (daysPassed/30), (double)0);

    //DEBUG CODE
    //std::cout<< std::max(1 - (daysPassed/30),(double) 0) << std::endl;
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


//[OLD DEBUG CODE]
/*Old function for adding sample disaster indicators
void worldMapFillLayer::addSampleDisasterIndicators()
{
    for(int i = 0; i < 100; i++)
    {
        disasterOccurrence curDisasterDot = disasterOccurrence();
        //FIXME: Adjust or make adjustable by users (size of dots)
        curDisasterDot.magnitude = (rand() % 80)/4;
        //FIXME: May want to go further to have the disasters
        //actually cluster where they do in real life
        curDisasterDot.dotPos = getNewIndicatorPosition();
        curDisasterDot.color = determineDisasterDotColor("debug");
        curDisasterDot.day = rand() % 500;
        disasterDots.push_back(curDisasterDot);
    }

    std::cout<<"New Dot at X: "<< curDisasterDot->dotPos.x() << " Y: " << curDisasterDot->dotPos.y() << std::endl;
}
*/
/*Overlay opasity check (for paint method)
std::cout << "Repainted with fill opacity: " << std::showpoint
          << std::fixed << std::setprecision(4)<< fillOpacity << std::endl;
*/
/*Continent disaster indicator region check (for paint method)
painter->setOpacity(.5);//full opasity for disaster indicators
painter->setBrush(QColor(0,0,255,255));
painter->drawEllipse(continentCenter,continentSize.x(),continentSize.y());
*/


