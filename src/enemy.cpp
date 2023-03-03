#include "../header/enemy.h"

Enemy::~Enemy() {}


int Enemy::getBaseDamage(){
    return this->BaseDamage;   
}

int Enemy::getDamageSpread(){
    return this->DamageSpread;
}

int Enemy::getEscapeChance(){
    return this->EscapeChance;
}

void Enemy::damageEntity(/*Player* playerTarget or Player & playerTarget*/){
    //May need to refactor this function once it has access to the Player class
    //playerTarget->setHealth(playerTarget->getHealth() - baseDamage);
    
}

 bool Enemy::addEffect(StatusEffect effect){
    
        if(this->Effects.empty()){
            this->Effects.push_back(effect);
            return true;
        }else{
        bool foundElement = false;
        for(vector<StatusEffect>::iterator it = Effects.begin(); it != Effects.end(); ++it) {
             if(*it == effect){
                foundElement = true;
                break;
             }
        }
        if(foundElement == true){
            //do nothing, element already exists in container
            return false;
        }
        else{
            this->Effects.push_back(effect);
            return true;
        }
        }
}

 bool Enemy::removeEffect(StatusEffect effect){
    
        if(this->Effects.empty()){
            return true;
        }else{
            auto it = find(Effects.begin(), Effects.end(), effect);
            if(it != Effects.end()){
                Effects.erase(it);
            }
            auto doubleCheck = find(Effects.begin(), Effects.end(), effect);
            if(it != Effects.end()){
                return false;
            }
            else{
                return true;
            }
        }
}