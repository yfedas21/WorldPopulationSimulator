#ifndef CONTINENT_H
#define CONTINENT_H

#include <iostream> //Debug
#include <vector>
#include <queue>
#include <map>
#include <string>
#include "continentalday.h"
#include "utility.h"

using std::string;
using std::vector;
using std::queue;

class Continent {
private:
	string name;
	values value_container;
	std::map<std::string, int> mapping;
	vector<Disaster*> disasters;
	std::queue<Disaster*> disasters_in_queue;

	// _test member variables
	double total_deaths_for_continent;
	double total_disasters_for_continent;

public:
	Continent() {
		// Default constructor
	}

	/**
		Constructor that will be used to create a Continent
		object and read the correct values from the data file
		** NOTICE: the order the functions in the constructor are
		called are intentional, don't change. 
    */
	Continent(string name, std::map<std::string, int> mapping) {
		this->name = name;
		this->mapping = mapping;
		initialize_data(name); 
		initialize_disasters();
	}

	/**
		A destructor for Continent
	*/
	~Continent() {
		for (auto dis_in_vec : disasters)
			delete dis_in_vec;
		while (!disasters_in_queue.empty()) {
			delete disasters_in_queue.front(); 
			disasters_in_queue.pop();
		}
	}

	/**
		Initialize each Continent object with Disaster objects
		using constant rates read from the data file into a struct
	*/
	void initialize_disasters() {

		// Each Continent contains the types of disasters
		Disaster *hurricane = new Disaster("hurricane", 
			value_container.hurricane_rate, value_container.hurricane_deaths);
		Disaster *tornado = new Disaster("tornado", 
			value_container.tornado_rate, value_container.tornado_deaths);
		Disaster *earthquake = new Disaster("earthquake", 
			value_container.earthquake_rate, value_container.earthquake_deaths);
		Disaster *volcano = new Disaster("volcano", 
			value_container.volcano_rate, value_container.volcano_deaths);
		Disaster *landslide = new Disaster("landslide", 
			value_container.landslide_rate, value_container.landslide_deaths);
		Disaster *flood = new Disaster("flood", 
			value_container.flood_rate, value_container.flood_deaths);
		Disaster *thunderstorm = new Disaster("thunderstorm", 
			value_container.thunderstorm_rate, value_container.thunderstorm_deaths);

		// Add the Disaster objects to the disasters vector
		disasters.push_back(hurricane);
		disasters.push_back(tornado);
		disasters.push_back(earthquake);
		disasters.push_back(volcano);
		disasters.push_back(landslide);
		disasters.push_back(flood);
		disasters.push_back(thunderstorm);
	}

	/**
		Accessor for values struct that holds the population and rates
	*/
	values get_values_struct() {
		return value_container;
	}

	/**
		Accessor for the name of this Continent object
	*/
	string get_name() {
		return this->name;
	}

	/**
		Accessor for the Continent population
	*/
	double get_population() {
		return value_container.population;
	}

	/**
		Mutator of the disasters vector that contains the continental disasters
	*/
	void add_disaster(string name, double rate_per_year, double deaths_per_year) {
		Disaster *d = new Disaster(name, rate_per_year, deaths_per_year);
		disasters.push_back(d);
	}

	/**
		Accessor for the Disaster container for this Continent
	*/
	vector<Disaster*> get_dis_vec() {
		return disasters;
	}

	/**
        Use data file to initialize object variables.
    */
	void initialize_data(string name) {
		// create a struct that will hold the rates 
        value_container = Utility::create_struct(name, this->mapping);
	}

