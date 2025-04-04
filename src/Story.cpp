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

Story::Story(std::string Name, Level* level){
    this->storyName = Name;
    this->level = level;

}

void Story::start(StoryIO io){
    this->StartGameMenu(io);
}

void Story::Menu() {
    std::ostringstream ostr;
    std::istringstream istr;
    StoryIO io(istr, ostr);
    StartGameMenu(io);
}

void Story::gameCycle(StoryIO io){
    bool loopCycle = true;
    do
    {
        int plrX = this->player->getLocationX();
        int plrY = this->player->getLocationY();
        Room plrRoom = *(this->level->getRoomAt(plrX, plrY));
        this->level->markRoomExplored(plrX,plrY);



        io << "Choose an action:" << io.endl;
        io << "1. View the map." << io.endl;
        io << "2. Move to a different room." << io.endl;
        io << "3. Access Inventory." << io.endl;
        io << "4. Back to Main Menu." << io.endl;

        int input = io.getDigit(4);

        if (input == 1)
        {
            io << this->level->generateMap(plrX, plrY) << io.endl;
        }else
        if (input == 2)
        {
            this->moveMenu(io);
            int newPosX = this->player->getLocationX();
            int newPosY = this->player->getLocationY();
            if(!this->level->isRoomExplored(newPosX,newPosY)){
                Room* newRoom = this->level->getRoomAt(newPosX, newPosY);
                //io << "get room" << io.endl;
                if(newRoom->rollEnemySpawn()){
                    //io << "roll spawn" << io.endl;
                    this->attackLoop(io, &(newRoom->getEnemy()),plrX,plrY);
                }
            }

        }else
        if(input == 3 ){
            inventoryMenu(io);
        }else if(input == 4 ){
            return;
        }else{
            io << "Invalid input" << io.endl;
        }

        
    }while(loopCycle == true);
}

void Story::inventoryMenu(StoryIO io){
    do{
    io << "Your inventory: " << player->getInventory()->getContentsAmount() << "/" << player->getInventory()->getMaxItems() << io.endl;
    //io << player->getInventory()->getContentsAmount() << io.endl;
    Weapon* equippedWeapon = this->player->getWeapon();
    for(int i = 0; i<player->getInventory()->getContentsAmount(); ++i){
        Item* item = player->getInventory()->getItemIndex(i);
        io << "[" << i << "] ";
        if(item == equippedWeapon){
            io << "EQUIPPED - ";
        }
        io << item->getDescription();
        io << io.endl;
    }
    io << "1. Equip different weapon" << io.endl;
    //io << "2. Use consumable" << io.endl;
    io << "2. Back" << io.endl;

    int input = io.getDigit(2);

    if(input == 1){
        io << "Enter the index of the weapon you want to equip." << io.endl;
        int weaponIndex = io.getDigit(player->getInventory()->getContentsAmount());
        if(player->getInventory()->getItemIndex(weaponIndex)->getType()==ItemTypes::WEAPON){
            Weapon* wep = dynamic_cast<Weapon*>(player->getInventory()->getItemIndex(weaponIndex));
            player->setWeapon(wep);
        }else{
            io << "Invalid item." << io.endl;
        }
    }else
    if(input ==2){
        break;
    }
    }while (true);
}


void Story::moveMenu(StoryIO io){
    int plrX = this->player->getLocationX();
    int plrY = this->player->getLocationY();
    io << "Where would you like to move?" << io.endl;
    io << this->level->generateMap(plrX,plrY) << io.endl;

    //north
    if(this->level->isThereRoom(plrX-1,plrY)){
        io << "1. North" << io.endl;
    }

    //South
    if(this->level->isThereRoom(plrX+1,plrY)){
        io << "2. South" << io.endl;
    }

    //East
    if(this->level->isThereRoom(plrX,plrY+1)){
        io << "3. East" << io.endl;
    }

    //West
    if(this->level->isThereRoom(plrX,plrY-1)){
        io << "4. West" << io.endl;
    }

    io << "5. Go back" << io.endl;

    int input = io.getDigit(5);

    if(input == 1 && this->level->isThereRoom(plrX-1,plrY)){
        this->player->movePlayer(plrX-1,plrY);
    }else if(input == 2 && this->level->isThereRoom(plrX+1,plrY)){
        this->player->movePlayer(plrX+1,plrY);
    }else if(input == 3 && this->level->isThereRoom(plrX,plrY+1)){
        this->player->movePlayer(plrX,plrY+1);
    }else if(input == 4 && this->level->isThereRoom(plrX,plrY-1)){
        this->player->movePlayer(plrX,plrY-1);
    }else if(input == 5){
        return;
    }else{
        io << "Invalid choice! Try again." << io.endl;
        moveMenu(io);
    }


}

