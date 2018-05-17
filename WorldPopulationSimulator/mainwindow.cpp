#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Create the input/calculation storage class
    simInfo = new Sim_Helper(); //FIXME: check if pointers actually faster
    curSimResults = new SimDeltaOutcome();
    simulator = new Simulator();

    ui->worldMapView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->worldMapView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->worldMapView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    //Scene for the graphics view (where to add items)
    scene = new QGraphicsScene(this);
    ui->worldMapView->setScene(scene);

    //Load the requred Resources for animation to run
    QImage worldMap("://Resources/WorldMap.png");
    worldMapView = QPixmap::fromImage(worldMap);
    worldMapView = worldMapView.scaled(1510, 744, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    //Main simulation driver (declaration)
    simTimer = new QTimer(this);
    connect(simTimer, SIGNAL(timeout()), this, SLOT(calculateOneDay()));

    //Background for the world map
    scene->addPixmap(worldMapView);

    //Date Indicator
    shownDate = new QGraphicsTextItem("XX/XX/XXXX");
    shownDate->setDefaultTextColor(QColor(253,240,34,255));
    shownDate->setFont(QFont("Times", 15, QFont::Bold));
    scene->addItem(shownDate);
    shownDate->setPos(shownDate->mapFromScene(1200,20));

    //Create continent overlays
    createContinentOverlays();

    //Add continent layers to scene
    addContinentsToScene();
    updateAnim(day);
}

//Central function that updates the entire map by going through each continent
void MainWindow::updateAnim(int day)
{
    shownDate->setPlainText(getCurSimDate());

    for(int i = 0; i < (int)continents.size(); i++)
    {
        continents[i]->updateLayers(day);
    }

    QWidget* viewport = ui->worldMapView->viewport();
    viewport->repaint();
}

//Updates the population amount of each country for one day
void MainWindow::calculateOneDay()
{
    curSimResults->insertNewDay(simulator->run_simulation(day));
    updateAnim(day);
    if(++day > simInfo->runtime)
        simTimer->stop();
}

//Returns the simulation date based on the current days after sim start
QString MainWindow::getCurSimDate()
{
    //FIXME: Investigate if causes a memory leak
    QDate resultDate = simInfo->startDate.addDays(day);
    if(resultDate.toString() == "")
    {
        QDate curDate = QDate::currentDate();
        simInfo->startDate = curDate;
        return QString::number(curDate.month()) + "/" +
               QString::number(curDate.day()) + "/" +
               QString::number(curDate.year());
    } else {
        return QString::number(resultDate.month()) + "/" +
               QString::number(resultDate.day()) + "/" +
               QString::number(resultDate.year());
    }

    //DEBUG CODE
    //std::cout << "Added day(s): " << day << " " << resultDate.toString().toUtf8().constData() << std::endl;
}


//Adds continent overlay items to storage vector
void MainWindow::createContinentOverlays()
{
    //Object creation using Overlay constructor
    worldMapFillLayer* Asia = new worldMapFillLayer(createPopLabel(QPoint(1150,300)),"Asia", 17.21, curSimResults, .002, 0.0, QPoint(1150,300), QPoint(250,200));
    worldMapFillLayer* Africa = new worldMapFillLayer(createPopLabel(QPoint(810,465)), "Africa", 11.73, curSimResults, .002, 0.0, QPoint(810,465), QPoint(150,160));
    worldMapFillLayer* Australia = new worldMapFillLayer(createPopLabel(QPoint(1315,595)), "Australia", 3.32, curSimResults, .002, 0.0, QPoint(1315,595), QPoint(150,130));
    worldMapFillLayer* Europe = new worldMapFillLayer(createPopLabel(QPoint(800,210)), "Europe", 3.931, curSimResults, .002, 0.0, QPoint(800,210), QPoint(150,130));
    worldMapFillLayer* NorthAmerica = new worldMapFillLayer(createPopLabel(QPoint(300,250)), "NorthAmerica", 9.54, curSimResults, .002, 0.0, QPoint(300,250), QPoint(240,230));
    worldMapFillLayer* SouthAmerica = new worldMapFillLayer(createPopLabel(QPoint(450,560)), "SouthAmerica", 6.888, curSimResults, .002, 0.0, QPoint(450,560), QPoint(110,135));
    //Pushing all continents into the storage vector
    continents.push_back(Asia);
    continents.push_back(Africa);
    continents.push_back(Australia);
    continents.push_back(Europe);
    continents.push_back(NorthAmerica);
    continents.push_back(SouthAmerica);
}

