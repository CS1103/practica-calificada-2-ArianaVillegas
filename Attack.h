//
// Created by ariana on 10/05/19.
//

#ifndef PC2_ATTACK_H
#define PC2_ATTACK_H

class Attack{
protected:
    int power;
public:
    Attack();
    int attack() { return power;};
};

class Punch:public Attack{
    Punch(){this->power=1;};
};

class Saber:public Attack{
    Saber(){this->power=5;};
};

class Firearm:public Attack{
    Firearm(){this->power=10;};
};

#endif //PC2_ATTACK_H