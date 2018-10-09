#include "initializations.h"

#include <fstream>

#include "system.h"

using namespace std;

char *next_string();
int next_int();

char *next_string() {
    return strtok(NULL, ",");
}
int next_int() {
    return stoi(strtok(NULL, ","));
}

map<string, System*> *build_system_list(string filename) {
        cout << "Building system database...\n";

        // Open the file and check for errors
        ifstream input;
        open_file(input, filename);

        map<string, System*> *systems = new map<string, System*>;

        while (!input.eof()) {
                string line, parsed_line;
                System *curr_system = new System();

                // Get the next line and store in c string for parsing
                getline(input, line);
                char * cline = new char[line.length() + 1];
                strcpy(cline, line.c_str());

                // Set system members and add to map
                curr_system->set_name(strtok(cline, ","));
                curr_system->set_x(stoi(strtok(NULL, ",")));
                curr_system->set_y(stoi(strtok(NULL, ",")));
                systems->insert(pair<string, System*>(curr_system->get_name(), curr_system));
        }

        input.close();

        return systems;
}

map<string, Weapon*> *build_weapon_list(string filename) {
        cout << "Building weapon database...\n";

        ifstream input;
        open_file(input, filename);

        map<string, Weapon*> *weapons = new map<string, Weapon*>;

        while (!input.eof()) {
                Weapon *curr_weapon = make_weapon(input);
                weapons->insert(pair<string, Weapon*>(curr_weapon->get_name(), curr_weapon));
        }

        return weapons;
}

map<string, StarshipTemp*> *build_starship_template_list(string filename) {
        cout << "Building starship template database...\n";

        ifstream input;
        open_file(input, filename);

        map<string, StarshipTemp*> *starship_templates = 
                                                new map<string, StarshipTemp*>;

        while (!input.eof()) {
                StarshipTemp *curr_temp = make_starship_temp(input);
                starship_templates->insert(pair<string, StarshipTemp*>(curr_temp->get_name(), curr_temp));
        }

        return starship_templates;
}

Weapon *make_weapon(istream &input) {
        string line, parsed_line;
        Weapon *curr_weapon = new Weapon;

        getline(input, line);
        char *cline = new char[line.length() + 1];
        strcpy(cline, line.c_str());

        curr_weapon->set_name(strtok(cline, ","));
        curr_weapon->set_damage(stoi(strtok(NULL, ",")));
        curr_weapon->set_min_range(stoi(strtok(NULL, ",")));
        curr_weapon->set_max_range(stoi(strtok(NULL, ",")));
        curr_weapon->set_accuracy(stoi(strtok(NULL, ",")));
        line = strtok(NULL, ",");
        if (line == "true") curr_weapon->set_turret(true);
        else curr_weapon->set_turret(false);

        return curr_weapon;
}

StarshipTemp *make_starship_temp(istream &input) {
        string line, parsed_line;
        StarshipTemp *curr_temp = new StarshipTemp;

        getline(input, line);
        char *cline = new char[line.length() + 1];
        strcpy(cline, line.c_str());

        curr_temp->set_fields(strtok(cline, ","), next_string(), next_int(), next_int(), next_int(), next_int(), next_int(), next_int(), next_int(), next_int(), new list<Weapon*>);

        return curr_temp;
}

// string split_string(string unparsed, char delimiter) {
//     for (int i = 0; i < unparsed.length(); i++) {
//         if (i )
//     }
// }

void open_file(ifstream &input, string filename) {
        input.open(filename);
        if (!input.is_open())
                cerr << "Failed to build system database from " 
                     << filename << endl;\
}