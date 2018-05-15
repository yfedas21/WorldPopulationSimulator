#ifndef GLOBE_H
#define GLOBE_H

#include <string>
#include <map>
#include "continent.h"
#include "globalday.h"

using std::string;

class Globe {
private:
	string name; // The globe name
	double global_population; 
	// container for Continent objects
    std::vector<Continent *> continents;
	
	// holds the names of the Continents that will 
	// be created. The name is really important, it 
	// initializes the Continent with the correct data
	std::vector<std::string> cont_to_create;

	// map to hold disaster_code and line number mappings
	std::map<string, int> mapping;
	std::map<string, int>::iterator it;

	/**
		Add the continent names to the cont_to_add vector
		Inside the function, the namespace Continent_Names 
		will go out of scope once the names are added
	*/
	void add_cont_codes() {

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
	/**
		Only one constructor, the initilization process 
		is very specific. 
		@param name the name of the Globe
	*/
	Globe(string name) {
		this->name = name;

		create_map(); // create map to hold location mappings 
		add_cont_codes(); // prepare cont names for Continent creation
		set_global_population();
		// Create the continents and add them to the Continent vector
		create_continents(); 
	}

	/**
		Globe destructor (following the Rule of Three)
	*/
	~Globe() {
        for (auto cont_ptr : continents)
            delete cont_ptr;
	}

	/**
		Accessor for the name of the Globe
		@return name the name of this Globe object
	*/
	std::string get_name() {
		return this->name;
	}

	/**
		Set this Globe population from file
		@return freaking nothing lol
	*/
	void set_global_population() {
		this->global_population = Utility::read_value(17);
	}

	/**
		Returns the vector that holds Continent objects
		@return the vector that holds Continent objects
	*/
    std::vector<Continent *> get_cont_vec() {
		return continents;
	}

	/**
		The Globe update function, which just runs
		each Continent's update function, but provides a 
		level of abstraction from the Simulator class
    */
    globalDay update(int day)
    {
        globalDay globalDayResult;
        for (auto cont : continents)
        {
            continentalDay curContResult = cont->update(day);
            global_population += curContResult.popGrowth;
            globalDayResult.addContData(cont->name, curContResult);
        }
        return globalDayResult;
    }

	/**
		A test update function, one with debug information
		DOES NOT MODIFY GLOBAL POPULATION! Use above function
	*/
	void _test_update_() {
		for (auto cont : continents) {

            cont->_test_update_();
		}
	}

	/**
		Create a map container to hold the location of the
        Disaster_Codes in the data file
		@return the current state of my wallet
	*/
	void create_map() {
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
#endif // !GLOBE_H

