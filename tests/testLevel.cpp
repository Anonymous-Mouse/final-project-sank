#include "gtest/gtest.h"
#include "../header/Level.h"
#include "../header/Room.h"
#include "../header/Container.h"
#include <vector>

using namespace std;

vector<vector<Room*>> roomVector {
    {new Room("testRoom"), nullptr, new Room("testRoom")},
    {new Room("testRoom"), new Room("testRoom"), nullptr},
    {nullptr, new Room("testRoom"), nullptr}
};

TEST(LevelTest, GetDifficulty)
{
    vector<vector<Room*>> roomVector{{}};
    Level level(1, roomVector);
    EXPECT_EQ(level.getDifficulty(), 1);
}

TEST(LevelTest, GetRoomAtValid)
{

    vector<vector<Room*>> roomVector {
        {new Room("testRoom"), nullptr, new Room("testRoom")},
        {new Room("testRoom"), new Room("testRoom"), nullptr},
        {nullptr, new Room("testRoom"), nullptr}
    };
    Level level(1, roomVector);
    Room* room = level.getRoomAt(0, 0);
    EXPECT_NE(room, nullptr);
    EXPECT_EQ(room->getName(), "testRoom");
}

TEST(LevelTest, GetRoomAtInvalid)
{

    vector<vector<Room*>> roomVector {
        {new Room("testRoom"), nullptr, new Room("testRoom")},
        {new Room("testRoom"), new Room("testRoom"), nullptr},
        {nullptr, new Room("testRoom"), nullptr}
    };
    Level level(1, roomVector);

    EXPECT_DEATH(Room* room = level.getRoomAt(-1, 0), "Invalid coordinates"); 

}

TEST(LevelTest, IsThereRoomValidInvalid)
{

    vector<vector<Room*>> roomVector {
        {new Room("testRoom"), nullptr, new Room("testRoom")},
        {new Room("testRoom"), new Room("testRoom"), nullptr},
        {nullptr, new Room("testRoom"), nullptr}
    };
    Level level(1, roomVector);

    EXPECT_TRUE(level.getRoomAt(0, 0));

    EXPECT_TRUE(level.isThereRoom(1, 1));

    EXPECT_FALSE(level.isThereRoom(-1, 0));
    EXPECT_FALSE(level.isThereRoom(0, 3));
}

TEST(LevelTest, GenerateMap)
{

    vector<vector<Room*>> roomVector {
        {new Room("testRoom"), nullptr, new Room("testRoom")},
        {new Room("testRoom"), new Room("testRoom"), nullptr},
        {nullptr, new Room("testRoom"), nullptr}
    };
    Level level(1, roomVector);

    string expectedMap =
        "-   - \n"
        "- P   \n"
        "  -   \n";
    EXPECT_EQ(level.generateMap(1, 1), expectedMap);
}

TEST(LevelTest, SetRoomValid)
{

    vector<vector<Room*>> roomVector {
        {new Room("testRoom"), nullptr, new Room("testRoom")},
        {new Room("testRoom"), new Room("testRoom"), nullptr},
        {nullptr, new Room("testRoom"), nullptr}
    };
    Level level(1, roomVector);

    Room* newRoom = new Room("new room");
    level.setRoom(1, 2, newRoom);
    EXPECT_EQ(level.getRoomAt(1, 2), newRoom);
}

TEST(LevelTest, SetRoomInvalid)
{

    vector<vector<Room*>> roomVector {
        {new Room("testRoom"), nullptr, new Room("testRoom")},
        {new Room("testRoom"), new Room("testRoom"), nullptr},
        {nullptr, new Room("testRoom"), nullptr}
    };
    Level level(1, roomVector);

    Room *newRoom = new Room("new room");
    EXPECT_DEATH(level.setRoom(3, 0, newRoom), "Invalid coordinates");
}
