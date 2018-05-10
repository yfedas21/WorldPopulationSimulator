#ifndef VALUE_CONTIANER_H_
#define VALUE_CONTIANER_H_

#include <string>

struct values {
	std::string name;
	// Constructor with name parameter
	values() {}
	values(std::string name) { this->name = name; }
	double population = 0;
	double net_growth = 0;
	double hurricane_rate = 0;
	double hurricane_deaths = 0;
	double tornado_rate = 0;
	double tornado_deaths = 0;
	double earthquake_rate = 0;
	double earthquake_deaths = 0;
	double volcano_rate = 0;
	double volcano_deaths = 0;
	double landslide_rate = 0;
	double landslide_deaths = 0;
	double flood_rate = 0;
	double flood_deaths = 0;
	double thunderstorm_rate = 0;
	double thunderstorm_deaths = 0;
};

#endif 