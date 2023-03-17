#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "./Entity.h"

enum ItemTypes{
    Item,
    Key,
    Consumable,
    Weapon
}

class Item{
    private:
        std::string Name;
    
    public:
        std::string getName();

        virtual bool use(Entity*);
        virtual ItemTypes getType();
        Item(std::string Name);

};

#endif
