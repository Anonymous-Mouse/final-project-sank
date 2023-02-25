#include "../header/StatusEffect.h"
#include "../header/Item.h"
#include "../header/Consumable.h"
#include "./Entity.h"
#include <string>

StatusEffect Consumable::getEffect();
UsageType Consumable::getUsage();

bool Consumable::use(Entity enemy) override{
    return enemy.addEffect(this->getEffect());
}

Consumable::Consumable(std::string Name, StatusEffect effect, UsageType usage): Item(Name){
    this->effect = effect;
    this->usage = usage
}
