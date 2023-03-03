#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "../header/enemy.h"

class Zombie: public Enemy{
public:
    Zombie(string name, int health, int baseDamage, int damageSpread, int difficultyMultiplier) : Enemy(name, health, baseDamage, damageSpread, difficultyMultiplier){}

};

#endif