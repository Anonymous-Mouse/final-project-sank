#ifndef ROOM_H
#define ROOM_H

#include "./Container.h"
#include <string>
#include "./Enemy.h"

class Room{
    private:
    Container* container = nullptr;
    std::string Name;
    Enemy* enemy = nullptr;
    int EnemySpawnChance;
    bool enemyAlive;
    bool chestExists;

    public:
    bool rollEnemySpawn();
    std::string getName();
    bool isThereEnemy();
    bool isThereChest();
    Enemy& getEnemy();
    Container& getChest();

    Room(std::string Name, Enemy* enemy = nullptr, int EnemySpawnChance = 0, Container* container = nullptr);
    // Room(std::string Name);

    ~Room();
    
};

#endif