//
// Created by ariana on 10/05/19.
//

#ifndef PC2_DEFENSE_H
#define PC2_DEFENSE_H

class Defense{
protected:
    int level;
public:
    Defense();
    int defense(){ return level;};
};

class Elude:public Defense{
    Elude(){this->level=1;};
};

class Shield:public Defense{
    Shield(){this->level=4;};
};

class Armor:public Defense{
    Armor(){this->level=8;};
};

#endif //PC2_DEFENSE_H
