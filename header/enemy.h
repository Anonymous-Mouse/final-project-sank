#ifndef ENEMY_H
#define ENEMY_H
#include <string>
using namespace std;

class Enemy{
private:
    int DamageSpread;
protected:
    string Name;
    int BaseDamage;
    int Health;
    int EscapeChance;
    bool IsDead;
public:
    Enemy(string name, int health, int baseDamage, int damageSpread){
        this->Name = name;
        this->Health = health;
        this->BaseDamage = baseDamage;
        this->DamageSpread = damageSpread;
        this->IsDead = false;
        srand((unsigned) time(NULL));


        this->EscapeChance = rand() % 101;
    }
    virtual ~Enemy();
    string getName();
    int getEscapeChance();
    int getBaseDamage();
    int getDamageSpread();
    int getHealth();
    bool checkIfDead();
    void setHealth(int dp);
    virtual void addEffect(Entity enemy) { };
};



#endif