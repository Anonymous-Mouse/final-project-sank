#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include "../header/Entity.h"
//#include "../header/Enemy.h"
#include "../header/Container.h"
#include "../header/StatusEffect.h"
#include "../header/Weapon.h"
#include "../header/Item.h"
#include "../header/Consumable.h"
#include "../header/Level.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Player : public Entity {
    protected:
        Container* inventory;
        int BaseDamage;
        Weapon* equippedWeapon;
        vector<int> location;

    public:
        Player(string name, int health, int baseDamage, Container* inventory) : Entity(name, health) {
            this->BaseDamage = baseDamage;
            this->inventory = inventory;
            this->location = vector<int>(2);

        }
        
        ~Player(){}
        int getBaseDamage();
        void damageEntity(Entity* enemyTarget);
        bool addEffect(StatusEffect effect);
        bool removeEffect(StatusEffect effect);
        Weapon* getWeapon();
        void setWeapon(Weapon* equippedWeapon);
        void movePlayer(int x, int y);
        int getLocationX();
        int getLocationY();

};

#endif