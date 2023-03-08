#ifndef STORY_H
#define STORY_H
#include "../header/StoryIO.h"

class Story {
    private:
        void StartGameMenu(StoryIO);
        void Menu();
        void OptionsMenu(StoryIO);
        void DifficultyMenu(StoryIO);
};

#endif