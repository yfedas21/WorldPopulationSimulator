#ifndef GLOBE_H
#define GLOBE_H

#include <vector>
#include "continent.h"

using std::vector;

class Globe {
private:
    vector<Continent> *continents;

    // If each globe will have the "standard" 7 continents:
    Continent *africa, *antarctica, *asia, *australia, *europe, *north_america, *south_america;
public:
    Globe() {
        // Keeping up with the "standard" theme:
        africa = new Continent();
        antarctica = new Continent();
        asia = new Continent();
        australia = new Continent();
        europe = new Continent();
        north_america = new Continent();
        south_america = new Continent();

        // add continents to vector
        continents->push_back(africa);
        continents->push_back(antarctica);
        continents->push_back(asia);
        continents->push_back(australia);
        continents->push_back(europe);
        continents->push_back(north_america);
        continents->push_back(south_america);
    }

    // add constructor with vector of Continent objects
    Globe(vector<Continent> *c) {
        this->continents = c;
    }
}

#endif // GLOBE_H
