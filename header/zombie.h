#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "../header/enemy.h"

class Zombie: public Enemy{
public:
    Zombie(string name, int health, int baseDamage, int damageSpread) : Enemy(name, health, baseDamage, damageSpread){}
    void addEffect(Entity enemy) override {}
};

#endif