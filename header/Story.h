#ifndef STORY_H
#define STORY_H
#include "../header/StoryIO.h"

class Story {
    public:
        void StartGameMenu(StoryIO);
        void Menu();
        void OptionsMenu(StoryIO);
        void DifficultyMenu(StoryIO);
        void playerCreation(StoryIO);
        void Menu();
};

#endif