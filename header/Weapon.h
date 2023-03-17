#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "./Item.h"
#include "./Entity.h"

class Weapon: public Item{

    private:
        int damage;
        int durability;

    public:

        int getDamage();
        int getDurability();

        void lowerDurability();

        bool use(Entity*) override;

        Weapon(std::string Name, int damage, int durability);
    


};


#endif