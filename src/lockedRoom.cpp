#include "../header/lockedRoom.h"
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

lockedRoom::lockedRoom(std::string keyName){
    this->keyName = keyName;
    this->locked = true;
}