#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "globe.h"
#include <iostream> //Dubug

class Simulator {
private:
	// Create a new globe at simulation init
    Globe *g;

public:
	/**
		Create a new Globe object at Simulation creation
	*/
	Simulator() {
        g = new Globe("Earth");
	}

	/**
		A destructor for Simulator
    */
	~Simulator() {
		delete g;
	}

    std::pair<int, globalDay> run_simulation(int curDay)
    { 
        // Call the Globe update (which calls each Continent update):
        return std::make_pair(curDay, g->update(curDay));
    }

	void _run_tests_() {

        //Timer Design makes this function a bit harder to implement
        //for (int time = 0; time < total_time; ++time) {
        //	// call the Globe update, which calls a test update
        //	g->_test_update_();
        //}
		std::cout << " ********** Statistics ********** " << std::endl;
		std::cout << "hurricane rate: " << Database::hur_rate << std::endl; Database::hur_rate = 0;
		std::cout << "tornado rate: " << Database::tor_rate << std::endl; Database::tor_rate = 0;
		std::cout << "earthquake rate: " << Database::ear_rate << std::endl; Database::ear_rate = 0;
		std::cout << "volcano rate: " << Database::vol_rate << std::endl; Database::vol_rate = 0;
		std::cout << "landslide rate: " << Database::lan_rate << std::endl; Database::lan_rate = 0;
		std::cout << "flood rate: " << Database::flo_rate << std::endl; Database::flo_rate = 0;
		std::cout << "thunderstorm rate: " << Database::thu_rate << std::endl; Database::thu_rate = 0;
		std::cout << std::endl;
		std::cout << " ---------- Deaths ---------- " << std::endl;
		std::cout << "hurricane deaths: " << Database::hur_deaths << std::endl; Database::hur_deaths = 0;
		std::cout << "tornado deaths: " << Database::tor_deaths << std::endl; Database::tor_deaths = 0;
		std::cout << "earthquake deaths: " << Database::ear_deaths << std::endl; Database::ear_deaths = 0;
		std::cout << "volcano deaths: " << Database::vol_deaths << std::endl; Database::vol_deaths = 0;
		std::cout << "landslide deaths: " << Database::lan_deaths << std::endl; Database::lan_deaths = 0;
		std::cout << "flood deaths: " << Database::flo_deaths << std::endl; Database::flo_deaths = 0;
		std::cout << "thunderstorm deaths: " << Database::thu_deaths << std::endl; Database::thu_deaths = 0;
		std::cout << "---------------------------------\n\n\n";
	}
};

#endif // SIMULATOR_H
