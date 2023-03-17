#include <string>
#include <cassert>

#include "../header/Weapon.h"
#include "../header/Item.h"
#include "../header/Entity.h"

int Weapon::getDamage(){
    return this->damage;
}
int Weapon::getDurability(){
    return this->durability;
}

void Weapon::lowerDurability(){
    if(durability > 0){
        this->durability = (durability - 1);
    }
}

bool Weapon::use(Entity* enemy){
    enemy->setHealth(enemy->getHealth() - this->getDamage());
    return true;
}

Weapon::Weapon(std::string Name, int damage, int durability): Item(Name){
    assert(damage >= 0 && "Damage of a weapon should not be less than 0");
    assert(durability >=0 && "Durability of a weapon should not be less than 0");
    this->durability = durability;
    this->damage = damage;
}


ItemTypes Weapon::getType(){
    return ItemTypes::WEAPON;
}

std::string Weapon::getTypeString(){
    return "Weapon";
}