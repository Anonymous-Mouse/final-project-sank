#include "gtest/gtest.h"
#include "../header/Level.h"
#include "../header/Room.h"
#include "../header/Container.h"
#include <vector>

using namespace std;

class MockLevelTest : public testing::Test {
protected:
    void SetUp() override {
        vector<vector<Room*>> roomVector {
            {new Room(), nullptr, new Room()},
            {new Room(), new Room(), nullptr},
            {nullptr, new Room(), nullptr}
        };
        level = new Level(1, roomVector);
    }

    void TearDown() override {
        for (auto row : level->roomVector) {
            for (auto room : row) {
                delete room;
            }
        }
        delete level;
    }

    Level* level; 
};

TEST(LevelTest, GetDifficulty) {
    EXPECT_EQ(level->getDifficulty(), 1);
}

TEST(LevelTest, GetRoomAtValid) {
    Room* room = level->getRoomAt(0, 0);
    EXPECT_NE(room, nullptr);
    EXPECT_EQ(room->getName(), "");
    EXPECT_EQ(level->exploredRooms[0][0], true);
}

TEST(LevelTest, GetRoomAtInvalid) {
    Room* rooms = level->getRoomAt(-1, 0);
    EXPECT_EQ(room, nullptr);
    room = level->getRoomAt(0, 3);
    EXPECT_EQ(room, nullptr);
    EXPECT_FALSE(level->getRoomAt[-1][0]);
    EXPECT_FALSE(level->getRoomAt[0][3]);
}

TEST(LevelTest, IsThereRoomValid) {
    EXPECT_TRUE(level->getRoomAt(0, 0));
    EXPECT_TRUE(level->exploredRooms[0][0]);
    EXPECT_TRUE(level->isThereRoom(1, 1));
    EXPECT_TRUE(level->exploredRooms[1][1]);
    EXPECT_FALSE(level->isThereRoom(-1, 0));
    EXPECT_FALSE(level->isThereRoom(0, 3));
}

TEST(LevelTest, GenerateMap) {
    string expectedMap = 
        "P - R \n"
        "- - - \n"
        "R - - \n";
    EXPECT_EQ(level->generateMap(0, 1), expectedMap);
}

TEST(LevelTest, SetRoomValid) {
    Room* newRoom = new Room("new room");
    level->setRoom(1, 2, *newRoom);
    EXPECT_EQ(level->roomVector[1][2], newRoom);
    delete newRoom;
}

TEST(LevelTest, SetRoomInvalid) {
    Room* newRoom = new Room("new room");
    level->setRoom(3, 0, *newRoom);
    EXPECT_EQ(level->roomVector[1][2], nullptr);
    delete newRoom;
}

