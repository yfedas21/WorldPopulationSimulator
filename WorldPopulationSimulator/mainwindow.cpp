#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->worldMapView->setScene(scene);

    QImage worldMap("://Resources/WorldMap.png");
    QImage worldMapFill("://Resources/WorldMapFilled.png");
    worldMapView = QPixmap::fromImage(worldMap);
    worldMapFillView = QPixmap::fromImage(worldMapFill);
    worldMapView = worldMapView.scaled(1510, 745, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    worldMapFillView = worldMapFillView.scaled(1510, 745, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    scene->addPixmap(worldMapView);
    scene->addPixmap(worldMapFillView);
}

MainWindow::~MainWindow()
{
    delete ui;
}
