#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <vector>
#include "worldMapFillLayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void addContinentsToScene();
    ~MainWindow();

public Q_SLOTS:
    void updateAnim();
    void updatePopulation();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPixmap worldMapView;
    QPixmap worldMapFillView;
    QTimer *timer;
    QTimer *simTimer;
    std::vector<worldMapFillLayer*> continents;

    //temp test variables
    int population = 0;
    bool running = true; //Tells wether simulation is running (FIX ME: Should be false at start)
};

#endif // MAINWINDOW_H
