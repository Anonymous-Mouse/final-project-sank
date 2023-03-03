#include "../header/lockedRoom.h"
#include "../header/Room.h"
#include "../header/Enemy.h"
#include "../header/Container.h"

#include <string>

bool lockedRoom::unlock(std::string keyName){
    int res = keyName.compare(this->keyName);
    if(res == 0){
        this->locked = false;
        return true;
    }else{
        return false;
    }
}

lockedRoom::lockedRoom(std::string keyName, std::string roomName, Enemy* enemy, int EnemySpawnChance , Container* container):
 Room(roomName, enemy, EnemySpawnChance , container){
    this->keyName = keyName;
    this->locked = true;
}

bool lockedRoom::isLocked(){
    return this->locked;
}

/*lockedRoom::lockedRoom(std::string keyName, std::string roomName): 
Room(roomName){
    this->keyName = keyName;
    this->locked = true;
}*/