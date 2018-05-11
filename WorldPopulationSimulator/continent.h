#ifndef CONTINENT_H
#define CONTINENT_H

#include <vector>
#include <iostream>
#include <queue>
#include "utility.h"
#include "disaster.h"
#include "value_container.h"

using std::string;
using std::vector;
using std::queue;

class Continent {
private:
	string name;
	double population;
	double cont_growth_rate;
	values struct_that_holds_rates;
	std::map<std::string, int> mapping;
	vector<Disaster*> disasters;
	queue<Disaster*> disasters_to_happen;

	// function for quick debugging...
	void add_sample_disasters() {
		Disaster *a = new Disaster("tornado", 1.1, 1.1);
		Disaster *b = new Disaster("earthquake", 1.2, 1.2);
		Disaster *c = new Disaster("flood", 1.3, 1.3);
		Disaster *d = new Disaster("lightning", 1.4, 1.4);
		Disaster *e = new Disaster("fire", 1.5, 1.5);

		disasters.push_back(a);
		disasters.push_back(b);
		disasters.push_back(c);
		disasters.push_back(d);
		disasters.push_back(e);
	}

public:
	Continent() {
		// Default constructor
	}

	/**
		Constructor that will be used to create a Continent
		object and read the correct values from the data file
	*/
	Continent(string name, std::map<std::string, int> mapping) {
		this->name = name;
		this->mapping = mapping;
		initialize_data(name);
	}

	values get_values_struct() {
		return struct_that_holds_rates;
	}

	string get_name() {
		return this->name;
	}

	void add_disaster(string name, double rate_per_year, double deaths_per_year) {
		Disaster *d = new Disaster(name, rate_per_year, deaths_per_year);
		disasters.push_back(d);
	}

	vector<Disaster*> get_dis_vec() {
		return disasters;
	}

	/**
		Use data file to initialize object variables. 
	*/
	void initialize_data(string name) {
		// create a struct that will hold the rates 
		struct_that_holds_rates = Utility::create_struct(name, mapping);
	}

	// most important function in a simulator ... the update() !
	void update(int day) {
		// For each day, increment the continental population
		// based on annual net growth rate / 365
		population += ((population * cont_growth_rate) / 365); // Check order of operations later
		std::cout << "The population now is " << population << "!\n";
	}

	
};

#endif // !CONTINENT_H
