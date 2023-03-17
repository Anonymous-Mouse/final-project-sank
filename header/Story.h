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
        Player* playerCreation(StoryIO);
        void gameCycle(StoryIO);
        void moveMenu(StoryIO io);
        void inventoryMenu(StoryIO io);
        
    public:
        void setPlayer(Player*);
        void start(StoryIO);
        void attackLoop(StoryIO io,Enemy* enemy, int lastRoomX, int lastRoomY);
       // std::vector<std::vector<Room*>> getRoomsAdjacentToPlayer();

        Story(std::string storyName, Level* level);
        ~Story();
};
#endif