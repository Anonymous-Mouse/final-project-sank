#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "./Entity.h"
#include <string>

enum ItemTypes{
    ITEM,
    KEY,
    CONSUMABLE,
    WEAPON
};

class Item{
    private:
        std::string Name;
    
    public:
        std::string getName();

        virtual bool use(Entity*);
        virtual ItemTypes getType();
        virtual std::string getTypeString();
        Item(std::string Name);

        virtual std::string getDescription();

};

#endif
