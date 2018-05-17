#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <vector>
#include <map>
#include "worldMapFillLayer.h"
#include "populationGraphicLabel.h"
#include "simdeltaoutcome.h"
#include "simulator.h"
#include "sim_helper.h"
//Debug
#include <iostream>
#include <iomanip>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void addContinentsToScene();
    void createContinentOverlays();
    QGraphicsTextItem* createPopLabel(QPoint pos);
    void showCustomMeassge(QString title = "Something went wrong!",
                           QString message = "Just click \"Close\" below.",
                           QPixmap icon = QPixmap("://Resources/formIcon.png"));
    void updateAnim(int day);
    QString getCurSimDate();
    //SimDeltaOutcome run_simulation();

    ~MainWindow();

public Q_SLOTS:
    void calculateOneDay();

private slots:
    void on_beginSimBtn_clicked();

    void on_resetSimBtn_clicked();

    void on_simRuntimeInput_textEdited(const QString &arg1);

    void on_enableDisasterInput_toggled(bool checked);

    void on_enableMigrationInput_toggled(bool checked);

    void on_continentFocusInput_currentTextChanged(const QString &arg1);

    void on_startDateInput_dateChanged(const QDate &date);

private:
    //Graphic holders
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsTextItem* shownDate;
    QPixmap worldMapView;

    QTimer* simTimer;
    std::vector<worldMapFillLayer*> continents;
    Sim_Helper* simInfo;
    SimDeltaOutcome* curSimResults;
    Simulator* simulator;
    int day = 0; //Tells what day simulation is currently on
    bool running = false; //Tells wether simulation is running
};

#endif // MAINWINDOW_H
