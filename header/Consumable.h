#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "./StatusEffect.h"
#include "./Item.h"
#include <string>

enum UsageType{
    self,
    enemy
};

class Consumable: public Item{
    private:
        StatusEffect effect;
        UsageType usage;
    
    public:
        StatusEffect getEffect();
        UsageType getUsage();
        ItemTypes getType() override;

        std::string getEffectString();
        std::string getTypeString() override;
        std::string getUsageString();

        bool use(Entity*) override;

        std::string getDescription() override;

        Consumable(std::string Name, StatusEffect effect, UsageType usage);
};

#endif