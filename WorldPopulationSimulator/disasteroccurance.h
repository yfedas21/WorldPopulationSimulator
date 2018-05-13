#ifndef DISASTEROCCURANCE_H
#define DISASTEROCCURANCE_H

struct disasterOcurance
{
    QPoint dotPos;
    int magnitude; //based on disater casualties amount
    QColor color;     //based on disaster type
    int day;       //days after sim start (used for fade out animation)

    disasterOcurance(){} //FIX ME: add default values as needed
};

#endif // DISASTEROCCURANCE_H
