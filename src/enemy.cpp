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

void Enemy::damageEntity(Entity enemy){
    this->Health = getHealth() - dp;
    if(getHealth() <= 0){
        this->IsDead = true;
        this->Health = 0;
    }
}