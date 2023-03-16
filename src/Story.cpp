<<<<<<< HEAD
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "../header/Level.h"
#include "../header/Player.h"
#include "../header/StoryIO.h"
#include "../header/Story.h"
#include "../header/Room.h"

void Story::setPlayer(Player* player){
    this->player = player;
}
Story::Story(std::string storyName, Level* level, StoryIO io){
    this->storyName = storyName;
    this->level = level;
    this->io = io;
}

void Story::Menu() {
    std::ostringstream ostr;
    std::istringstream istr;
    StoryIO io(istr, ostr);
    StartGameMenu(io);
}

void Story::StartGameMenu(StoryIO io) {
    io << "Mystery Menagerie" << io.endl;
    io << "1. New game" << io.endl;
    io << "2. Load game" << io.endl;
    io << "3. Options" << io.endl;

    int input = io.getDigit(3);

    if (input == 1) {
        //It would call a function to start a new game
    }

    if (input == 2) {
        //It would call a function that loads in a game from a previous save (saving this for the end because we might not implement it)
    }

    if (input == 3) {
        OptionsMenu(io);
    }
}

void Story::OptionsMenu(StoryIO io) {
    io << "Options: " << io.endl;
    io << "1. Change difficulty" << io.endl;
    io << "2. Instructions" << io.endl;
    io << "3. Back" << io.endl;

    int input = io.getDigit(3);

    if (input == 1) {
        DifficultyMenu(io);
    }

    if (input == 2) {
        //This should display the instructions to the game
    }

    if (input == 3) {
        StartGameMenu(io);
        //This will bring players back to the start menu
    }
}

void Story::DifficultyMenu(StoryIO io) {
    io << "Change Difficulty" << io.endl;
    io << "1. Easy mode" << io.endl;
    io << "2. Normal mode" << io.endl;
    io << "3. Hard mode" << io.endl;
    io << "4. Back" << io.endl;

    int input = io.getDigit(4);

    if (input == 1) {
        //calls function to change difficulty accordingly
    }

    if (input == 2) {
        //calls function to change difficulty accordingly
    }

    if (input == 3) {
        //calls function to change difficulty accordingly
    }

    if (input == 4) {
        OptionsMenu(io);
        //This will bring the player back to the options menu
    }
}

std::vector<std::vector<Room*>> Story::getRoomsAdjacentToPlayer() {
    std::vector<Room*> adjacentRooms;
    std::vector<Room*> connectedRooms = currentRoom->getConnectRooms();
    int numConnectedRooms = connectedRooms.size();
    for (int i = 0; i < numConnectedRooms; i++) {
        Room* connectedRooms = connectedRooms[i];
        if (connectedRooms != nullptr) {
            adjacentRooms.push_back(connectedRooms);
        }
    }
    return adjacentRooms;
}