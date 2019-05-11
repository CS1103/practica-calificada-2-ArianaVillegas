#include <iostream>

#define CATCH_CONFIG_MAIN

#include "Tester.h"
#include "catch.hpp"

#ifndef CATCH_CONFIG_MAIN

#include "Arena.h"

int main() {
    Arena arena;
    Fight f1,f2;
    Fighter *p1,*p2,*p3;
    p1=new BruceLee();
    p2=new ChuckNorris();
    p3=new JasonStatham();
    p1->add_attack('P');
    p1->add_attack('S');
    p2->add_attack('P');
    p2->add_attack('F');
    p3->add_attack('S');
    p3->add_attack('F');
    p1->add_defense('E');
    p1->add_defense('S');
    p2->add_defense('E');
    p2->add_defense('A');
    p3->add_defense('S');
    p3->add_defense('A');
    f1.A=p1;
    f1.B=p2;
    f2.A=p2;
    f2.B=p3;
    arena.add_fights(&f1);
    arena.add_fights(&f2);
    arena.Run_all();
    arena.load_fights("peleas.txt");
    arena.Run_all();

    return 0;
}

#endif