#include "Level.h"
#include "Room.h"
#include <string>
#include <array>

using namespace std;

Level::Level(int difficulty, Rooms Room[][], Room exploredRooms[][]);
Level::Level(int difficulty, Rooms Room[][]);
int Level::getDifficulty();
Room Level::getRoomAt(int, int);
bool Level::isThereRoom(int, int);
string Level::generateMap(int, int);
void Level::setRoom(int, int, Room);