#include "../header/Level.h"
#include "../header/Room.h"
#include <cassert>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

Level::Level(int difficulty, vector<vector<Room*>> roomVector, vector<int> startRoom) {
    this->difficulty = difficulty;
    this->roomVector = roomVector;
    this->exploredRooms.resize(roomVector.size());
    for (int i = 0; i < roomVector.size(); i++) {
        this->exploredRooms[i].resize(roomVector[i].size());
    }
    this->mapSize.push_back(roomVector.size());
    this->mapSize.push_back(roomVector[0].size());
    this->startRoom = startRoom;
}

vector<int> Level::getStartRoom(){
    return this->startRoom;
}

int Level::getDifficulty() {
    return this->difficulty;
}

void Level::setDifficulty(int difficulty){
    this->difficulty = difficulty; 
}

Room* Level::getRoomAt(int x, int y) {
    assert(isThereRoom(x, y) && "Invalid coordinates");
    return this->roomVector[x][y];
}

bool Level::isRoomExplored(int x, int y){
    assert(isThereRoom(x, y) && "Invalid coordinates");
    if(this->exploredRooms[x][y]){
        return true;
    }else{
        return false;
    }
}

void Level::markRoomExplored(int x, int y){
    assert(isThereRoom(x, y) && "Invalid coordinates");
    this->exploredRooms[x][y] = true;
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
            if (i == playerX && j == playerY) {
                map += "P ";
            }
            else if (isThereRoom(i, j)) {
                if (this->exploredRooms[i][j]) {
                    map += "X ";
                }
                else {
                    map += "- ";
                }
            }
            else {
                map += "  ";
            }
        }
        map += "\n";
    }
    return map;
}

void Level::setRoom(int x, int y, Room* room) {
    if(x < roomVector.size() && y < roomVector[x].size()) {
        this->roomVector[x][y] = room;
    }
    else {
        assert(false && "Invalid coordinates");
    }
}

Level::~Level(){
    for(int i = 0; i<this->roomVector.size(); ++i){
         for(int j = 0; j<this->roomVector.at(i).size(); ++j){
            if(roomVector.at(i).at(j) != nullptr){
                delete roomVector.at(i).at(j);
            }
         }
    }
}