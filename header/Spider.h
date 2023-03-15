#ifndef SPIDER_H
#define SPIDER_H

#include "../header/Enemy.h"

class Spider: public Enemy{
public:
    Spider(string name, int health, int baseDamage, int damageSpread, int difficultyMultiplier) : Enemy(name, health, baseDamage, damageSpread, difficultyMultiplier){}
    ~Spider();
};

#endif