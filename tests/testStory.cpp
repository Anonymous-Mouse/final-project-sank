#include "gtest/gtest.h"
#include "../header/Story.h"
#include "../header/StoryIO.h"
#include <iostream>




TEST(MenuOutput, StartMenu) {
    std::ostringstream ostr;
    std::istringstream istr("1");
    StoryIO io(istr, ostr);
    Story story("Mystery Menagerie", nullptr, io);
    story.StartGameMenu(io);
    EXPECT_EQ(ostr.str(), "Mystery Menagerie\n1. New game\n2. Load game\n3. Options\n");
}

TEST(MenuInput, StartMenu) {
    std::ostringstream ostr;
    std::istringstream istr("3");
    StoryIO io(istr, ostr);
    Story story("Mystery Menagerie", nullptr, io);
    story.StartGameMenu(io);
    EXPECT_EQ(istr.str(), "3");
}

TEST(MenuOutput, OptionsMenu) {
    std::ostringstream ostr;
    std::istringstream istr("1");
    StoryIO io(istr, ostr);
    Story story("Mystery Menagerie", nullptr, io);
    story.OptionsMenu(io);
    EXPECT_EQ(ostr.str(), "Options: \n1. Change difficulty\n2. Instructions\n3. Back\n");
}

TEST(MenuInput, OptionsMenu) {
    std::ostringstream ostr;
    std::istringstream istr("2");
    StoryIO io(istr, ostr);
    Story story("Mystery Menagerie", nullptr, io);
    story.OptionsMenu(io);
    EXPECT_EQ(istr.str(), "2");
}

TEST(MenuOutput, DifficultyMenu) {
    std::ostringstream ostr;
    std::istringstream istr("1");
    StoryIO io(istr, ostr);
    Story story("Mystery Menagerie", nullptr, io);
    story.DifficultyMenu(io);
    EXPECT_EQ(ostr.str(), "Change Difficulty\n1. Easy mode\n2. Normal mode\n3. Hard mode\n4. Back\n");
}

TEST(MenuInput, DifficultyMenu) {
    std::ostringstream ostr;
    std::istringstream istr("4");
    StoryIO io(istr, ostr);
    Story story("Mystery Menagerie", nullptr, io);
    story.DifficultyMenu(io);
    EXPECT_EQ(istr.str(), "4");
}

// TEST(, StartMenu) {

// }

// TEST(, OptionsMenu) {

// }

// TEST(, DifficultyMenu) {

// }
