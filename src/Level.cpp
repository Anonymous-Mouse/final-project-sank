#include "../header/Level.h"
#include "../header/Room.h"
#include "..header/Container.h"
#include "../header/Enemy.h"
#include <string>
#include <iostream>

using namespace std;

Level::Level(int difficulty, Rooms Room[][], Room exploredRooms[][]) {
    this->difficulty = difficulty;
    this->Room = Room;
    this->exploredRooms = exploredRooms;
    this->mapSize[0] = sizeof(Room) / sizeof(Room[0]);
    this->mapSize[1] = sizeof(Room[0]) / sizeof(Room[0][0]);
}

Level::Level(int difficulty, Rooms Room[][]) {
    this->difficulty = difficulty;
    this->Room = Room;
    this->exploredRooms = new Rooom*[mapSize[0]];
    for(int i = 0; i < mapSize[0]; i++) {
        this->exploredRooms[i] = new Room[mapSize[1]];
    }
}

int Level::getDifficulty() {
    return this->difficulty;
}

Room Level::getRoomAt(int x, int y) {
    if (isThereRoom(x, y)) {
        this->exploredRooms[x][y] = this->Room[x][y];
        return this->Room[x][y];
    }
    else {
        cout << "Invalid coordinates: (" << x << ", " << y << ")" << endl;
        return NULL;
    }
}

bool Level::isThereRoom(int x, int y) {
    if (x >= 0 && x < mapSize[0] && y >= 0 && y < mapSize[1]) {
        return true;
    }
    else {
        return false;
    }
}

string Level::generateMap(int playerX, int playerY) {
    string map = "";
    for (int i = 0; i < mapSize[0]; i++) {
        for (int j = 0; j < mapSize[1]; j++) {
            if (i == playerX && j = playerY) {
                map += "P ";
            }
            else if (isThereRoom(i, j)) {
                if (this->exploredRooms[i][j].getName()) {
                    map += "X ";
                }
                else {
                    map += "- "
                }
                else {
                    map += " ";
                }
            }
        }
        map += "\n";
    }
    return map;
}

void Level::setRoom(int x, int y, Room room) {
    if(isThereRoom(x, y)) {
        this->Room[x][y] = room;
    }
    else {
        cout << "Invalid coordinates: (" << x << ", " << u << ")" << endl;
    }
}