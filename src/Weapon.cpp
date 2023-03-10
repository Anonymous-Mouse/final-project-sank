#include <string>

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
    this->durability = (durability - 1);
}

bool Weapon::use(Entity* enemy){
    enemy->setHealth(enemy->getHealth() - this->getDamage());
    return true;
}

Weapon::Weapon(std::string Name, int damage, int durability): Item(Name){
    this->durability = durability;
    this->damage = damage;
}


