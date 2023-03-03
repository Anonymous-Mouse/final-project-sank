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

bool Room::getName(){
    return this->Name;
}

bool Room::isThereEnemy(){
    return this->enemyAlive;
}

bool Room::isThereChest(){
    return this->chestExists;
}

Enemy& Room::getEnemy(){
    return this->enemy;
}

Container& Room::getChest(){
    return this->container;
}


Room::Room(Enemy enemy*, int EnemySpawnChance , Container container*){
    if(enemy != null){
        this->enemy = enemy;
        this->enemyAlive = true;
        this->EnemySpawnChance = EnemySpawnChance;
    }else{
        this->enemyAlive = false;
        this->EnemySpawnChance = 0;
    }

    if(container != null){
        this->container = container;
        this->chestExists = true;
    }else{
        this->chestExists = false;
    }
}

Room::Room(){
    this->EnemySpawnChance = 0;
    this->enemyAlive = false;
    this->chestExists = false;
}

Room::~Room(){
    delete this->enemy;
    delete this->container;
}