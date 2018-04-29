#include "mainwindow.h"
#include "worldMapFillLayer.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    simTimer->start(1000); //FIX ME - currently just adds population every second

    //Begin Timer that calls the updates of frames
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAnim())); //an update tenth of a second
    timer->start(100);

    //Background for the world map
    scene->addPixmap(worldMapView);

    //Create continent overalys FIX ME implement actual induvidual continents
    worldMapFillLayer* allContinents = new worldMapFillLayer("Other", 10, 1.0, 0.0);
    continents.push_back(allContinents);

    //Add continent layers to scene
    addContinentsToScene();
    updateAnim();
}

//Central function that updates the entire map by going through each continent
void MainWindow::updateAnim()
{
    for(int i = 0; i < (int)continents.size(); i++)
    {
        continents[i]->calculateState(running, population);
        QWidget* viewport = ui->worldMapView->viewport();
        viewport->repaint();
    }
}

//Updates the population amount of each country
void MainWindow::updatePopulation()
{
    population++;
}

//Function that adds continent ovelays to scene (done once)
void MainWindow::addContinentsToScene()
{
    for(int i = 0; i < (int)continents.size(); i++)
        scene->addItem(continents[i]);
}

MainWindow::~MainWindow()
{
    delete ui;
}
