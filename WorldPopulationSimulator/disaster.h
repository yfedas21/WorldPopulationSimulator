#ifndef DISASTER_H
#define DISASTER_H

#include <string>
#include "utility.h"

using std::string;

class Disaster {
private:
	string name;
	double rate_per_year;
	double deaths_per_year;

public:
	Disaster() {}

	~Disaster() {
		delete this; // don't know if this is implemented correctly, check later
	}
	 
	Disaster(string name, double rate_per_year, double deaths_per_year) {
		this->name = name;
		this->rate_per_year = rate_per_year;
		this->deaths_per_year = deaths_per_year;
	}

	string get_name() {
		return this->name;
	}

	double calculate_prob() {
        return Utility::calculate_prob(this->rate_per_year, this->deaths_per_year);
	}
};

#endif
