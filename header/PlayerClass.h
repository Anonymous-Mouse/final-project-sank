#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <string>

using namespace std;

class Player {
    private:
        string PlayerName;
        string PlayerType;
        int PlayerHealth;
        int PlayerAttack;

    public:
        Player(const string, const string, int, int); //Creates an object of player with a name, type, health, and attack

};

void PlayerCreation(string, int); //Creates a player using the name and type given

#endif