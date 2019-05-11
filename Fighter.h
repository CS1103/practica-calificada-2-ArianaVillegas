//
// Created by ariana on 10/05/19.
//

#ifndef PC2_FIGHTER_H
#define PC2_FIGHTER_H

#include <iostream>
#include <vector>
#include "Defense.h"
#include "Attack.h"

class Fighter{
    int attackpoints=0;
    int defensepoints=0;
protected:
    std::string name;
public:
    Fighter(){};
    void add_attack(char ident);
    void add_defense(char ident);
    std::string get_name(){ return name;};
    int attack(){ return attackpoints;};
    int defense(){ return defensepoints;};
};

class BruceLee:public Fighter{
public:
    BruceLee(){this->name="BruceLee";};
};

class ChuckNorris:public Fighter{
public:
    ChuckNorris(){this->name="ChuckNorris";};
};

class JasonStatham:public Fighter{
public:
    JasonStatham(){this->name="JasonStatham";};
};

#endif //PC2_FIGHTER_H
