#ifndef GLOBE_H
#define GLOBE_H

#include <vector>
#include <string>
#include "continent.h"

using std::string;

class Globe {
private:
	string name;
	// container for Continent objects
	std::vector<Continent *> continents;
	
	// structs with information
	std::vector<values> values_vec;

	// map to hold disaster_code and line number mappings
	std::map<string, int> mapping;
	std::map<string, int>::iterator it;

	void create_structs() {
		this->values_vec = Utility::create_structs(mapping);
	}

	/**
		Search the map container for disaster_code 
		to line number mapping
		@return the line number relative to the continent block
	*/
	int find_in_map(string dis_code) {
		// the disaster_code exists
		if (mapping.find(dis_code) != mapping.end()) {
			return mapping[dis_code];
		}
	}

	std::vector<Continent *> create_continents(values) {
		std::vector<Continent*> cont;

		//// Create Continent objects
		//Continent *africa = new Continent("africa");
		//Continent *asia = new Continent("asia");
		//Continent *australia = new Continent("australia");
		//Continent *antarctica = new Continent("antarctica");
		//Continent *north_america = new Continent("north america");
		//Continent *south_america = new Continent("south america");
		//Continent *europe = new Continent("europe");

		//// Add continents to cont std::vector
		//cont.push_back(africa);
		//cont.push_back(asia);
		//cont.push_back(australia);
		//cont.push_back(antarctica);
		//cont.push_back(north_america);
		//cont.push_back(south_america);
		//cont.push_back(europe);

		//return cont;
	}

public:
	Globe(string name) {
		this->name = name;
		//continents = create_continents();
		create_map(); // initialize 
		create_structs(); // initialize Continents
	}

	std::vector<Continent *> get_cont_vec() {
		return continents;
	}

	/**
	Create a map container to hold the location of the
	Disaster_Codes in the data file
	*/
	void create_map() {
		using namespace Disaster_Codes;

		// Create a map container to hold Disaster_Code
		// to line number in the data file mappings
		mapping.insert(std::make_pair(pop, 2));
		mapping.insert(std::make_pair(ngr, 3));
		mapping.insert(std::make_pair(hr, 4));
		mapping.insert(std::make_pair(hd, 5));
		mapping.insert(std::make_pair(tr, 6));
		mapping.insert(std::make_pair(td, 7));
		mapping.insert(std::make_pair(er, 8));
		mapping.insert(std::make_pair(ed, 9));
		mapping.insert(std::make_pair(vr, 10));
		mapping.insert(std::make_pair(vd, 11));
		mapping.insert(std::make_pair(lr, 12));
		mapping.insert(std::make_pair(ld, 13));
		mapping.insert(std::make_pair(fr, 14));
		mapping.insert(std::make_pair(fd, 15));
		mapping.insert(std::make_pair(thr, 16));
		mapping.insert(std::make_pair(thd, 17));
	}
};

//struct values {
//	string name;
//	// Constructor with name parameter
//	values(string name) { this->name = name; }
//	double population = 0;
//	double net_growth = 0;
//	double hurricane_rate = 0;
//	double hurricane_deaths = 0;
//	double tornado_rate = 0;
//	double tornado_deaths = 0;
//	double earthquake_rate = 0;
//	double earthquake_deaths = 0;
//	double volcano_rate = 0;
//	double volcano_deaths = 0;
//	double landslide_rate = 0;
//	double landslide_deaths = 0;
//	double flood_rate = 0;
//	double flood_deaths = 0;
//	double thunderstorm_rate = 0;
//	double thunderstorm_deaths = 0;
//};

#endif // !GLOBE_H

