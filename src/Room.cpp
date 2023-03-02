#include "../header/Room.h"
#include "../header/Container.h"
#include <string>
#include "../header/Enemy.h"
#include <cstdlib>

bool Room::rollEnemySpawn(){
    int roll = std::rand() % 100 + 1; // roll 1 - 100
    if(roll > this->EnemySpawnChance){
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

Enemy Room::getEnemy(){
    return this->enemy;
}

Container Room::getChest(){
    return this->container;
}


Room::Room(Enemy enemy&, int EnemySpawnChance, Container container&){
    this->enemy = &enemy;
    this->EnemySpawnChance = EnemySpawnChance;
    this->container = &container
}

Room::Room(Enemy enemy&, int EnemySpawnChance){
    this->enemy = &enemy;
    this->EnemySpawnChance = EnemySpawnChance;
}