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
    std::string lore;
    bool hasLore;

    public:
    bool rollEnemySpawn();
    std::string getName();
    bool isThereEnemy();
    bool isThereChest();
    virtual bool isLocked();
    Enemy& getEnemy();
    Container& getChest();
    bool isThereLore();
    std::string getLore();


    Room(std::string Name, Enemy* enemy = nullptr, int EnemySpawnChance = 0, Container* container = nullptr, std::string lore = "");
    // Room(std::string Name);
    
    ~Room();
    
};

#endif