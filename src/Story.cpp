#include <string>
#include <vector>

#include "../header/Level.h"
#include "../header/Player.h"
#include "../header/StoryIO.h"
#include "../header/Room.h"

void Story::setPlayer(Player* player){
    this->player = player;
}
Story::Story(std::string storyName, Level* level, StoryIO io){
    this->storyName = storyName;
    this->level = level;
    this->io = io;
}

