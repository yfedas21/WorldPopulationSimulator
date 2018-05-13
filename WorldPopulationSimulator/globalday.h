#ifndef GLOBALDAY_H
#define GLOBALDAY_H

#include <map>
#include <string>
#include "continentalday.h"

class globalDay
{
public:
    std::map<std::string, continentalDay> continentDays;

    globalDay(){}

    //Used by backend
    void addContData(std::string continentName, continentalDay contData)
    {
        continentDays.insert(std::make_pair(continentName, contData));
    }

};

#endif // GLOBALDAY_H
