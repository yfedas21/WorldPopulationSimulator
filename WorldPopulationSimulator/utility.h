#ifndef UTILITY_H
#define UTILITY_H

#include <map>
#include <iterator>
#include <string>
#include <iomanip>
#include <fstream>

struct values {
	std::string name;
	// Constructor with name parameter
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

namespace Disaster_Codes {
	std::string pop = "population";
	std::string ngr = "net_growth";
	std::string hr = "hurricane_rate";
	std::string hd = "hurricane_deaths";
	std::string tr = "tornado_rate";
	std::string td = "tornado_deaths";
	std::string er = "earthquake_rate";
	std::string ed = "earthquake_deaths";
	std::string vr = "volcano_rate";
	std::string vd = "volcano_deaths";
	std::string lr = "landslide_rate";
	std::string ld = "landslide_deaths";
	std::string fr = "flood_rate";
	std::string fd = "flood_deaths";
	std::string thr = "thunderstorm_rate";
	std::string thd = "thunderstorm_deaths";
};

namespace Continent_Names {
	std::string af = "Africa";
	std::string an = "Antarctica";
	std::string as = "Asia";
	std::string au = "Australia";
	std::string eu = "Europe";
	std::string na = "North_America";
	std::string sa = "South_America";
}

class Utility {

private:
	Utility() {}
public:

