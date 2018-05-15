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

    SimDeltaOutcome(){}

    //FIXME: nolonger needed probably
    //Constructor used by backend to encapsulate all final simulation information
    SimDeltaOutcome(std::map<int, globalDay> snapshots, int calcTime = 0)
    {
        this->snapshots = snapshots;
        totalCalcTime = calcTime;
    }

    void insertNewDay(std::pair<int, globalDay> dayInfo)
    {
        snapshots.insert(dayInfo);
    }
};

#endif // SIMDELTAOUTCOME_H
