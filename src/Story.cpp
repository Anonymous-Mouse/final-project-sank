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

void Story::start(){
    this->StartGameMenu(this->io)
}

void Story::Menu() {
    std::ostringstream ostr;
    std::istringstream istr;
    StoryIO io(istr, ostr);
    StartGameMenu(io);
}

void Story::gameCycle(){
    this->setPlayer(this->playerCreation(this->io));
}

void Story::StartGameMenu(StoryIO io) {
    io << "Mystery Menagerie" << io.endl;
    io << "1. New game" << io.endl;
    io << "2. Load game" << io.endl;
    io << "3. Options" << io.endl;

    int input = io.getDigit(3);

    if (input == 1) {
        this->gameCycle();
    }

    if (input == 2) {
        io << "Not yet implemented" << io.endl;
        this->StartGameMenu(io);
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
        io << "You're investigating a monster infested Asylum, but you may've bitten off more than you can chew... \n\
        Navigate the Asylum and defeat monsters to find out what happened and escape!'"
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
        this->level->setDifficulty(1);
    }

    if (input == 2) {
        this->level->setDifficulty(2);
    }

    if (input == 3) {
        this->level->setDifficulty(3);
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

Player* Story::playerCreation(StoryIO io) {
    io << "What is your name?" << io.endl;

    string name = io.getString();

    io << "Choose your player type:" << io.endl;
    io << "1. Officer" << io.endl;
    io << "2. Scavenger" << io.endl;
    io << "3. EMT" << io.endl;

    int input = io.getDigit(3);

    if (input == 1) { //creates a Player object named Officer
        Weapon* gun = new Weapon("Gun",35,30);
        vector<Item*> contents = {gun};
        Container* newContainer = new Container(contents, "Inventory", 4);
        Player* Officer = new Player(name, 100, 25, newContainer);
        return Officer;
    }else if (input == 2) { //creates a Player objcet named Scavenger
        Weapon* crowbar = new Weapon("Crowbar",25,15);
        vector<Item*> contents = {crowbar};
        Container* newContainer = new Container(contents, "Inventory", 6);
        Player* Scavenger = new Player(name, 100, 20, newContainer);
        return Scavenger;
    }else if (input == 3) { //creates a Plaer object named EMT
        Consumable* medkit = new Consumable("Medkit", Heal, self);
        vector<Item*> contents = {medkit};
        Container* newContainer = new Container(contents, "Inventory", 5);
        Player* EMT = new Player(name, 100, 15, newContainer);
        return EMT;
    }
}