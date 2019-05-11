//
// Created by ariana on 10/05/19.
//

#ifndef PC2_ARENA_H
#define PC2_ARENA_H

#include <fstream>
#include <bits/stdc++.h>
#include <cstring>
#include "Fighter.h"

struct Fight{
    Fighter* A;
    Fighter* B;
    Fighter* winner= nullptr;
    int score=0;
};

class Arena{
    std::vector<Fight*> fights;
public:
    Arena(){};
    void add_fights(Fight* fight){fights.push_back(fight);};
    void Run(Fight &fight);
    std::vector<Fight*> get_fights(){ return fights;};
    void load_fights(std::string filename);
    void Run_all();
};

#endif //PC2_ARENA_H
