#ifndef LOCKEDROOM_H
#define LOCKEDROOM_H

#include "./Room.h"
#include "./Enemy.h"
#include "./Container.h"
#include <string>

class lockedRoom: public Room{

    private:
        std::string keyName;
        bool locked;

    public:
        bool unlock(std::string);
        bool isLocked();
        lockedRoom(std::string keyName, std::string roomName, Enemy* enemy = nullptr, int EnemySpawnChance = 0, Container* container = nullptr);
        //lockedRoom(std::string keyName, std::string roomName);

};

#endif