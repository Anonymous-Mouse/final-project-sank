#ifndef ENEMY_H
#define ENEMY_H
#include "../header/entity.h"
#include <string>

using namespace std;

enum StatusEffect{
    ReduceMaxHealth,
    Heal,
    ReduceBaseDamage,
    Slow
};

class Enemy: public Entity{
private:
    int DamageSpread;
protected:
    int BaseDamage;
    int EscapeChance;
public:
    Enemy(int baseDamage, int damageSpread) : Entity(Name, Health){
        this->Name = name;
        this->Health = health;
        this->BaseDamage = baseDamage;
        this->DamageSpread = damageSpread;
        this->IsDead = false;
        srand((unsigned) time(NULL));


        this->EscapeChance = rand() % 101;
    }
    virtual ~Enemy();
    int getEscapeChance();
    int getBaseDamage();
    int getDamageSpread();
    void damageEntity(int dp);
    virtual void addEffect(StatusEffect effect) {};
};



#endif