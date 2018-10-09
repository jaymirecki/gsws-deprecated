#include <iostream>
#include <fstream>
#include <string>
#include "system.h"

#ifndef MAP_H
#define MAP_H

const std::string SYS = " * ";
const std::string NONE = "   ";
const int WIDTH = 6 * 20;
const int HEIGHT = 6 * 21;

class Map {
public:
        Map();

        ~Map();

        void command_loop(std::ostream &);

        void populate(std::map<std::string, System*>*);

        void print(std::ostream &);

        void check_command(std::string, std::ostream &);

        void print_help(std::ostream &);

        void pan(std::string);

private:
        coordinate_x_y convert_from_coruscant(coordinate_x_y);

        int window_size;
        std::string map_ray[WIDTH][HEIGHT];
        int zoom;
        int center_x;
        int center_y;
        Planet *planets;
        struct coord {
                int x, y;
        };
};
#endif