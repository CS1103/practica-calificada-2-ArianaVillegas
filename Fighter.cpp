//
// Created by ariana on 10/05/19.
//

#include "Fighter.h"

void Fighter::add_defense(char ident) {
    Defense* defense= nullptr;
    switch (ident){
        case 'E':
            defense=new Elude();
            break;
        case 'S':
            defense=new Shield();
            break;
        case 'A':
            defense=new Armor();
            break;
    }
    defensepoints+=defense->defense();
}

void Fighter::add_attack(char ident) {
    Attack* attack= nullptr;
    switch (ident){
        case 'P':
            attack=new Punch();
            break;
        case 'S':
            attack=new Saber();
            break;
        case 'F':
            attack=new Firearm();
            break;
    }
    attackpoints+=attack->attack();
}