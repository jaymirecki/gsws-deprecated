#include <string>
#include <list>

#include "weapon.h"

#ifndef STARSHIP_TEMP_H
#define STARSHIP_TEMP_H

class StarshipTemp{
public:
        StarshipTemp();
        ~StarshipTemp();

        void print(std::ostream&);

        void set_fields(std::string, std::string, int, int, int, int, int, int, int, int, std::list<Weapon*> *weapons);

        std::string get_name() const;
        std::string get_classification() const;
        int get_cost() const;
        int get_realspeed() const;
        int get_hyperdrive() const;
        int get_shield() const;
        int get_armor() const;
        int get_crew() const;
        int get_passengers() const;
        int get_complement() const;

private:
        std::string name, classification;
        int cost, realspeed, hyperdrive, shield, 
            armor, crew, passengers, complement;
        std::list<Weapon*> *weapons;
};

#endif