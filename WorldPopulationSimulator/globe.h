#ifndef GLOBE_H
#define GLOBE_H

#include <vector>
#include <string>
#include "continent.h"

using std::string;

class Globe {
private:
	string name; // The Globe name

	// container for Continent objects
	std::vector<Continent *> continents;
	
	// holds the names of the Continents that will 
	// be created. The name is really important, it 
	// initializes the Continent with the correct data
	std::vector<std::string> cont_to_create;

	// structs with information
	std::vector<values> values_vec;

	// map to hold disaster_code and line number mappings
	std::map<string, int> mapping;
	std::map<string, int>::iterator it;

	void create_structs() {
		//this->values_vec = Utility::create_structs(mapping);
	}

	/**
		Add the continent names to the cont_to_add vector
		Inside the function, the namespace Continent_Names 
		will go out of scope once the names are added
	*/
	void add_cont_codes() {
		using namespace Continent_Names;

		// add the default 7 continents
		cont_to_create.push_back(af);
		cont_to_create.push_back(an);
		cont_to_create.push_back(as);
		cont_to_create.push_back(au);
		cont_to_create.push_back(eu);
		cont_to_create.push_back(na);
		cont_to_create.push_back(sa);
	}

	/**
		Create the continents based on the continent
		name stored in the cont_to_create vector
	*/
	void create_continents() {
		// create the continents and initialize the data
		for (int i = 0; i < cont_to_create.size(); ++i) {
			Continent *c = new Continent(cont_to_create[i], mapping);
			continents.push_back(c);
		}
	}

public:
	Globe(string name) {
		this->name = name;

		create_map(); // create map to hold locations
		add_cont_codes(); // prepare cont names for Continent creation
		//create_structs(); // return a vector of values structs
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

