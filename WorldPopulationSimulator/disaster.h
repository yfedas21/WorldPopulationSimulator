#ifndef DISASTER_H
#define DISASTER_H

#include <string>
#include "utility.h"

using std::string;

class Disaster {
private: // parts
	string name;
	double rate_per_year;
	double deaths_per_year;

public:
	// The boring default constructor
	Disaster() {}

	/**
		Deconstructor (Rule of Three)
	*/
	~Disaster() {
		delete this; // don't know if this is implemented correctly, check later
	}
	
	/**
		The Disaster constructor that takes a disaster name, 
		rate_per_year and deaths_per_year and creates a Disaster object
	*/
	Disaster(string name, double rate_per_year, double deaths_per_year) {
		this->name = name;
		this->rate_per_year = rate_per_year;
		this->deaths_per_year = deaths_per_year;
	}

	/**
		Accessor for the type of disaster
		@return name the type of disaster (ie hurricane)
	*/
	string get_name() {
		return this->name;
	}

	/**
		Accessor for the rate of occurence per year
		@return rate_per_year the rate of occurence 
	*/
	double get_rate_per_year() {
		return rate_per_year;
	}

	/**
		Accessor for the deaths per disaster per year
		@return deaths_per_year the number of deaths / yr 
	*/
	double get_deaths_per_year() {
		return deaths_per_year;
	}
};

#endif
