#include "map.h"

using namespace std;

void load_planets();
//coord translate_planet_coords(coord);

Map::Map() {
        window_size = 46;
        zoom = 1;
        center_x = WIDTH / 2;
        center_y = HEIGHT / 2;
        cerr << center_x << ", " << center_y << endl;
        planets = new Planet[10];   
        //load_planets();
}

Map::~Map() {

}

void Map::command_loop(ostream &out) {
        string command;
        while (command != "q") {
                print(out);
                cout << "Please enter a command or type \"help\" for more info\n";
                cin >> command;
                check_command(command, out);
        }
}

void Map::populate(map<string, System*>* systems) {
        for (int i = 0; i < WIDTH; i++) {
                for (int j = 0; j < HEIGHT; j++)
                        map_ray[i][j] = NONE;
        }
        for (map<string, System*>::iterator it = systems->begin(); it != systems->end(); it++) {
            int x, y;
            x = convert_from_coruscant(it->second->get_xy()).x;
            y = convert_from_coruscant(it->second->get_xy()).y;
            map_ray[x][y] = SYS;
        }
}

void Map::print(ostream &out) {
        cerr << "printing...\n";
        int range = window_size / zoom;
        int min_x = center_x - (range / 2);
        int max_x = center_x + (range / 2);
        int min_y = center_y - (range / 2);
        int max_y = center_y + (range / 2);

        // for (int i = min_x; i < max_x; i++)
        //     for (int j = -2; j < zoom; j++)
        //         out << "_";
        // out << endl;
        cerr << range << endl;
        for (int i = min_y; i < max_y; i++) {
                for (int j = min_x; j < max_x; j++){
                        for (int k = 1; k < zoom; k++)
                                out << NONE;
                        if (j < 0 || i < 0 ||j >= WIDTH || i >= HEIGHT)
                                out << NONE;
                        else
                                out << map_ray[j][i];
                        if (j == max_x - 1)
                            out << "|";
                }
                for (int j = 0; j < zoom; j++)
                        out << endl;
        }
        for (int i = 0; i < 138; i++)
            //cout << i << endl;
            cout << '_';
        cout << '|' << endl;
        // for (int i = min_x; i < max_x; i++)
        //     for (int j = -1; j < zoom; j++)
        //         out << "_";
        // out << endl;
        //out << center_x << ", " << center_y << endl;
}

void Map::check_command(string command, ostream &out){
        if (command == "help") {
                print_help(out);
        } else if (command == "+") {
                zoom = zoom * 2;
        } else if (command == "-") {
                zoom = zoom / 2;
                if (zoom < 1) zoom = 1;
        } else if (command == "w" || command == "s" || 
                   command == "a" || command == "d") {
                pan(command);
        } else if (command == "q") {
        } else
                cout << command << " is not a valid command. ";
}

void Map::print_help(ostream &out) {
        out << "Quit: q"       << "    "
            << "Zoom In: +"    << "    "
            << "Zoom Out: -"   << "    "
            << "Pan Up: w"     << "    "
            << "Pan Down: s"   << "    "
            << "Pan Left: a"   << "    "
            << "Pan Right: d"  << "    ";
}

void Map::pan(string direction) {
        int distance = window_size / zoom / 2;
        if (direction == "w")
                center_y -= distance;
        else if (direction == "s")
                center_y += distance;
        else if (direction == "a")
                center_x -= distance;
        else
                center_x += distance;
}

coordinate_x_y Map::convert_from_coruscant(coordinate_x_y coruscant) {
        coordinate_x_y real;
        real.x =   coruscant.x + 54;
        real.y = - coruscant.y + 54;
        return real;
}

/*void load_planets() {
        ifstream input;
        input.open("planets.txt");
        int counter = 0;
        while (!input.eof()) {
            string name;
            input >> name;
            int temp;
            coord xy;
            input >> temp;
            xy.x = stoi(temp);
            input >> temp;
            xy.y = stoi(temp);
            Planet *new_planet = new Planet(name, xy.x, xy.y);
            planets[counter] = new_planet;
        }
}*/