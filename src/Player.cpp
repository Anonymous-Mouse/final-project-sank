#include "../header/Player.h"

int Player::getBaseDamage() {
    return this->BaseDamage;
}

void Player::damageEntity(Entity* enemyTarget) {
    enemyTarget->setHealth(enemyTarget->getHealth() - BaseDamage);
    vector<StatusEffect> temp = getEffects();
    for(vector<StatusEffect>::iterator it = Effects.begin(); it != Effects.end(); ++it){
        enemyTarget->addEffect(*it);
    }
}

bool Player::addEffect(StatusEffect effect){
    if(effect != StatusEffect::Heal){
        this->setHealth(this->getHealth() + 15);
        return true;
    }else{
        auto it = find(Effects.begin(), Effects.end(), effect);
        if(it == Effects.end()){
            this->Effects.push_back(effect);
        }
        
    }
    

}

Container* Player::getInventory(){
    return this->inventory;
}

bool Player::removeEffect(StatusEffect effect){
    
    if(this->Effects.empty()){
        return true;
    }
    else{
        auto it = find(Effects.begin(), Effects.end(), effect);
        if(it != Effects.end()){
            this->Effects.erase(it);
        }
        auto doubleCheck = find(Effects.begin(), Effects.end(), effect);
        if(doubleCheck != Effects.end()){
            return false;
        }
        else{
            return true;
        }
    }
}

Weapon* Player::getWeapon() {
    return this->equippedWeapon;
}

void Player::setWeapon(Weapon* equippedWeapon) {
    this->equippedWeapon = equippedWeapon;
}

void Player::movePlayer(int x, int y) {
    location.at(0) = x;
    location.at(1) = y;
}

int Player::getLocationX() {
    return location.at(0);
}

int Player::getLocationY() {
    return location.at(1);
}

