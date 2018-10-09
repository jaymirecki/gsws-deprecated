#include <string>
#include <iostream>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
        Weapon();
        Weapon(std::string, int, int, int, int, bool);
        ~Weapon();

        void print(std::ostream &);

        std::string get_name();
        int get_damage();
        int get_min_range();
        int get_max_range();
        int get_accuracy();
        int is_turret();

        void set_name(std::string);
        void set_damage(int);
        void set_min_range(int);
        void set_max_range(int);
        void set_accuracy(int);
        void set_turret(bool);

private:
        std::string name;
        int damage, min_range, max_range, accuracy;
        bool turret;
};

#endif