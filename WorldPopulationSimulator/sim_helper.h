#ifndef SIM_HELPER_H
#define SIM_HELPER_H

#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <string>
#include <QDate>

using std::string;

class Sim_Helper
{
public:
    // some utility functions here, such as
    // set initial values, get inputs
	
    int runtime;
    bool enableDisaster;
    bool enableMigration;
    std::string continentFocus;
    QDate startDate;

    Sim_Helper()
    {
        runtime = 0;
        enableDisaster = false;
        enableMigration = false;
        continentFocus = "No";
        startDate = QDate(4,29,2018);
    }

    //Returns runtime for simulation in days
    int getRunTime(){
        if (runtime <= 0){
            return -1;
        }else{
            return runtime;
        }
    }
};

#endif // SIM_HELPER_H