QGraphicsTextItem* MainWindow::createPopLabel(QPoint pos){
    //Population # string item
    PopulationGraphicLabel* shownPop = new PopulationGraphicLabel("XXXXXXXXX");
    shownPop->setDefaultTextColor(QColor(0,0,50,255));
    shownPop->setFont(QFont("Times", 12, QFont::Bold));
    scene->addItem(shownPop);
    //FIXME: Actualy do a correct centering of the label
    shownPop->setPos(shownPop->mapFromScene(pos.x()-50, pos.y()));
    shownPop->setZValue(5);
    return shownPop;
}

//Adds continent ovelays to scene (done once)
void MainWindow::addContinentsToScene()
{
    for(int i = 0; i < (int)continents.size(); i++)
        scene->addItem(continents[i]);
}

MainWindow::~MainWindow()
{
    //Remove overlay items (FIXME: check if unneeded)
    while(continents.size() != 0)
    {
        scene->removeItem(continents[0]);
        delete continents[0];
        continents.erase(continents.begin());
    }
    delete simInfo;
    delete ui;
}

//FIXME: find better default icon + add button arrangements + button selection return
//Adapted Message box from documentation
//http://doc.qt.io/archives/qt-4.8/qmessagebox.html#QMessageBox
void MainWindow::showCustomMeassge(QString title, QString message, QPixmap icon)
{
    QMessageBox msgBox;
    msgBox.setText(title);
    msgBox.setInformativeText(message);
    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.setDefaultButton(QMessageBox::Close);
    msgBox.setIconPixmap(icon);
    msgBox.exec();
}

void MainWindow::on_beginSimBtn_clicked()
{
    if(!running)
    {
        if((simInfo->getRunTime() == -1)||(simInfo->getRunTime() == 0))
        {
            showCustomMeassge("Invalid Simulation Settings",
                              "Please enter a positive integer in the runtime textfield of the \"Quick Settings\" tab!",
                              QPixmap("://Resources/formIcon.png"));
            return;
        }

        std::cout<< "Staring the simulation with " << simInfo->getRunTime() << " days to go!" << std::endl;

        //Change values only if simulation ran/resumed successfully
        simTimer->start(simSpeed);

        ui->beginSimBtn->setText("Pause Simulation");
        running = true;
    }
    else
    {
        ui->beginSimBtn->setText("Begin Simulation");
        simTimer->stop();
        running = false;
    }
}

void MainWindow::on_resetSimBtn_clicked()
{
    day = 0;
    if(running)
        running = false;

    simTimer->stop();
    ui->beginSimBtn->setText("Begin Simulation");
    curSimResults->snapshots.clear(); //remove all past simulation values
    updateAnim(0);
}

void MainWindow::on_simRuntimeInput_textEdited(const QString &arg1)
{
    simInfo->runtime = arg1.toInt();
}

void MainWindow::on_enableDisasterInput_toggled(bool checked)
{
    simInfo->enableDisaster = checked;
}

void MainWindow::on_enableMigrationInput_toggled(bool checked)
{
    simInfo->enableMigration = checked;
}

void MainWindow::on_continentFocusInput_currentTextChanged(const QString &arg1)
{
    simInfo->continentFocus = arg1.toUtf8().constData();;
}

void MainWindow::on_startDateInput_dateChanged(const QDate &date)
{
    simInfo->startDate = date;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    simSpeed = value;
    simTimer->setInterval(value);
    int dayPerSec = 1000/value;
    ui->simSpeedLabel->setText("Simulation Speed: " + QString::number(dayPerSec) + " days / second");
}
