#include "weapon.h"

using namespace std;

Weapon::Weapon() {
        name = "default weapon";
        damage = 0;
        min_range = 0;
        max_range = 0;
        accuracy = 0;
        turret = false;
}
Weapon::Weapon(string namex, int damagex, int min_rangex, 
               int max_rangex, int accuracyx, bool turretx) {
        name = namex;
        damage = damagex;
        min_range = min_rangex;
        max_range = max_rangex;
        if (accuracyx < 0) {
                cerr << accuracyx << " is not a valid accuracy" << endl;
                return;
        }
        accuracy = accuracyx;
        turret = turretx;
}
Weapon::~Weapon() {

}

void Weapon::print(ostream &out) {
        out << name << ": " << damage << ", " << min_range << "-" 
            << max_range << ", " << accuracy << ", " << turret;
}

string Weapon::get_name() {
        return name;
 }
int Weapon::get_damage() {
        return damage;
}
int Weapon::get_min_range() {
        return min_range;
}
int Weapon::get_max_range() {
        return max_range;
}
int Weapon::get_accuracy() {
        return accuracy;
}
int Weapon::is_turret() {
        return turret;
}

void Weapon::set_name(string namex) {
        name = namex;
}
void Weapon::set_damage(int damagex) {
        damage = damagex;
}
void Weapon::set_min_range(int min_rangex) {
        min_range = min_rangex;
}
void Weapon::set_max_range(int max_rangex) {
        max_range = max_rangex;
}
void Weapon::set_accuracy(int accuracyx) {
        accuracy = accuracyx;
}
void Weapon::set_turret(bool turretx) {
        turret = turretx;
}