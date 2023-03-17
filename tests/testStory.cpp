#include "gtest/gtest.h"
#include "../header/Story.h"
#include "../header/StoryIO.h"
#include "../header/Entity.h"
#include "../header/Container.h"
#include "../header/StatusEffect.h"
#include "../header/Weapon.h"
#include "../header/Item.h"
#include "../header/Consumable.h"
#include <iostream>

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
