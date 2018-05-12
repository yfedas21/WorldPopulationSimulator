#ifndef CONTINENT_H
#define CONTINENT_H

#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <iterator>
#include "utility.h"
#include "disaster.h"
#include "value_container.h"

using std::string;
using std::vector;
using std::queue;

/**
	Inherit from double-ended queue for iterator-like functionality
	Source: https://stackoverflow.com/a/5984198/9036593
*/
template<typename T, typename Container = std::deque<T> >
class iterable_queue : public std::queue<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

class Continent {
private:
	string name;
	values value_container;
	std::map<std::string, int> mapping;
	vector<Disaster*> disasters;
	iterable_queue<Disaster*> disasters_to_happen;

	//// function for quick debugging... Remove later 
	//void add_sample_disasters() {
	//	Disaster *a = new Disaster("tornado", 1.1, 1.1);
	//	Disaster *b = new Disaster("earthquake", 1.2, 1.2);
	//	Disaster *c = new Disaster("flood", 1.3, 1.3);
	//	Disaster *d = new Disaster("lightning", 1.4, 1.4);
	//	Disaster *e = new Disaster("fire", 1.5, 1.5);

	//	disasters.push_back(a);
	//	disasters.push_back(b);
	//	disasters.push_back(c);
	//	disasters.push_back(d);
	//	disasters.push_back(e);
	//}

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
		The core of any simulation program
	*/
	void update(int day) {

		// For each day, increment the continental population based on annual net growth rate / 365
		value_container.population += 
			(int)((value_container.population * value_container.net_growth / 365) + 0.5); 

		// Loop through the disasters vector to determine which ones will occur
		for (int loc_in_vec = 0; loc_in_vec < disasters.size(); ++loc_in_vec) {
			if (Utility::calculate_probability(disasters[loc_in_vec]->get_rate_per_year())) {
				// add the disaster into the Disaster queue
				disasters_to_happen.push(disasters[loc_in_vec]);
			}
		}

		// Step through each disaster in the iterable_queue 
		for (auto it = disasters_to_happen.begin(); it != disasters_to_happen.end(); ++it) {
			// calculate the number of deaths per Disaster
			value_container.population -= Utility::calculate_deaths(disasters_to_happen.front());
			
			// remove the disaster from the queue
			disasters_to_happen.pop();
		}
	}

	
};

#endif // !CONTINENT_H
