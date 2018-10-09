#include "starship_temp.h"
#include "character.h"

#ifndef STARSHIP_H
#define STARSHIP_H

class Starship{
public:
        Starhip();
        ~Starship();

private:
        StarshipTemp *model;
        Character *captain, first_mate;
        
}