#include "../header/StatusEffect.h"
#include "../header/Item.h"
#include "../header/Consumable.h"
#include "./Entity.h"
#include <string>

StatusEffect Consumable::getEffect(){
    return this->effect;
}
UsageType Consumable::getUsage(){
    return this->usage;
}

bool Consumable::use(Entity* entity){
    return entity->addEffect(this->getEffect());
}

Consumable::Consumable(std::string Name, StatusEffect effect, UsageType usage): Item(Name){
    this->effect = effect;
    this->usage = usage;
}
