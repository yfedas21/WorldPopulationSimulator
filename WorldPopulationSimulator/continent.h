#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>
using std::string;

class Continent {
private:
    string name;
    double population;

public:
    Continent() {
        // default constructor - no parameters
    }

    Continent(string name, double population) {
        this->name = name;
        this->population = population;
    }

    void set_name(string name) {
        this->name = name;
    }

    void set_population(double population) {
        this->population = population;
    }

    string get_name() {
        return name;
    }

    double get_population() {
        return population;
    }
}

#endif // CONTINENT_H
