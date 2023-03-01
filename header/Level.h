#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Rooms.h"
#include <string>
#include <array>

using namespace std;

class Level {
private:
    Rooms Room[][];
    exploredRooms[][];
    int difficulty;
    int mapSize[];

public:
    Level(int difficulty, Rooms Room[][], Room exploredRooms[][]);
    Level(int difficulty, Rooms Room[][]);
    int getDifficulty();
    Room getRoomAt(int, int);
    bool isThereRoom(int, int);
    string generateMap(int, int);
    void setRoom(int, int, Room);
};
#endif