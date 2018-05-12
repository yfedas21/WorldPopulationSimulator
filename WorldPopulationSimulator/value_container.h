#ifndef VALUE_CONTAINER_H_
#define VALUE_CONTAINER_H_

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

	// for debug purposes...
	void display() {
		std::cout << "Name: " << name << std::endl;
		std::cout <<  "Population: " << population << std::endl;
		std::cout <<  "Net growth: " << net_growth << std::endl;
		std::cout <<  "Hurricane rate:" << hurricane_rate << std::endl;
		std::cout <<  "Hurricane deaths: " << hurricane_deaths << std::endl;
		std::cout <<  "Tornado rate: " << tornado_rate << std::endl;
		std::cout <<  "Tornado deaths: " << tornado_deaths << std::endl;
		std::cout <<  "Earthquake rate: " << earthquake_rate << std::endl;
		std::cout <<  "Earthquake deaths: " << earthquake_deaths << std::endl;
		std::cout <<  "Volcano rate: " << volcano_rate << std::endl;
		std::cout <<  "Volcano deaths: " << volcano_deaths << std::endl;
		std::cout <<  "Landslide rate: " << landslide_rate << std::endl;
		std::cout <<  "Landslide deaths: " << landslide_deaths << std::endl;
		std::cout <<  "Flood rate: " << flood_rate << std::endl;
		std::cout <<  "Flood deaths: " << flood_deaths << std::endl;
		std::cout <<  "Thunderstorm rate: " << thunderstorm_rate << std::endl;
		std::cout <<  "Thunderstorm deaths: " << thunderstorm_deaths << std::endl;
	}
};

#endif 