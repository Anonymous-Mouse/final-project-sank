#include "../header/enemy.h"
#include <assert.h>

using Enemies::Enemy;

Enemy::Enemy()
    : Enemy("Zombie Patient", 100, 10, 25, EnemyType::ZOMBIE)
{

}
//string name, int health, int baseDamage, int damageSpread, int escapeChance, EnemyType type = EnemyType::ZOMBIE
Enemy::Enemy(string name, int health, int baseDamage, int damageSpread, int escapeChance, EnemyType type = EnemyType)
    : name {name},
    health {health},
    baseDamage {baseDamage},
    damageSpread {damageSpread},
    EnemyType {type}
    isDead{false}
{

}

Enemy::getBaseDamage(){
    return baseDamage;   
}

int Enemy::getHealth(){
    return health;
}

bool Enemy::checkIsDead(){
    return isDead;
}

int Enemy::getDamageSpread(){
    return damageSpread;
}

int Enemy::getEscapeChance(){
    return escapeChance;
}

Enemy::takeDamageFromPlayer(int dp){
    health = health - dp;
    if(health <= 0){
        isDead = true;
    }
}