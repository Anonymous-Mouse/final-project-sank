#ifndef ENEMY_H
#define ENEMY_H
#include <string>
using namespace std;

namespace Enemies{
class Enemy{
public:
    enum class EnemyType{
        ZOMBIE = 0, GIANTSPIDER, MUTATEDRAT,
    };
protected:
    string name;
    int baseDamage;
    int health;
    int damageSpread;
    int escapeChance;
    bool isDead;
    EnemyType monstertype;
public:
    Enemy();
    Enemy(string name, int health, int baseDamage, int damageSpread, int escapeChance, EnemyType type = EnemyType::ZOMBIE);
    ~Enemy() = default;
    int getEscapeChance();
    int getBaseDamage();
    int getHealth();
    bool checkIsDead();
    void takeDamageFromPlayer(int dp);
};


};

#endif