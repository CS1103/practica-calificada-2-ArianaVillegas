//
// Created by ariana on 10/05/19.
//

#ifndef PC2_ARENA_H
#define PC2_ARENA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Fighter.h"

class Fight{
    Fighter* A;
    Fighter* B;
    Fighter* winner;
    int score;
public:
    Fight(Fighter* A,Fighter* B):A(A),B(B),winner(nullptr),score(0){};
    Fighter* GetA(){ return A;};
    Fighter* GetB(){ return B;};
    void SetWinner(Fighter* winner1){winner=winner1;};
    void SetScore(int score1){score=score1;};
    ~Fight(){delete A;delete B; delete winner;};
};

class Arena{
    std::vector<Fight> fights;
public:
    Arena(){};
    void add_fight(Fight f);
    void run(Fighter A, Fighter B);
    std::vector<Fight> get_fights(){ return fights;};
    void load_fights(std::string filename);
    void run_all();
};

#endif //PC2_ARENA_H
