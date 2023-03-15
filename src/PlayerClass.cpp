#include "../header/PlayerClass.h"

// Player::~Player() {} //destructs player

int Player::getBaseDamage() {
    return this->BaseDamage;
}

// void Player::damageEntity(Enemy* enemyTarget) {
//     enemyTarget->setHealth(enemyTarget->getHealth() - BaseDamage);
//     vector<StatusEffect> temp = getEffects();
//     for(vector<StatusEffect>::iterator it = Effects.begin(); it != Effects.end(); ++it){
//         enemyTarget->addEffect(*it);
//     }
// }

// bool Player::addEffect(StatusEffect effect) {
//     if(this->Effects.empty()){
//         this->Effects.push_back(effect);
//         return true;
//     }
//     else{
//         bool foundElement = false;
//         for(vector<StatusEffect>::iterator it = Effects.begin(); it != Effects.end(); ++it) {
//              if(*it == effect){
//                 foundElement = true;
//                 break;
//              }
//         }
//         if(foundElement == true){
//             //do nothing, element already exists in container
//             return false;
//         }
//         else{
//             this->Effects.push_back(effect);
//             return true;
//         }
//     }
// }

// bool Player::removeEffect(StatusEffect effect) {
//     if(this->Effects.empty()){
//         return true;
//     }
//     else{
//         auto it = find(Effects.begin(), Effects.end(), effect);
//         if(it != Effects.end()){
//             this->Effects.erase(it);
//         }
//         auto doubleCheck = find(Effects.begin(), Effects.end(), effect);
//         if(doubleCheck != Effects.end()){
//             return false;
//         }
//         else{
//             return true;
//         }
//     }
// }

// Weapon* Player::getWeapon() { //add weapon to the contents vector
//     if ()
// }

// void Player::setWeapon(Weapon*) {

// }

