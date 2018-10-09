#include <iostream>

#include "map.h"

using namespace std;

int main() {
        Map this_map;

        this_map.populate();

        this_map.command_loop(cout);

        //this_map.print(cout);

        return 0;
}