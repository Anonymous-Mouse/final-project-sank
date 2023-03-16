#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "../header/Level.h"
//#include "../header/Player.h"
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

void::Story::attackLoop(Enemy* enemy, Room* room, StoryIO, io){
    io << "------------------------------------------" << io.endl;
    io << "You've encountered an enemy!" << io.endl;
    io << "It hisses at you...and its eyes ready to attack!" << io.endl;

    int input = io.getDigit(1);
    do{
        io << "What is your next choice?" << io.endl;
        io << "1. Attack" << io.endl;
        io << "2. Run Away" << io.endl;
        io << "3. Use your Consumables" << io.endl;
        if(input == 1){ //attack

            player->damageEntity(enemy);
            enemy->damageEntity(player);

            if(enemy->getHealth() <= 0){
                io << "You killed the enemy with " << (player->getWeapon())->getDamage() << " damage points." << io.endl;
                io << "You smile in victory." << io.endl;
            }else if (enemy->getHealth() >= 0){
                io << "Using your equipped weapon, you did " << (player->getWeapon())->getDamage() << " damage to the enemy!" << io.endl;
                io << "The enemy has " << enemy->getHealth() << " health points left." << io.endl;
                io << "The enemy damaged you for " << enemy->getbaseDamage() << " points." << io.endl;
                io << "You have " << player->getHealth() << " health points left." << io.endl;
            }else if(player->getHealth() <= 0){
                io << "The enemy has killed you with " << enemy->getbaseDamage() << " damage points." << io.endl;
                io << "You perish. Your adventure is done." << io.endl;
                return;
            }

        }
        else if(input == 2){ //run away
            bool escapeAttempt = (rand() % 100) <= enemy->getEscapeChance();
            if(escapeAttempt == true){
                io << "You successfully escaped the monster!" << io.endl;
                player->movePlayer(); //Move player into the previous room
                return;
            }
            else{
                io << "You did failed your escape attempt..." io.endl;
            }
        }else if(input == 3){//use consumable
            //use(player)
            //unsure how to implement player use consumable functionality :(

        }else{// invalid input
        io << "Invalid input!" << io.endl;
            continue;
        }

    io << "Exiting attack sequence..." << io.endl;
    }while(enemy->getHealth() > 0 && player->getHealth() > 0);
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