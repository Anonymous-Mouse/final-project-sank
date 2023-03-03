#include "PlayerClass.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(const string name, const string type, int health, int attack) {
    PlayerName = name;
    PlayerType = type;
    PlayerHealth = health;
    PlayerAttack = attack;
}

void PlayerCreation(const string pName, int choice) {
    if (choice == 1) {
        Player* Officer = new Player(pName, "Officer", 100, 20);
    }
    if (choice == 2) {
        Player* Scavenger = new Player(pName, "Scavenger", 100, 15);
    }
    if (choice == 3) {
        Player* EMT = new Player(pName, "EMT", 100, 20);
    }
}