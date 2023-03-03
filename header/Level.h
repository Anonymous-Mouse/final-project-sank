#include "../header/Rooms.h"
#include "..header/Container.h"
#include "../header/Enemy.h"
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

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