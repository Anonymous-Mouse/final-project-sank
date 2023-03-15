#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/PlayerClass.h"
#include "../header/Container.h"

using namespace std;

TEST(PlayerName, testPlayerConstructor) {
    vector<Item*> contents = {};
    Container* newContainer = new Container(contents, "inv", 5);
    Player* player = new Player("Nick", 100, 25, newContainer);
    EXPECT_THAT(player->getName(), "Nick");
}

TEST(PlayerHealth, testPlayerConstructor) {
    vector<Item*> contents = {};
    Container* newContainer = new Container(contents, "inv", 5);
    Player* player = new Player("Nick", 100, 25, newContainer);
    EXPECT_THAT(player->getHealth(), 100);
}

TEST(PlayerBaseDamage, testPlayerConstructor) {
    vector<Item*> contents = {};
    Container* newContainer = new Container(contents, "inv", 5);
    Player* player = new Player("Nick", 100, 25, newContainer);
    EXPECT_THAT(player->getBaseDamage(), 25);
}

