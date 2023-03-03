#ifndef LOCKEDROOM_H
#define LOCKEDROOM_H

#include "./Room.h"
#include "./Entity.h"
#include "./Container.h"
#include <string>

class lockedRoom: public Room{

    private:
        std::string keyName;
        bool locked;

    private:
        bool unlock(std::string);

        lockedRoom(std::string keyName, Enemy*, int, Container*);
        lockedRoom(std::string keyName);

}

#endif