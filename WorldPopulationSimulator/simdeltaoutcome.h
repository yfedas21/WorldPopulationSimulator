#ifndef SIMDELTAOUTCOME_H
#define SIMDELTAOUTCOME_H

#include <map>
#include "globalday.h"


class SimDeltaOutcome
{
public:
    //FIXME: would be nice to implement this and more
    int totalCalcTime; //in sec how much simulation took to complete

    std::map<int, globalDay> snapshots;

    //FIXME: need default constructor?
    SimDeltaOutcome(){}

    //Constructor used by backend to encapsulate all final simulation information
    SimDeltaOutcome(std::map<int, globalDay> snapshots, int calcTime = 0)
    {
        this->snapshots = snapshots;
        totalCalcTime = calcTime;
    }
};

#endif // SIMDELTAOUTCOME_H
