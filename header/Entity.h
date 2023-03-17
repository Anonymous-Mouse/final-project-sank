#ifndef ENTITY_H
#define ENTITY_H
#include "../header/StatusEffect.h"
#include <vector>
#include <string>
using namespace std;


class Entity{
protected:
    string Name;
    int Health;
    bool DeadState;
    vector<StatusEffect> Effects;
public:
    Entity(string name, int health){
        this->Name = name;
        this->Health = health;
        this->DeadState = false;
    }
    virtual ~Entity();
    int getHealth();
    virtual bool addEffect(StatusEffect effect) = 0;
    virtual bool removeEffect(StatusEffect effect) = 0;
    vector<StatusEffect> getEffects();
    void setHealth(int hp);
    bool isDead();
    string getName();
};



#endif