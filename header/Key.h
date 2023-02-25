#ifndef KEY_H
#define KEY_H

#include "./Item.h"
#include "./Entity.h"

class Key: public Item{

    public:
        bool use(Entity) override;

        Key(std::string Name);
}

#endif