#ifndef RAT_H
#define RAT_H
#include "../header/enemy.h"

class Rat: public Enemy{
public:
    Rat(string name, int health, int baseDamage, int damageSpread) : Enemy(name, health, baseDamage, damageSpread){}
    void addEffect(Entity enemy) override {}
};
#endif