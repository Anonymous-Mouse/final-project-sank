#ifndef KEY_H
#define KEY_H

#include "./Item.h"
#include "./Entity.h"

class Key: public Item{

    public:
        bool use(Entity*) override;

        ItemTypes getType() override;

        Key(std::string Name);

        std::string getTypeString() override;
};

#endif