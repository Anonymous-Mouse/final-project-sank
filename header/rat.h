#ifndef RAT_H
#define RAT_H
#include "../header/enemy.h"

class Rat: public Enemy{
public:
    Rat(string name, int health, int baseDamage, int damageSpread) : Enemy(name, health, baseDamage, damageSpread){}
    void addEffect(StatusEffect effect) override {
        for(int i =0; i < Effects.)
        this->getEffects.pushback(effect);


    }

};
#endif