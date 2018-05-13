#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create the input/calculation storage class
    simInfo = new Sim_Helper();

    scene = new QGraphicsScene(this);
    ui->worldMapView->setScene(scene);
    ui->worldMapView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    //Load the requred Resources for animation to run
    QImage worldMap("://Resources/WorldMap.png");
    worldMapView = QPixmap::fromImage(worldMap);
    worldMapView = worldMapView.scaled(1510, 744, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    //Begin Time that tells how much time passed total since simulation start
    simTimer = new QTimer(this);
    connect(simTimer, SIGNAL(timeout()), this, SLOT(updatePopulation()));
    simTimer->start(100); //FIX ME - currently just adds population every second

    //Begin Timer that calls the updates of frames
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAnim())); //an update tenth of a second
    timer->start(100);

    //Connect QFuture watcher to apropriate methods
    connect(&simWatcher, SIGNAL(finished()), this, SLOT(simCalcFinished()));

    //Background for the world map
    scene->addPixmap(worldMapView);

    //Date Indicator
    dateFont = new QFont("Times", 15, QFont::Bold);
    shownDate = new QGraphicsTextItem("XX/XX/XXXX");
    shownDate->setDefaultTextColor(QColor(253,240,34,255));
    shownDate->setFont((*dateFont));
    scene->addItem(shownDate);
    shownDate->setPos(shownDate->mapFromScene(1200,10));

    //Create continent overalys
    createContinentOverlays();

    //Add continent layers to scene
    addContinentsToScene();
    updateAnim();
}

//Central function that updates the entire map by going through each continent
void MainWindow::updateAnim()
{
    shownDate->setPlainText(getCurSimDate());

    for(int i = 0; i < (int)continents.size(); i++){
        continents[i]->calculateState(running, population, day);
    }

    QWidget* viewport = ui->worldMapView->viewport();
    viewport->repaint();
}

//Updates the population amount of each country
void MainWindow::updatePopulation()
{
    if(running){
        population++;
        day++;
    }

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
    worldMapFillLayer* Asia = new worldMapFillLayer("Asia", 17.21,.02,0.0, QPoint(1150,300), QPoint(250,200));
    worldMapFillLayer* Africa = new worldMapFillLayer("Africa", 11.73,.02,0.0, QPoint(810,465), QPoint(150,160));
    worldMapFillLayer* Australia = new worldMapFillLayer("Australia", 3.32,.02,0.0, QPoint(1315,595), QPoint(150,130));
    worldMapFillLayer* Europe = new worldMapFillLayer("Europe", 3.931,.02,0.0, QPoint(800,210), QPoint(150,130));
    worldMapFillLayer* NorthAmerica = new worldMapFillLayer("NorthAmerica", 9.54,.02,0.0, QPoint(300,250), QPoint(240,230));
    worldMapFillLayer* SouthAmerica = new worldMapFillLayer("SouthAmerica", 6.888,.02,0.0, QPoint(450,560), QPoint(110,135));
    //Pushing all continents into the storage vector
    continents.push_back(Asia);
    continents.push_back(Africa);
    continents.push_back(Australia);
    continents.push_back(Europe);
    continents.push_back(NorthAmerica);
    continents.push_back(SouthAmerica);
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

SimDeltaOutcome run_simulation()
{
    qDebug() << "Hello from worker thread!";
    qDebug() << "Simulator object was created";
    return Simulator().run_simulation();
}

void MainWindow::on_beginSimBtn_clicked()
{
    if(!running)
    {
        if((simInfo->getRunTime() == -1)||(simInfo->getRunTime() == 0))
        {
            //FIXME: make into a seperate function
            //Adapted Message box from documentation
            //http://doc.qt.io/archives/qt-4.8/qmessagebox.html#QMessageBox
            QMessageBox msgBox;
            msgBox.setText("Invalid Simulation Settings");
            msgBox.setInformativeText("Please enter a positive integer in the runtime textfield of the \"Quick Settings\" tab!");
            msgBox.setStandardButtons(QMessageBox::Close);
            msgBox.setDefaultButton(QMessageBox::Close);
            msgBox.setIconPixmap(QPixmap("://Resources/formIcon.png"));
            msgBox.exec();
            return;
        }

        std::cout<< "Staring the simulation with " << simInfo->getRunTime() << " days to go!" << std::endl;

        //Change values only if simulation ran/resumed successfully
        //Documentation: https://doc.qt.io/qt-5.10/qfuturewatcher.html
        //Documentation: https://doc.qt.io/qt-5.10/qfuture.html#details
        simResults = QtConcurrent::run(run_simulation);
        simWatcher.setFuture(simResults);
        std::cout << "QFuture isFinished #1? " << simResults.isFinished() << std::endl;
        std::cout<< "Started? " << simWatcher.isStarted() << " Finshed? "<< simWatcher.isFinished() << std::endl;

        ui->beginSimBtn->setText("Pause Simulation");
        running = true;
    }
    else
    {
        ui->beginSimBtn->setText("Begin Simulation");
        running = false;
    }
}

void MainWindow::on_resetSimBtn_clicked()
{
    population = 0;
    day = 0;
    if(running)
    {
        running=false;
        ui->beginSimBtn->setText("Begin Simulation");
    }
}

void MainWindow::simCalcFinished(){
    std::cout << "QFuture isFinished #2? " << simResults.isFinished() << std::endl;

    std::cout<< "2 Started? " << simWatcher.isStarted() << " 2 Finshed? "<< simWatcher.isFinished() << std::endl;

    std::cout << "Calculations are complete!"  << std::endl;

     std::cout << "pop growth day 1: " << simResults.result().snapshots.at(1).continentDays.at("Africa").populationGrowth << std::endl;
}

void MainWindow::on_simRuntimeInput_textEdited(const QString &arg1)
{
    simInfo->runtime = arg1.toInt();
}

void MainWindow::on_enableDisastersInput_toggled(bool checked)
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
