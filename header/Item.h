#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "./Entity.h"


class Item{
    private:
        std::string Name;
    
    public:
        std::string getName();

        virtual bool use(Entity*) = 0;

        Item(std::string Name);

};

#endif
