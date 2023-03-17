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
    vector<int> startRoom;

public:

    vector<vector<bool>> exploredRooms;

    Level(int difficulty, vector<vector<Room*>> roomVector, vector<int> startRoom = {0,0});
    int getDifficulty();
    void setDifficulty(int);
    Room* getRoomAt(int, int);
    bool isThereRoom(int, int);
    string generateMap(int, int);
    void setRoom(int, int, Room*);
    vector<int> getStartRoom();
    bool isRoomExplored(int x, int y);
    void markRoomExplored(int x, int y);

    ~Level();
};
#endif