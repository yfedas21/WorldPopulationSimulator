#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdexcept>
#include <ios>
#include <string>
#include <vector>
#include "globe.h"
#include "continent.h"

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
        for (int clock = 0; clock < total_time; clock++) {
            // update each continent as each day goes by ...
            for (int cont = 0; cont < continents->size(); cont++){
                continents->at(cont).update(clock);
            }
        }
    }
}

#endif // SIMULATION_H
