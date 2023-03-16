#ifndef STORY_H
#define STORY_H 

#include <string>
#include <vector>

#include "./Level.h"
//#include "./Player.h"
#include "./StoryIO.h"
#include "./Room.h"

using namespace std;

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

    public:
        void setPlayer(Player*);
        void start();
        void attackLoop(Enemy* enemy, Room* room, StoryIO io);
        std::vector<std::vector<Room*>> getRoomsAdjacentToPlayer();

        Story(std::string storyName, Level* level, StoryIO io);

#endif