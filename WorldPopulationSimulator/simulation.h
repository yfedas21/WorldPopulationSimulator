#ifndef SIMULATION_H
#define SIMULATION_H

//Will be adding multithreading via Concurrency Qt Module
//#include <QThread>
//possible adaptation of https://www.youtube.com/watch?v=tvpC8UrPpZ4

#include <string>
#include "globe.h"

class Simulation {
private:
    int total_time; // total number of days to run the simulation
    int day; // current day

    // Create a new globe at simulation init
    Globe *g;

public:
    Simulation() {
        g = new Globe();
    }

    Globe* get_globe() {
        return g;
    }

    void run_simulation() {
        for (int time = 0; time < total_time; ++time) {
            // update each continent as each day goes by ...
            for (int cont = 0; cont < continents->size(); cont++){
                continents->at(cont).update(time);
            }
        }
    }
}

#endif // SIMULATION_H
