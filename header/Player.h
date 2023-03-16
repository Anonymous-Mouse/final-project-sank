#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include "../header/Entity.h"
//#include "../header/Enemy.h"
#include "../header/Container.h"
#include "../header/StatusEffect.h"
#include "../header/Weapon.h"
#include "../header/Item.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Player : public Entity {
    protected:
        Container* inventory;
        int BaseDamage;
        Weapon* equippedWeapon;
        //location: int[2]

    public:
        Player(string name, int health, int baseDamage, Container* inventory) : Entity(name, health) {
            this->BaseDamage = baseDamage;
            this->inventory = inventory;

        }
        
        ~Player(){}
        int getBaseDamage();
        void damageEntity(Entity* enemyTarget);
        bool addEffect(StatusEffect effect);
        bool removeEffect(StatusEffect effect);
        Weapon* getWeapon();
        void setWeapon(Weapon* equippedWeapon);

};

#endif