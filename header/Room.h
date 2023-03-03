#ifndef ROOM_H
#define ROOM_H

#include "./Container.h"
#include <string>
#include "./Enemy.h"

class Room{
    private:
    Container* container;
    string Name;
    Enemy* enemy;
    int EnemySpawnChance;
    bool enemyAlive;
    bool chestExists;

    public:
    bool rollEnemySpawn();
    std::string getName();
    bool isThereEnemy();
    bool isThereChest();
    Enemy getEnemy();
    Container getChest();

    Room(Enemy enemy* = nullptr, int EnemySpawnChance, Container container* = nullptr);
    Room();

    ~Room();
    
}

#endif