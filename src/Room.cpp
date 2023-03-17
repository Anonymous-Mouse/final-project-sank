#include "../header/Room.h"
#include "../header/Container.h"
#include <string>
#include "../header/Enemy.h"
#include <cstdlib>

bool Room::rollEnemySpawn(){
    int roll = std::rand() % 100 + 1; // roll 1 - 100
    if(roll < this->EnemySpawnChance){
        this->enemyAlive = true;
        return true;
    }else{
        return false;
    }
}

bool Room::isLocked(){
    return false;
}

std::string Room::getName(){
    return this->Name;
}

bool Room::isThereEnemy(){
    return this->enemyAlive;
}

bool Room::isThereChest(){
    return this->chestExists;
}

Enemy& Room::getEnemy(){
    return *(this->enemy);
}

Container& Room::getChest(){
    return *(this->container);
}

bool Room::isThereLore(){
    return this->hasLore;
}
std::string Room::getLore(){
    return this->lore;
}


/*Room::Room(std::string Name){
    this->EnemySpawnChance = 0;
    this->enemyAlive = false;
    this->chestExists = false;
    this->Name = Name;
}*/

Room::Room(std::string Name, Enemy* enemy, int EnemySpawnChance , Container* container, std::string lore){
    this->Name = Name;
    if(enemy != nullptr){
        this->enemy = enemy;
        this->enemyAlive = true;
        this->EnemySpawnChance = EnemySpawnChance;
    }else{
        this->enemy = nullptr;
        this->enemyAlive = false;
        this->EnemySpawnChance = 0;
    }

    if(container != nullptr){
        this->container = container;
        this->chestExists = true;
    }else{
        this->container = nullptr;
        this->chestExists = false;
    }

    this->lore = lore;

    if(lore.length() < 1){
        this->hasLore = false;
    }else{
        this->hasLore = true;
    }
}



Room::~Room(){
    if(this->enemy != nullptr){
        delete this->enemy;
    }
    if(this->container != nullptr){
        delete this->container;
    }  
}