void Story::StartGameMenu(StoryIO io) {
    do{
    io << this->storyName << io.endl;
    io << "1. New game" << io.endl;
    io << "2. Load game" << io.endl;
    io << "3. Options" << io.endl;
    io << "4. Quit" << io.endl;

    int input = io.getDigit(4);

    if (input == 1) {
        Player* plr = this->playerCreation(io);
        Weapon* wep = dynamic_cast<Weapon*>(plr->getInventory()->getItemIndex(0));
        plr->setWeapon(wep);
        int xPos = this->level->getStartRoom().at(0);
        int yPos = this->level->getStartRoom().at(1);
        plr->movePlayer(xPos,yPos);
        this->setPlayer(plr);
        this->gameCycle(io);
    }

    if (input == 2) {
        io << "Not yet implemented" << io.endl << io.endl;
        this->StartGameMenu(io);
        //It would call a function that loads in a game from a previous save (saving this for the end because we might not implement it)
    }

    if (input == 3) {
        OptionsMenu(io);
    }

    if (input == 4) {
        break;
    }

    }while(true);
}

void Story::OptionsMenu(StoryIO io) {
    do{
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
        Navigate the Asylum and defeat monsters to find out what happened and escape!'" << io.endl;
        //this->OptionsMenu(io);
    }

    if (input == 3) {
        break;
        //StartGameMenu(io);
        //This will bring players back to the start menu
    }
    }while(true);
    
}

void Story::DifficultyMenu(StoryIO io) {
    do{
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
        break;
        //OptionsMenu(io);
        //This will bring the player back to the options menu
    }
    }while(true);
}

void Story::attackLoop(StoryIO io ,Enemy* enemy, int lastRoomX, int lastRoomY){
    io << "------------------------------------------" << io.endl;
    io << "You've encountered an enemy!" << io.endl;
    io << "It's a "<<enemy->getName()<<"!" << io.endl;

    
    do{
        io << "What is your next choice?" << io.endl;
        io << "1. Attack" << io.endl;
        io << "2. Run Away" << io.endl;
        //io << "3. Use your Consumables" << io.endl;
        int input = io.getDigit(2);
        if(input == 1){ //attack

            player->damageEntity(enemy);
            enemy->damageEntity(player);

            if(enemy->getHealth() <= 0){
                io << "You killed the enemy with " << (player->getWeapon())->getDamage() << " damage points." << io.endl;
                io << "You smile in victory." << io.endl;
            }else if (enemy->getHealth() >= 0){
                io << "Using your equipped weapon, you did " << (player->getWeapon())->getDamage() << " damage to the "<<enemy->getName()<<"!" << io.endl;
                io << "The enemy has " << enemy->getHealth() << " health points left." << io.endl;
                io << "The enemy damaged you for " << enemy->getBaseDamage() << " points." << io.endl;
                io << "You have " << player->getHealth() << " health points left." << io.endl;
            }else if(player->getHealth() <= 0){
                io << "The enemy has killed you with " << enemy->getBaseDamage() << " damage points." << io.endl;
                io << "You perish. Your adventure is done." << io.endl;
                return;
            }

        }
        else if(input == 2){ //run away
            bool escapeAttempt = (rand() % 100) <= enemy->getEscapeChance();
            if(escapeAttempt == true){
                io << "You successfully escaped the monster!" << io.endl;
                player->movePlayer(lastRoomX, lastRoomY); //Move player into the previous room
                return;
            }
            else{
                io << "You failed your escape attempt..." << io.endl;
            }
        }else if(input == 3){//use consumable
            //use(player)
            //unsure how to implement player use consumable functionality :(

        }

    //io << "Exiting attack sequence..." << io.endl;
    }while(enemy->getHealth() > 0 && player->getHealth() > 0);
}

/*std::vector<std::vector<Room*>> Story::getRoomsAdjacentToPlayer() {
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
}*/

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
        Consumable* medkit = new Consumable("Medkit", Heal, UsageType::self);
        Weapon* scalpel = new Weapon("Scalpel", 15, 14);
        vector<Item*> contents = {scalpel, medkit};
        Container* newContainer = new Container(contents, "Inventory", 5);
        Player* EMT = new Player(name, 100, 15, newContainer);
        return EMT;
    }
}

Story::~Story(){
    if(this->player != nullptr){
        delete this->player;
    }
    if(this->level != nullptr){
        delete this->level;
    }
}