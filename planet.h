#include <iostream>
#include <fstream>
#include <string>

#ifndef PLANET_H
#define PLANET_H

class Planet {
public:
        Planet();

        Planet(std::string, int, int);

        ~Planet();

        std::string get_name();

private:
        std::string name;
        int coord_x, coord_y;
};
#endif