	/**
        The core of single continent one day simulation
        @param: day - current simulationDay (used for setting the correct disaster timestamp easily)
        @return: population amount, growth and disasters that occured for the day
	*/
    continentalDay update(int day) {

        //Create today's continent snapshot
        continentalDay contDayResult = continentalDay();

        //Store the initial population of continent
        double original_pop = value_container.population;

        // For each day, increment the continental population based on annual net growth rate / 365
        value_container.population +=
            (long long) ((value_container.population * value_container.net_growth / 365) + 0.5);

        // Loop through the disasters vector to determine which ones will occur
        for (int loc_in_vec = 0; loc_in_vec < disasters.size(); ++loc_in_vec) {

            int disastAmountToday;

            //Calcualte amount of particular disaster in one day combining lightning into one
            if(disasters[loc_in_vec]->get_name() == "thunderstorm")
                disastAmountToday = 1;
            else
                disastAmountToday = Utility::calculate_probability(disasters[loc_in_vec]->get_rate_per_year());

            for(int i = 0; i < disastAmountToday; i++)
                disasters_in_queue.push(disasters[loc_in_vec]);
        }

        //Loop through all disasters that happened today
        while (!disasters_in_queue.empty()) {
            //Find the amount of deaths disaster causes
            int disasterDeaths = Utility::calculate_deaths(disasters_in_queue.front());

            if(!(disasterDeaths <= 0))
            {
                //Apply population impact of disaster
                value_container.population -= disasterDeaths;

                //Create current disaster snapshot
                contDayResult.addDisasterSnapshot(disasterOccurrence((double)disasterDeaths/5,day));
            }

            //Remove pending disasters for this continent for today
            disasters_in_queue.pop();
        }

        //Debug: for graph and final report
        if (day == 150)
            std::cout << "Continent: " << name << " | Population: " << value_container.population << std::endl;

        //Read population state into continent day snapshot
        contDayResult.totalPop = value_container.population;
        contDayResult.popGrowth = original_pop - value_container.population;

        return contDayResult;
    }

private:
	friend class Globe;
	/**
		The test function that will do what update() does, 
		but adds file output, percent calculations, and other
		debug information. 
	*/
	void _test_update_() {
		// "write" to the database
		using namespace Database;

		double original_population = value_container.population;

		// For each day, increment the continental population based on annual net growth rate / 365
		value_container.population +=
			(int)((value_container.population * value_container.net_growth / 365) + 0.5);
		
		// For debug purposes, keep track of deaths and occurrences to detect bugs...
		for (int loc_in_vec = 0; loc_in_vec < disasters.size(); ++loc_in_vec) {
			if (Utility::calculate_probability(disasters[loc_in_vec]->get_rate_per_year())) {
				// add the disaster into the Disaster queue
				disasters_in_queue.push(disasters[loc_in_vec]); 

				// increment the right disaster counters
				Disaster *d = disasters[loc_in_vec];
				if (d->get_name() == "hurricane")
					Database::hur_rate++;
				else if (d->get_name() == "tornado")
					Database::tor_rate++;
				else if (d->get_name() == "earthquake")
					Database::ear_rate++;
				else if (d->get_name() == "volcano")
					Database::vol_rate++;
				else if (d->get_name() == "landslide")
					Database::lan_rate++;
				else if (d->get_name() == "flood")
					Database::flo_rate++;
				else 
					Database::thu_rate++;	
			}
		}

		//std::cout << "The number of disasters for today is " << disasters_in_queue.size() << std::endl; 

		while (!disasters_in_queue.empty()) {
			int num_deaths = Utility::calculate_deaths(disasters_in_queue.front());
			value_container.population -= num_deaths;

			// increment the right death counters
			Disaster *d = disasters_in_queue.front();
			if (d->get_name() == "hurricane")
				Database::hur_deaths += num_deaths;
			else if (d->get_name() == "tornado")
				Database::tor_deaths += num_deaths;
			else if (d->get_name() == "earthquake")
				Database::ear_deaths += num_deaths;
			else if (d->get_name() == "volcano")
				Database::vol_deaths += num_deaths;
			else if (d->get_name() == "landslide")
				Database::lan_deaths += num_deaths;
			else if (d->get_name() == "flood")
				Database::flo_deaths += num_deaths;
			else
				Database::thu_deaths += num_deaths;

			disasters_in_queue.pop();
		}

		//std::cout << "The population increase for " << this->name << " is " <<
		//	value_container.population - original_population << std::endl << std::endl; 
	}
};

#endif // !CONTINENT_H
