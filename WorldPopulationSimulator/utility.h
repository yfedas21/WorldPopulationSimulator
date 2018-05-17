#ifndef UTILITY_H
#define UTILITY_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include "constants.h"
#include "value_container.h"
#include "disaster.h"

class Utility {

private:

	// Private constructor will ensure this
	// class doesn't create any objects. 
	Utility() {}

public:

	/**
		Calculate whether a specific disaster is set to happen 
		on any given day
		@return true if a disaster is to occur that day; false otherwise
	*/
	static bool calculate_probability(int rate_of_occurrence) {
		// generate a random number between 0 and 365 (annual rates)
		// source: https://stackoverflow.com/a/7560564/9036593
        static std::random_device rd; // obtain a random number from hardware
        static std::mt19937 eng(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, 365); // annual rate

        //BIG FIXME: Make it possible for more than one disaster of one type to occur
        //especcially for ones that have more than 365 occurances per year
        //Dont worry about lightning (thunderstorm) thats already handled

        // create a new random number in the range of [0 to 365]
		int random_integer = distr(eng);
        if (random_integer <= rate_of_occurrence){
            //std::cout<<"A disaster was added! [" << random_integer << " < " << rate_of_occurrence << "]" << std::endl;
            return true;
        }

		else 
			return false;
	}

	/**
		Calculate the number of deaths from the disaster
		@return deaths the number of deaths
	*/
	static int calculate_deaths(Disaster* disaster) {

        // see calculate_probability() for random number generator source
        static std::random_device rdd; // obtain a random number from hardware
        static std::mt19937 engd(rdd()); // seed the generator

		// use a different method of calculation for lightning
		// because of the high occurence rate (in the millions)
        if (disaster->get_name() == "thunderstorm")
        {
			// algorithm to calculate the number of deaths per day from lightning
            std::uniform_int_distribution<> distrd(0, 365);
            double rate_per_day;

            rate_per_day = disaster->get_deaths_per_year() / 365;
            if(rate_per_day < 1) //Case for less than 365 lightning strikes a year
            {
                if (distrd(engd) <= disaster->get_deaths_per_year())
                    return 1;
                else
                    return 0;
            }

            //FIXME: make more random
            return rate_per_day;

            return -1; // IF -1 returns, Houston, we have a problem
		}
        else
        {
			/*
				Algorithm for determining deaths per occurence of disaster
				1.) retrieve the number of deaths / year for the disaster
				2.) divide the # of occ / year to get the avg deaths / occ
				3.) multiply avg deaths * .30 
				4.) generate random number between 
					(avg - (avg * .30), avg + (avg * .30)) as the 
					(lower bound	  , upper bound		))
				*/
			int dpy = (int)(disaster->get_deaths_per_year());
			
            if ((int)(disaster->get_rate_per_year()) <= 0)
				return 0;
			else { // divide by zero exception
				double avg = dpy / (int)(disaster->get_rate_per_year());
                // +2 for nice variable name
				double wiggle_room = avg * .3;
				// generate number of deaths with reasonable randomness (scary thought...)
				std::uniform_int_distribution<> distr(avg - wiggle_room, avg + wiggle_room);

				// return the calculated # of deaths
                if (distr(engd) <= avg)
					return (int)(avg + .5);
			}
		}

		// if all else fails scenario: nobody dies!
		return -1;
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
                std::string error = "Exception: The file can't be opened!"; //qt didn't know it was and std::string not QString
                throw error;
			}
			else {
				while (std::getline(file, str) && line_counter < line_number) {
					line_counter++;
				}
				// Assumes line number was found...
                return std::stod(str, &sz);
			}
		}
		catch (std::string ex) {
			// unable to open file

            // *** FIXME: Add GUI messagebox popup here ***
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
