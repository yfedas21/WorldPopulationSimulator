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
const std::string na = "NorthAmerica";
const std::string sa = "SouthAmerica";

namespace Database {
	// Holds a year's worth of data
    extern double hur_deaths;
    extern double tor_deaths;
    extern double ear_deaths;
    extern double vol_deaths;
    extern double lan_deaths;
    extern double flo_deaths;
    extern double thu_deaths;

    extern double hur_rate;
    extern double tor_rate;
    extern double ear_rate;
    extern double vol_rate;
    extern double lan_rate;
    extern double flo_rate;
    extern double thu_rate;
}

#endif 
