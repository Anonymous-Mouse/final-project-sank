#include <iostream>
#include <string>
#include <sstream>
#include "../header/Story.h"
#include "../header/StoryIO.h"
#include "../header/Player.h"
//#include "../header/Weapon.h"
//#include "../header/Container.h"
#include <vector>

void Story::Menu() {
    std::ostringstream ostr;
    std::istringstream istr;
    StoryIO io(istr, ostr);
}

void Story::playerCreation(StoryIO io) {
    io << "What is your name?" << io.endl;

    string name = io.getString();

    io << "Choose your player type:" << io.endl;
    io << "1. Officer" << io.endl;
    io << "2. Scavenger" << io.endl;
    io << "3. EMT" << io.endl;

    int input = io.getDigit(3);

    if (input == 1) { //creates a Player object named Officer
        Weapon* gun = new Weapon("gun",35,30);
        vector<Item*> contents = {gun};
        Container* newContainer = new Container(contents, "Inventory", 4, "123");
        Player* Officer = new Player(name, 100, 25, newContainer);
    }

    if (input == 2) { //creates a Player objcet named Scavenger
        Weapon* crowbar = new Weapon("crowbar",25,15);
        vector<Item*> contents = {crowbar};
        Container* newContainer = new Container(contents, "Inventory", 6, "123");
        Player* Scavenger = new Player(name, 100, 20, newContainer);
    }

    if (input == 3) { //creates a Plaer object named EMT
        Consumable* medkit = new Consumable("medkit", Heal, self);
        vector<Item*> contents = {medkit};
        Container* newContainer = new Container(contents, "Inventory", 5, "123");
        Player* EMT = new Player(name, 100, 15, newContainer);
    }
}