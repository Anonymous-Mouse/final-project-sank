#include "../header/StatusEffect.h"
#include "../header/Item.h"
#include "../header/Consumable.h"
#include "./Entity.h"
#include <string>

StatusEffect Consumable::getEffect(){
    return this->effect;
}

std::string Consumable::getEffectString(){
    switch(this->effect){
        case StatusEffect::Heal:
            return "Heal";
        case StatusEffect::ReduceMaxHealth:
            return "Reduce Max Health";
        case StatusEffect::Slow:
            return "Slow";
        case StatusEffect::ReduceBaseDamage:
            return "ReduceBaseDamage";
    }
}

UsageType Consumable::getUsage(){
    return this->usage;
}

std::string Consumable::getUsageString(){
    switch(this->effect){
        case UsageType::self:
            return "Self";
        case UsageType::enemy:
            return "Enemy";
    }
}

bool Consumable::use(Entity* entity){
    return entity->addEffect(this->getEffect());
}

Consumable::Consumable(std::string Name, StatusEffect effect, UsageType usage): Item(Name){
    this->effect = effect;
    this->usage = usage;
}

ItemTypes Consumable::getType(){
    return ItemTypes::CONSUMABLE;
}

std::string Consumable::getTypeString(){
    return "Consumable";
}

std::string Item::getDescription(){
    return getTypeString() + " - Name: " + this->getName() + " - Usage: " + this->getUsageString() + " - Effect: " + getEffectString();
 }