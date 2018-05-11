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

    Utility * util;

public:
	Disaster() {
        //BIG FIXME: Make the object that creates disasters objects pass in the utility class pointer
        //that is created in the globe object or simulation object
        util = new Utility();
	}

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
        return util->calculate_prob(this->rate_per_year, this->deaths_per_year);
	}
};

#endif
