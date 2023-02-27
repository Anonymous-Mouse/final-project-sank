#ifndef SPIDER_H
#define SPIDER_H

#include "../header/enemy.h"

class Spider: public Enemy{
public:
    Spider(string name, int health, int baseDamage, int damageSpread) : Enemy(name, health, baseDamage, damageSpread){}
    void addEffect(Entity enemy) override {}
};

#endif