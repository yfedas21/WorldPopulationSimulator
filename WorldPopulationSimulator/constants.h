#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string> 

/**
	Notes: The constant strings were originally defined
	in a namespace. That way, whenever a function from
	utility.h or elsewhere needed to use the strings,
	using namespace constants would put them in scope
	and then the strings would go out of scope when the
	function finishes executing. However, the QT library
	was having issues with external namespaces, so we
	changed the design to maintain basic functionality...
*/

const std::string pop = "population";
const std::string ngr = "net_growth";
const std::string hr = "hurricane_rate";
const std::string hd = "hurricane_deaths";
const std::string tr = "tornado_rate";
const std::string td = "tornado_deaths";
const std::string er = "earthquake_rate";
const std::string ed = "earthquake_deaths";
const std::string vr = "volcano_rate";
const std::string vd = "volcano_deaths";
const std::string lr = "landslide_rate";
const std::string ld = "landslide_deaths";
const std::string fr = "flood_rate";
const std::string fd = "flood_deaths";
const std::string thr = "thunderstorm_rate";
const std::string thd = "thunderstorm_deaths";

const std::string af = "Africa";
const std::string an = "Antarctica";
const std::string as = "Asia";
const std::string au = "Australia";
const std::string eu = "Europe";
const std::string na = "North_America";
const std::string sa = "South_America";

namespace Database {
	// Holds a year's worth of data
	double hur_deaths;
	double tor_deaths;
	double ear_deaths;
	double vol_deaths;
	double lan_deaths;
	double flo_deaths;
	double thu_deaths;

	double hur_rate;
	double tor_rate;
	double ear_rate;
	double vol_rate;
	double lan_rate;
	double flo_rate;
	double thu_rate;
}

#endif 