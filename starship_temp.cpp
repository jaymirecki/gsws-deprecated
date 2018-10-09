#include "starship_temp.h"

using namespace std;

StarshipTemp::StarshipTemp() {
        classification = name = "template";
}

StarshipTemp::~StarshipTemp() {

}

void StarshipTemp::print(ostream &out) {
        out << name << " (" << classification << "): " << cost;
}

void StarshipTemp::set_fields(string namex, string classificationx, int costx, 
                              int realspeedx, int hyperdrivex, int shieldx, 
                              int armorx, int crewx, int passengersx, 
                              int complementx, list<Weapon*> *weaponsx) {
        name = namex;
        classification = classificationx;
        cost = costx;
        realspeed = realspeedx;
        hyperdrive = hyperdrivex;
        shield = shieldx;
        armor = armorx;
        crew = crewx;
        passengers = passengersx;
        complement = complementx;
        weapons = weaponsx;
}

string StarshipTemp::get_name() const {
        return name;
}