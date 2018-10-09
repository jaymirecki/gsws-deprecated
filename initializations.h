#include <string>
#include <map>
#include <cstring>

#include "system.h"
#include "weapon.h"
#include "starship_temp.h"

std::map<std::string, System*> *build_system_list(std::string);
std::map<std::string, Weapon*> *build_weapon_list(std::string);
std::map<std::string, StarshipTemp*> *build_starship_template_list(std::string);

Weapon *make_weapon(std::istream&);
StarshipTemp *make_starship_temp(std::istream&);

std::string split_string(std::string, char);
void open_file(std::ifstream&, std::string);