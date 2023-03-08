#include "gtest/gtest.h"
#include "../header/Story.h"
#include "../header/StoryIO.h"
#include <iostream>



TEST(Output, StartMenu) {
    std::ostringstream ostr;
    std::istringstream istr;
    StoryIO io(istr, ostr);
    void StartGameMenu(StoryIO io);
    EXPECT_EQ(ostr.str(), "Mystery Menagerie\n1. New game\n2. Load game\n3. Options\n");
}

// TEST(Input, StartMenu) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     StartGameMenu(StoryIO io);
//     EXPECT_EQ(istr.str(), )
// }

TEST(Output, OptionsMenu) {
    std::ostringstream ostr;
    std::istringstream istr;
    StoryIO io(istr, ostr);
    void OptionsMenu(StoryIO io);
    EXPECT_EQ(ostr.str(), "Options: \n1. Change difficulty\n2. Instructions\n3. Back\n");
}

// TEST(Input, OptionsMenu) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     OptionsMenu(StoryIO io);
//     EXPECT_EQ(istr.str(), )
// }

TEST(Output, DifficultyMenu) {
    std::ostringstream ostr;
    std::istringstream istr;
    StoryIO io(istr, ostr);
    void DifficultyMenu(StoryIO io);
    EXPECT_EQ(ostr.str(), "Change Difficulty\n1. Easy mode\n2. Normal mode\n3. Hard mode\n4. Back\n");
}

// TEST(Input, DifficultyMenu) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     DifficultyMenu(StoryIO io);
//     EXPECT_EQ(istr.str(), )
// }

// TEST(InputFunc, menus) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     int input = io.getDigit(4);
//     EXPECT_EQ(input, 1);
//     //The input should be 1 which is in the range assigned to getDigit().
// }

// TEST(InputFunc, menus) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     int input = io.getDigit(4);
//     EXPECT_EQ(input, 2);
//     //The input should be 2 which is in the range assigned to getDigit().
// }

// TEST(InputFunc, menus) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     int input = io.getDigit(4);
//     EXPECT_EQ(input, 3);
//     //The input should be 3 which is in the range assigned to getDigit().
// }

// TEST(InputFunc, menus) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     int input = io.getDigit(4);
//     EXPECT_EQ(input, 4);
//     //The input should be 4 which is equal to the max assigned to getDigit().
// }

// TEST(InputFunc, menus) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     int input = io.getDigit(4);
//     EXPECT_FALSE(input, -1);
//     //The input shouldn't be a negative value.
// }

// TEST(InputFunc, menus) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     int input = io.getDigit(4);
//     EXPECT_NE(input, -1);
//     //The input shouldn't be a negative value.
// }

// TEST(InputFunc, menus) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     int input = io.getDigit(4);
//     EXPECT_FALSE(input, 6);
//     //The input should not be greater than the max value assigned to getDigit().
// }

// TEST(InputFunc, menus) {
//     std::ostringstream ostr;
//     std::istringstream istr;
//     StoryIO io(istr, ostr);
//     int input = io.getDigit(4);
//     EXPECT_NE(input, 6);
//     //The input should not be greater than the max value assigned to getDigit().
// }