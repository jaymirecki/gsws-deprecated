#include "planet.h"

using namespace std;

Planet::Planet() {
        name = "no_name";
        coord_x = 0;
        coord_y = 0;
}

Planet::Planet(string new_name, int x, int y) {
        name = new_name;
        coord_x = x;
        coord_y = y;
}

Planet::~Planet() {
        
}

string Planet::get_name() {
        return name;
}