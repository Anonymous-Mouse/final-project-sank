#ifndef LOCKEDROOM_H
#define LOCKEDROOM_H

#include "./Room.h"
#include <string>

class lockedRoom: public Room{

    private:
        std::string keyName;
        bool locked;

    private:
        bool unlock(std::string);

        lockedRoom(std::string keyName);

}

#endif