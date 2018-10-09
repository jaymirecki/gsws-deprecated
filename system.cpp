#include <string>
#include <map>
#include "Planet.h"

#include "system.h"

using namespace std;

System::System() {
        name = "noname";
        coord = {0, 0};
}

System::System(string namex, coordinate_x_y coordx, map<string, Planet*> planetsx) {
        name = namex;
        coord = coordx;
        planets = planetsx;
}

System::~System() {
        
}

void System::print(ostream &out) {
        print_name(out);
        out << " (" << coord.x << "," << coord.y << "): ";
        for (map<string, Planet*>::iterator it = planets.begin(); it != planets.end(); it++)
                out << it->second->get_name() << ", ";
        out << endl;
}
void System::print_name(ostream &out) {
        out << name << " System";
}

void System::set_name(string namex) {
        name = namex;
}
void System::set_x(int xx) {
        coord.x = xx;
}
void System::set_y(int yx) {
        coord.y = yx;
}
void System::set_xy(coordinate_x_y coordx) {
        coord = coordx;
}
void System::set_planets(map<string, Planet*> planetsx) {
        planets = planetsx;
}

string System::get_name() {
        return name;
}
int System::get_x() {
        return coord.x;
}
int System::get_y() {
        return coord.y;
}
coordinate_x_y System::get_xy() {
        return coord;
}
map<string, Planet*> System::get_planets() {
        return planets;
}