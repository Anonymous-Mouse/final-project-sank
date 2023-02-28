#include "../header/enemy.h"

Enemy::~Enemy() {}

string Enemy::getName(){
    return this->Name;
}

int Enemy::getBaseDamage(){
    return this->BaseDamage;   
}

int Enemy::getHealth(){
    return this->Health;
}

bool Enemy::checkIfDead(){
    return this->IsDead;
}

int Enemy::getDamageSpread(){
    return this->DamageSpread;
}

int Enemy::getEscapeChance(){
    return this->EscapeChance;
}

void Enemy::damageEntity(int dp){
    this->Health = getHealth() - dp;
    if(getHealth() <= 0){
        this->IsDead = true;
        this->Health = 0;
    }
}