
#include "../header/Entity.h"

Entity::~Entity() {

}

string Entity::getName(){
    return this->Name;
}

int Entity::getHealth(){
    return this->Health;
}

bool Entity::isDead(){
    return this->DeadState;
}

void Entity::setHealth(int hp){
    this->Health = hp;
       if(getHealth() <= 0){
        this->DeadState = true;
        this->Health = 0;
    }
}

vector<StatusEffect> Entity::getEffects(){
    return this->Effects;
}
