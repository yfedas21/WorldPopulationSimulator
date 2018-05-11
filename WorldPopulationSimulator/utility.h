#ifndef UTILITY_H
#define UTILITY_H
#pragma once
#include <map>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <iostream>
#include "value_container.h"

class Utility {

private:

    static const std::string pop;
    static const std::string ngr;
    static const std::string hr;
    static const std::string hd;
    static const std::string tr;
    static const std::string td;
    static const std::string er;
    static const std::string ed;
    static const std::string vr;
    static const std::string vd;
    static const std::string lr;
    static const std::string ld;
    static const std::string fr;
    static const std::string fd;
    static const std::string thr;
    static const std::string thd;

    static const std::string af;
    static const std::string an;
    static const std::string as;
    static const std::string au;
    static const std::string eu;
    static const std::string na;
    static const std::string sa;


public:
    //FIX ME: anything to add here?
    Utility() {}


    static void set_map(std::map<std::string, int> mapping) {
		mapping = mapping;
	}

	static double calculate_prob(double occ, double deaths) {
		// do some magic here...
		return 1.2;
	}

	/**
		Read the value at line line_number in the data file
		@param line_number the line number of target data
		@return the target data
	*/
    static double read_value(int line_number) {

		// attempt to read data from file
		try {
			int line_counter = 1;
			std::string str;
			std::ifstream file;
			std::string::size_type sz;
			file.open("Values.txt");

			if (!file) {
				throw "Exception: The file can't be opened!";
			}
			else {
				int i = 9;
				while (std::getline(file, str) && line_counter < line_number) {
					line_counter++;
				}
				// Assumes line number was found...
				return std::stod(str, &sz);
			}
		}
		catch (std::string ex) {
			// unable to open file

			// *** Add GUI messagebox popup here ***
		}
		

		return -1;
	}

	/**
		Find the location of the specific rate in the data file
		@return the line number with the rate in the data file
	*/
    static int find_line_number(const std::string cont_name, const int dis_code_location) {
		// Hold the start line of the information for the continent
		// in the data file
		int cont_location = get_cont_line_start(cont_name);
		return (cont_location + dis_code_location);
	}

	/**
	Search the map container for disaster_code
	to line number mapping
	@return the line number relative to the continent block
	*/
    static int find_in_map(std::string dis_code, std::map<std::string, int>& mapping) {
		// the disaster_code exists
		if (mapping.find(dis_code) != mapping.end()) {
			return mapping[dis_code];
		}
	}

	/**
		Get the line where the continent information
		starts in the data file
		@return the line in the file where continental info begins 
    */
    static int get_cont_line_start(std::string cont_name) {
        //using namespace Continent_Names;
		// each continents block is 19 lines long.
		int cont_block = 19;
		if (cont_name == af)
			return cont_block;
		else if (cont_name == an)
			return cont_block * 2;
		else if (cont_name == as)
			return cont_block * 3;
		else if (cont_name == au)
			return cont_block * 4;
		else if (cont_name ==  eu)
			return cont_block * 5;
		else if (cont_name == na)
			return cont_block * 6;
		else if (cont_name == sa)
			return cont_block * 7;
		else
			return -1;
    }


	/**
	Creates a struct that rates and populations in one location
	@return the values struct with data from the data file
	*/
    static values create_struct(std::string name, std::map<std::string, int> mapping) {
        //using namespace Disaster_Codes;

		values V(name); 
		V.population = read_value(find_line_number(name, find_in_map(pop, mapping)));
		V.net_growth = read_value(find_line_number(name, find_in_map(ngr, mapping)));
		V.hurricane_rate = read_value(find_line_number(name, find_in_map(hr, mapping)));
		V.hurricane_deaths = read_value(find_line_number(name, find_in_map(hd, mapping)));
		V.tornado_rate = read_value(find_line_number(name, find_in_map(tr, mapping)));
		V.tornado_deaths = read_value(find_line_number(name, find_in_map(td, mapping)));
		V.earthquake_rate = read_value(find_line_number(name, find_in_map(er, mapping)));
		V.earthquake_deaths = read_value(find_line_number(name, find_in_map(ed, mapping)));
		V.volcano_rate = read_value(find_line_number(name, find_in_map(vr, mapping)));
		V.volcano_deaths = read_value(find_line_number(name, find_in_map(vd, mapping)));
		V.landslide_rate = read_value(find_line_number(name, find_in_map(lr, mapping)));
		V.landslide_deaths = read_value(find_line_number(name, find_in_map(ld, mapping)));
		V.flood_rate = read_value(find_line_number(name, find_in_map(fr, mapping)));
		V.flood_deaths = read_value(find_line_number(name, find_in_map(fd, mapping)));
		V.thunderstorm_rate = read_value(find_line_number(name, find_in_map(thr, mapping)));
		V.thunderstorm_deaths = read_value(find_line_number(name, find_in_map(thd, mapping)));

		return V;
    }
};

#endif // !UTILITY_H
