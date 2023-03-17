#ifndef STORY_H
#define STORY_H 

#include <string>
#include <vector>

#include "./Level.h"
#include "./Player.h"
#include "./StoryIO.h"
#include "./Room.h"

class Story{
    private:
        Level* level;
        std::string storyName;
        Player* player;
        StoryIO io;
        void StartGameMenu(StoryIO);
        void Menu();
        void OptionsMenu(StoryIO);
        void DifficultyMenu(StoryIO);
        void playerCreation(StoryIO);
        void gameCycle();
        
    public:
        void setPlayer(Player*);
        void start();
        void attackLoop(Enemy*);
        std::vector<std::vector<Room*>> getRoomsAdjacentToPlayer();

        Story(std::string storyName, Level* level, StoryIO io);
}
#endif