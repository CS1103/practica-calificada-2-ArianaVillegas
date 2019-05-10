//
// Created by ariana on 10/05/19.
//

#ifndef PC2_FIGHTER_H
#define PC2_FIGHTER_H

#include <iostream>
#include <numeric>
#include "vector"
#include "Defense.h"
#include "Attack.h"

class Fighter{
    std::vector<int> d;
    std::vector<int> a;
public:
    Fighter(std::vector<int> d,std::vector<int> a):d(d),a(a){};
    int defense();
    int attack();
};

class BruceLee:public Fighter{

};

class ChuckNorris:public Fighter{

};

class JasonStatham:public Fighter{

};

#endif //PC2_FIGHTER_H
