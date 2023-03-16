#include "../header/Level.h"
#include "../header/Room.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

Level::Level(int difficulty, vector<vector<Room*>> roomVector) {
    this->difficulty = difficulty;
    this->roomVector = roomVector;
    this->exploredRooms.resize(roomVector.size());
    for (int i = 0; i < roomVector.size(); i++) {
        this->exploredRooms[i].resize(roomVector[i].size());
    }
    this->mapSize.push_back(roomVector.size());
    this->mapSize.push_back(roomVector[0].size());
}

int Level::getDifficulty() {
    return this->difficulty;
}

Room* Level::getRoomAt(int x, int y) {
    assert(isThereRoom(x, y) && "Invalid coordinates");

    this->exploredRooms[x][y] = true;
    return this->roomVector[x][y];
}

bool Level::isThereRoom(int x, int y) {
    if (x < roomVector.size() && y < roomVector[x].size() && roomVector[x][y] != nullptr) {
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
                if (this->exploredRooms[i][j]) {
                    map += "X ";
                }
                else {
                    map += "- "
                }
            }
            else {
                map += " ";
            }
        }
        map += "\n";
    }
    return map;
}

void Level::setRoom(int x, int y, Room room) {
    if(x < roomVector.size() && y < roomVector[x].size()) {
        this->rommVector[x][y] = room;
    }
    else {
        assert(false && "Invalid coordinates");
    }
}