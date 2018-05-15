#ifndef CONTINENTALDAY_H
#define CONTINENTALDAY_H

#include <list>
#include "disasterOccurrence.h"

//Not a struct because - not recomended here (larger than 16 bytes)
//https://docs.microsoft.com/en-us/dotnet/standard/design-guidelines/choosing-between-class-and-struct

class continentalDay
{
public:
    double totalPop;
    double popGrowth;
    std::list<disasterOccurrence> disasters;

    continentalDay(){}

    void addDisasterSnapshot(disasterOccurrence disaster){
        disasters.push_back(disaster);
    }
};

#endif // CONTINENTALDAY_H
