#include <iostream>
#include <string>
#include <map>

#include "map.h"
#include "initializations.h"

using namespace std;

const double VERSION = 0.1;
const string SYSTEMS = "systems.csv";
const string WEAPONS = "weapons.csv";
const string STARSHIP_TEMPS = "starship_temps.csv";

struct Sim_Object {Map *sim_map; map<string, System*> *systems; map<string, Weapon*> *weapons; map<string, StarshipTemp*> *starship_temps;};

void command_loop(Map*);
void print_help();

int main() {
        string save_directory;
        Sim_Object databases;

        cout << "Loading GSWS..." << endl;
        databases.sim_map = new Map();
        cout << "Welcome to Galactic Star Wars Simulator " << VERSION << endl
             << "Please enter your desired save directory:" << endl;
        cin >> save_directory;
        databases.systems = build_system_list(SYSTEMS);
        databases.sim_map->populate(databases.systems);

        for (map<string, System*>::iterator it = databases.systems->begin(); it != databases.systems->end(); it++) {
            it->second->print(cout);
            cout << endl;
        }

        databases.weapons = build_weapon_list(WEAPONS);

        for (map<string, Weapon*>::iterator it = databases.weapons->begin(); it != databases.weapons->end(); it++) {
            it->second->print(cout);
            cout << endl;
        }

        databases.starship_temps = build_starship_template_list(STARSHIP_TEMPS);

        for (map<string, StarshipTemp*>::iterator it = databases.starship_temps->begin(); it != databases.starship_temps->end(); it++) {
            it->second->print(cout);
            cout << endl;
        }

        command_loop(databases.sim_map);

        cout << "Thank you for using Galactic Star Wars Simulator" << endl;
}

void command_loop(Map *main_map) {
        string command = "";

        while (command != "q") {
                cout << "Please choose an option or enter \"h\" for help:" 
                     << endl;
                cin >> command;

                if (command == "w") {
                        cout << "Warfare is not implemented yet!" << endl;
                } else if (command == "p") {
                        cout << "Politics are not implemented yet!" << endl;
                } else if (command == "m") {
                        main_map->command_loop(cout);
                } else if (command == "n") {
                        cout << "News is not implemented yet!" << endl;
                } else if (command == "h") {
                        print_help();
                }
        }
}

void print_help() {
        cout << "Warfare: w    "
             << "Politics: p    "
             << "Map: m    "
             << "News: n    " << endl;
}