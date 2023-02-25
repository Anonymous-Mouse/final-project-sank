#ifndef MONSTER_H
#define MONSTER_H
#include "../header/enemy.h"
#include <string>
using namespace std;
namespace Monsters{
class Monster: public Enemy{
public:
    enum class StatusEffect
    {
        ZOMBIEBITE, SPIDERPOISON, RATSEPSIS
    }
    Monster();
    Monster(StatusEffect t = EnemyType::ZOMBIEBITE);
    bool addEffect();
private:
    StatusEffect type;
};
}
#endif