#include "../header/lockedRoom.h"
#include "../header/Room.h"
#include "../header/Entity.h"
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

lockedRoom::lockedRoom(std::string keyName, Enemy enemy*, int EnemySpawnChance , Container container*): Room(enemy, EnemySpawnChance , container*){
    this->keyName = keyName;
    this->locked = true;
}

lockedRoom::lockedRoom(std::string keyName): Room(){
    this->keyName = keyName;
    this->locked = true;
}