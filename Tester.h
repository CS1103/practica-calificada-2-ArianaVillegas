//
// Created by ariana on 10/05/19.
//

#ifndef PC2_TESTER_H
#define PC2_TESTER_H

#include "catch.hpp"
#include "Arena.h"

SCENARIO("ARENA"){
  GIVEN("Dos peleas"){
      WHEN("Los peleadores de la primera son BruceLee y ChuckNorris; y, en la segunda son ChuckNorris y JasonStatham"){
          Arena arena;
          Fight f1,f2;
          Fighter *p1,*p2,*p3;
          p1=new BruceLee();
          p2=new ChuckNorris();
          p3=new JasonStatham();
          THEN("Los nombres de p1, p2 y p3 son BruceLee, ChuckNorris y JasonStatham repectivamente"){
              REQUIRE(p1->get_name()=="BruceLee");
              REQUIRE(p2->get_name()=="ChuckNorris");
              REQUIRE(p3->get_name()=="JasonStatham");
          }
          p1->add_attack('P');
          p1->add_attack('S');
          p2->add_attack('P');
          p2->add_attack('F');
          p3->add_attack('S');
          p3->add_attack('F');
          THEN("Los ataques para p1, p2 y p3 serán 6, 11, 15 respectivamente"){
              REQUIRE(p1->attack()==6);
              REQUIRE(p2->attack()==11);
              REQUIRE(p3->attack()==15);
          }
          p1->add_defense('E');
          p1->add_defense('S');
          p2->add_defense('E');
          p2->add_defense('A');
          p3->add_defense('S');
          p3->add_defense('A');
          THEN("Los ataques para p1, p2 y p3 serán 5, 9, 12 respectivamente"){
              REQUIRE(p1->defense()==5);
              REQUIRE(p2->defense()==9);
              REQUIRE(p3->defense()==12);
          }
          f1.A=p1;
          f1.B=p2;
          f2.A=p2;
          f2.B=p3;
          arena.add_fights(&f1);
          arena.add_fights(&f2);
          arena.Run_all();
          THEN("Los scores deben ser 3 y 1; y, los winners deben ser p2 y p3"){
              REQUIRE(arena.get_fights()[0]->score==3);
              REQUIRE(arena.get_fights()[1]->score==1);
              REQUIRE(arena.get_fights()[0]->winner==p2);
              REQUIRE(arena.get_fights()[1]->winner==p3);
          }
          arena.load_fights("peleas.txt");
          THEN("EL tamaño del vector es 5"){
              REQUIRE(arena.get_fights().size()==5);
          }
          arena.Run_all();
          THEN("Los scores son -2,2,2 y los winners A,B,B son respectivamente"){
              REQUIRE(arena.get_fights()[2]->score==-2);
              REQUIRE(arena.get_fights()[3]->score==2);
              REQUIRE(arena.get_fights()[4]->score==2);
              REQUIRE(arena.get_fights()[2]->winner==arena.get_fights()[2]->A);
              REQUIRE(arena.get_fights()[3]->winner==arena.get_fights()[3]->B);
              REQUIRE(arena.get_fights()[4]->winner==arena.get_fights()[4]->B);
          }
      }
  }
}

#endif //PC2_TESTER_H
