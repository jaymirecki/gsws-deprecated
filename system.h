#include <map>

#include "Planet.h"

#ifndef SYSTEM_H
#define SYSTEM_H

struct coordinate_x_y {int x, y;};

class System {
public:
        System();

        System(std::string, coordinate_x_y, std::map<std::string, Planet*>);

        ~System();

        void print(std::ostream &out);
        void print_name(std::ostream &out);

        void set_name(std::string);
        void set_x(int);
        void set_y(int);
        void set_xy(coordinate_x_y);
        void set_planets(std::map<std::string, Planet*>);

        std::string get_name();
        int get_x();
        int get_y();
        coordinate_x_y get_xy();
        std::map<std::string, Planet*> get_planets();

private:
        std::string name;
        coordinate_x_y coord;
        std::map<std::string, Planet*> planets;
};

#endif