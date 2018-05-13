#ifndef DISASTEROCCURRENCE_H
#define DISASTEROCCURRENCE_H

#include <QPoint>
#include <QColor>

//BIG FIXME: Find what (class/struct) is better at being coppied also
//if having these as pointers is better

struct disasterOccurrence
{
    QPoint dotPos;
    double magnitude; //based on disater casualties amount
    QColor color;     //based on disaster type
    int day;       //days after sim start (used for fade out animation)

    //FIXME: needed?
    disasterOccurrence(){}

    //Constructor used by backend during calculations
    disasterOccurrence(double mag, int day){
        magnitude = mag;
        this->day = day;
    }
};

#endif
