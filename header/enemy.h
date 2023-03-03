#ifndef ENEMY_H
#define ENEMY_H
#include "../header/entity.h"
#include "../header/player.h"
#include <string>
#include <algorithm>

using namespace std;


class Enemy: public Entity{
protected:
    int BaseDamage;
    int EscapeChance;
    int DamageSpread;
    int difficultyMultiplier;
public:
    Enemy(string name, int health, int baseDamage, int damageSpread, int difficultyMultiplier) : Entity(name, health){
        srand(time(0));
        this->EscapeChance = rand() % 100;
        this->difficultyMultiplier = difficultyMultiplier;
        this->Health = health + ((health*difficultyMultiplier)/20);
        this->BaseDamage = baseDamage * difficultyMultiplier;
        this->DamageSpread = damageSpread;
    }
    virtual ~Enemy();
    int getEscapeChance();
    int getBaseDamage();
    int getDamageSpread();
    void damageEntity(/*Player playerTarget*/);
    virtual bool addEffect(StatusEffect effect);
    virtual bool removeEffect(StatusEffect effect);
};

#endif