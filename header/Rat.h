#ifndef RAT_H
#define RAT_H
#include "../header/Enemy.h"
#include <iostream>

class Rat: public Enemy{
public:
    Rat(string name, int health, int baseDamage, int damageSpread, int difficultyMultiplier) : Enemy(name, health, baseDamage, damageSpread, difficultyMultiplier){}
    ~Rat();
};
#endif