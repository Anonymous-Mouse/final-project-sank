#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "./StatusEffect.h"
#include "./Item.h"
#include <string>

enum UsageType{
    self,
    enemy
}

class Consumable: public Item{
    private:
        StatusEffect effect;
        UsageType usage;
    
    public:
        StatusEffect getEffect();
        UsageType getUsage();

        bool use(Entity) override;

        Consumable(std::string Name, StatusEffect effect, UsageType usage);
}

#endif