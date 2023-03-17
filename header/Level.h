#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED
#include "../header/Room.h"
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Level {
private:
    vector<vector<Room*>> roomVector;

    int difficulty;
    vector<int> mapSize;

public:

    vector<vector<bool>> exploredRooms;

    Level(int difficulty, vector<vector<Room*>> roomVector);
    int getDifficulty();
    Room* getRoomAt(int, int);
    bool isThereRoom(int, int);
    string generateMap(int, int);
    void setRoom(int, int, Room*);
};
#endif