//
// Created by ariana on 10/05/19.
//

#include "Fighter.h"

int Fighter::defense() {
    return std::accumulate(d.begin(),d.end(),0);
}

int Fighter::attack() {
    return std::accumulate(a.begin(),a.end(),0);
}