	static double calculate_prop(double occ, double deaths) {
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
				std::cout << "File open was successful! \n\n";
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
		using namespace Continent_Names;
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
	Pass in a vector of values structs that will be initialized
	@param vec the vector that holds values structs
	*/
	static std::vector<values> create_structs(std::map<std::string, int>& mapping) {
		using namespace Disaster_Codes;
		using namespace Continent_Names;
		// Create a vector to hold values structs
		std::vector<values> val_vec;

		values Africa(af);
		Africa.population = read_value(find_line_number(af, find_in_map(pop, mapping)));
		Africa.hurricane_rate = read_value(find_line_number(af, find_in_map(hr, mapping)));
		Africa.hurricane_deaths = read_value(find_line_number(af, find_in_map(hd, mapping)));
		Africa.tornado_rate = read_value(find_line_number(af, find_in_map(tr, mapping)));
		Africa.tornado_deaths = read_value(find_line_number(af, find_in_map(td, mapping)));
		Africa.earthquake_rate = read_value(find_line_number(af, find_in_map(er, mapping)));
		Africa.earthquake_deaths = read_value(find_line_number(af, find_in_map(ed, mapping)));
		Africa.volcano_rate = read_value(find_line_number(af, find_in_map(vr, mapping)));
		Africa.volcano_deaths = read_value(find_line_number(af, find_in_map(vd, mapping)));
		Africa.landslide_rate = read_value(find_line_number(af, find_in_map(lr, mapping)));
		Africa.landslide_deaths = read_value(find_line_number(af, find_in_map(ld, mapping)));
		Africa.flood_rate = read_value(find_line_number(af, find_in_map(fr, mapping)));
		Africa.flood_deaths = read_value(find_line_number(af, find_in_map(fd, mapping)));
		Africa.thunderstorm_rate = read_value(find_line_number(af, find_in_map(thr, mapping)));
		Africa.thunderstorm_deaths = read_value(find_line_number(af, find_in_map(thd, mapping)));

		values Antarctica(an);
		Antarctica.population = read_value(find_line_number(an, find_in_map(pop, mapping)));
		Antarctica.hurricane_rate = read_value(find_line_number(an, find_in_map(hr, mapping)));
		Antarctica.hurricane_deaths = read_value(find_line_number(an, find_in_map(hd, mapping)));
		Antarctica.tornado_rate = read_value(find_line_number(an, find_in_map(tr, mapping)));
		Antarctica.tornado_deaths = read_value(find_line_number(an, find_in_map(td, mapping)));
		Antarctica.earthquake_rate = read_value(find_line_number(an, find_in_map(er, mapping)));
		Antarctica.earthquake_deaths = read_value(find_line_number(an, find_in_map(ed, mapping)));
		Antarctica.volcano_rate = read_value(find_line_number(an, find_in_map(vr, mapping)));
		Antarctica.volcano_deaths = read_value(find_line_number(an, find_in_map(vd, mapping)));
		Antarctica.landslide_rate = read_value(find_line_number(an, find_in_map(lr, mapping)));
		Antarctica.landslide_deaths = read_value(find_line_number(an, find_in_map(ld, mapping)));
		Antarctica.flood_rate = read_value(find_line_number(an, find_in_map(fr, mapping)));
		Antarctica.flood_deaths = read_value(find_line_number(an, find_in_map(fd, mapping)));
		Antarctica.thunderstorm_rate = read_value(find_line_number(an, find_in_map(thr, mapping)));
		Antarctica.thunderstorm_deaths = read_value(find_line_number(an, find_in_map(thd, mapping)));

		values Asia(as);
		Asia.population = read_value(find_line_number(as, find_in_map(pop, mapping)));
		Asia.hurricane_rate = read_value(find_line_number(as, find_in_map(hr, mapping)));
		Asia.hurricane_deaths = read_value(find_line_number(as, find_in_map(hd, mapping)));
		Asia.tornado_rate = read_value(find_line_number(as, find_in_map(tr, mapping)));
		Asia.tornado_deaths = read_value(find_line_number(as, find_in_map(td, mapping)));
		Asia.earthquake_rate = read_value(find_line_number(as, find_in_map(er, mapping)));
		Asia.earthquake_deaths = read_value(find_line_number(as, find_in_map(ed, mapping)));
		Asia.volcano_rate = read_value(find_line_number(as, find_in_map(vr, mapping)));
		Asia.volcano_deaths = read_value(find_line_number(as, find_in_map(vd, mapping)));
		Asia.landslide_rate = read_value(find_line_number(as, find_in_map(lr, mapping)));
		Asia.landslide_deaths = read_value(find_line_number(as, find_in_map(ld, mapping)));
		Asia.flood_rate = read_value(find_line_number(as, find_in_map(fr, mapping)));
		Asia.flood_deaths = read_value(find_line_number(as, find_in_map(fd, mapping)));
		Asia.thunderstorm_rate = read_value(find_line_number(as, find_in_map(thr, mapping)));
		Asia.thunderstorm_deaths = read_value(find_line_number(as, find_in_map(thd, mapping)));

		values Australia(au);
		Australia.population = read_value(find_line_number(au, find_in_map(pop, mapping)));
		Australia.hurricane_rate = read_value(find_line_number(au, find_in_map(hr, mapping)));
		Australia.hurricane_deaths = read_value(find_line_number(au, find_in_map(hd, mapping)));
		Australia.tornado_rate = read_value(find_line_number(au, find_in_map(tr, mapping)));
		Australia.tornado_deaths = read_value(find_line_number(au, find_in_map(td, mapping)));
		Australia.earthquake_rate = read_value(find_line_number(au, find_in_map(er, mapping)));
		Australia.earthquake_deaths = read_value(find_line_number(au, find_in_map(ed, mapping)));
		Australia.volcano_rate = read_value(find_line_number(au, find_in_map(vr, mapping)));
		Australia.volcano_deaths = read_value(find_line_number(au, find_in_map(vd, mapping)));
		Australia.landslide_rate = read_value(find_line_number(au, find_in_map(lr, mapping)));
		Australia.landslide_deaths = read_value(find_line_number(au, find_in_map(ld, mapping)));
		Australia.flood_rate = read_value(find_line_number(au, find_in_map(fr, mapping)));
		Australia.flood_deaths = read_value(find_line_number(au, find_in_map(fd, mapping)));
		Australia.thunderstorm_rate = read_value(find_line_number(au, find_in_map(thr, mapping)));
		Australia.thunderstorm_deaths = read_value(find_line_number(au, find_in_map(thd, mapping)));

		values Europe(eu);
		Europe.population = read_value(find_line_number(eu, find_in_map(pop, mapping)));
		Europe.hurricane_rate = read_value(find_line_number(eu, find_in_map(hr, mapping)));
		Europe.hurricane_deaths = read_value(find_line_number(eu, find_in_map(hd, mapping)));
		Europe.tornado_rate = read_value(find_line_number(eu, find_in_map(tr, mapping)));
		Europe.tornado_deaths = read_value(find_line_number(eu, find_in_map(td, mapping)));
		Europe.earthquake_rate = read_value(find_line_number(eu, find_in_map(er, mapping)));
		Europe.earthquake_deaths = read_value(find_line_number(eu, find_in_map(ed, mapping)));
		Europe.volcano_rate = read_value(find_line_number(eu, find_in_map(vr, mapping)));
		Europe.volcano_deaths = read_value(find_line_number(eu, find_in_map(vd, mapping)));
		Europe.landslide_rate = read_value(find_line_number(eu, find_in_map(lr, mapping)));
		Europe.landslide_deaths = read_value(find_line_number(eu, find_in_map(ld, mapping)));
		Europe.flood_rate = read_value(find_line_number(eu, find_in_map(fr, mapping)));
		Europe.flood_deaths = read_value(find_line_number(eu, find_in_map(fd, mapping)));
		Europe.thunderstorm_rate = read_value(find_line_number(eu, find_in_map(thr, mapping)));
		Europe.thunderstorm_deaths = read_value(find_line_number(eu, find_in_map(thd, mapping)));

		values North_America(na);
		North_America.population = read_value(find_line_number(na, find_in_map(pop, mapping)));
		North_America.hurricane_rate = read_value(find_line_number(na, find_in_map(hr, mapping)));
		North_America.hurricane_deaths = read_value(find_line_number(na, find_in_map(hd, mapping)));
		North_America.tornado_rate = read_value(find_line_number(na, find_in_map(tr, mapping)));
		North_America.tornado_deaths = read_value(find_line_number(na, find_in_map(td, mapping)));
		North_America.earthquake_rate = read_value(find_line_number(na, find_in_map(er, mapping)));
		North_America.earthquake_deaths = read_value(find_line_number(na, find_in_map(ed, mapping)));
		North_America.volcano_rate = read_value(find_line_number(na, find_in_map(vr, mapping)));
		North_America.volcano_deaths = read_value(find_line_number(na, find_in_map(vd, mapping)));
		North_America.landslide_rate = read_value(find_line_number(na, find_in_map(lr, mapping)));
		North_America.landslide_deaths = read_value(find_line_number(na, find_in_map(ld, mapping)));
		North_America.flood_rate = read_value(find_line_number(na, find_in_map(fr, mapping)));
		North_America.flood_deaths = read_value(find_line_number(na, find_in_map(fd, mapping)));
		North_America.thunderstorm_rate = read_value(find_line_number(na, find_in_map(thr, mapping)));
		North_America.thunderstorm_deaths = read_value(find_line_number(na, find_in_map(thd, mapping)));

		values South_America(sa);
		South_America.population = read_value(find_line_number(sa, find_in_map(pop, mapping)));
		South_America.hurricane_rate = read_value(find_line_number(sa, find_in_map(hr, mapping)));
		South_America.hurricane_deaths = read_value(find_line_number(sa, find_in_map(hd, mapping)));
		South_America.tornado_rate = read_value(find_line_number(sa, find_in_map(tr, mapping)));
		South_America.tornado_deaths = read_value(find_line_number(sa, find_in_map(td, mapping)));
		South_America.earthquake_rate = read_value(find_line_number(sa, find_in_map(er, mapping)));
		South_America.earthquake_deaths = read_value(find_line_number(sa, find_in_map(ed, mapping)));
		South_America.volcano_rate = read_value(find_line_number(sa, find_in_map(vr, mapping)));
		South_America.volcano_deaths = read_value(find_line_number(sa, find_in_map(vd, mapping)));
		South_America.landslide_rate = read_value(find_line_number(sa, find_in_map(lr, mapping)));
		South_America.landslide_deaths = read_value(find_line_number(sa, find_in_map(ld, mapping)));
		South_America.flood_rate = read_value(find_line_number(sa, find_in_map(fr, mapping)));
		South_America.flood_deaths = read_value(find_line_number(sa, find_in_map(fd, mapping)));
		South_America.thunderstorm_rate = read_value(find_line_number(sa, find_in_map(thr, mapping)));
		South_America.thunderstorm_deaths = read_value(find_line_number(sa, find_in_map(thd, mapping)));

		// Add to the val_vec vector
		val_vec.push_back(Africa);
		val_vec.push_back(Antarctica);
		val_vec.push_back(Asia);
		val_vec.push_back(Australia);
		val_vec.push_back(Europe);
		val_vec.push_back(North_America);
		val_vec.push_back(South_America);

		// return the val_vec 
		return val_vec;
	}
};

#endif // !UTILITY_H
