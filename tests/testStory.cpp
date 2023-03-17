#include "gtest/gtest.h"
#include "../header/Story.h"
#include "../header/StoryIO.h"
#include <iostream>
#include "../header/Entity.h"
#include "../header/Container.h"
#include "../header/StatusEffect.h"
#include "../header/Weapon.h"
#include "../header/Item.h"
#include "../header/Consumable.h"
#include <iostream>

TEST(MenuOutput, StartMenu) {
    std::ostringstream ostr;
    std::istringstream istr("1");
    StoryIO io(istr, ostr);
    Story story;
    story.StartGameMenu(io);
    EXPECT_EQ(ostr.str(), "Mystery Menagerie\n1. New game\n2. Load game\n3. Options\n");
}

TEST(MenuInput, StartMenu) {
    std::ostringstream ostr;
    std::istringstream istr("3");
    StoryIO io(istr, ostr);
    Story story;
    story.StartGameMenu(io);
    EXPECT_EQ(istr.str(), "3");
}

TEST(MenuOutput, OptionsMenu) {
    std::ostringstream ostr;
    std::istringstream istr("1");
    StoryIO io(istr, ostr);
    Story story;
    story.OptionsMenu(io);
    EXPECT_EQ(ostr.str(), "Options: \n1. Change difficulty\n2. Instructions\n3. Back\n");
}

TEST(MenuInput, OptionsMenu) {
    std::ostringstream ostr;
    std::istringstream istr("2");
    StoryIO io(istr, ostr);
    Story story;
    story.OptionsMenu(io);
    EXPECT_EQ(istr.str(), "2");
}

TEST(MenuOutput, DifficultyMenu) {
    std::ostringstream ostr;
    std::istringstream istr("1");
    StoryIO io(istr, ostr);
    Story story;
    story.DifficultyMenu(io);
    EXPECT_EQ(ostr.str(), "Change Difficulty\n1. Easy mode\n2. Normal mode\n3. Hard mode\n4. Back\n");
}

TEST(MenuInput, DifficultyMenu) {
    std::ostringstream ostr;
    std::istringstream istr("4");
    StoryIO io(istr, ostr);
    Story story;
    story.DifficultyMenu(io);
    EXPECT_EQ(istr.str(), "4");
}

// TEST(, StartMenu) {

// }

// TEST(, OptionsMenu) {

// }

// TEST(, DifficultyMenu) {

// }


TEST(MenuOutput, PlayerCreation) {
    std::ostringstream ostr;
    std::istringstream istr("Nick");
    StoryIO io(istr, ostr);
    io << "What is your name?" << io.endl;
    string name = io.getString();
    EXPECT_EQ(ostr.str(), "What is your name?\n");
}

TEST(MenuOutput, PlayerCreation2) {
    std::ostringstream ostr;
    std::istringstream istr("1");
    StoryIO io(istr, ostr);
    io << "Choose your player type:" << io.endl;
    io << "1. Officer" << io.endl;
    io << "2. Scavenger" << io.endl;
    io << "3. EMT" << io.endl;
    int input = io.getDigit(3);
    EXPECT_EQ(ostr.str(), "Choose your player type:\n1. Officer\n2. Scavenger\n3. EMT\n");
}
