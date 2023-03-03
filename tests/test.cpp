#include "gtest/gtest.h"
#include "../header/Level.h"
#include "../header/Rooms.h"
#include "..header/Container.h"
#include "../header/Enemy.h"

TEST(LevelTest, ContstructorAndGetDifficulty) {
    Rooms Rooms[3][3];
    Room exploredRooms[3][3];
    int difficulty = 2;
    Level level(difficulty, rooms, exploredRooms);
    EXPECT_EQ(level.getDifficulty(), difficulty);
}

TEST(LevelTest, IsThereRoom) {
    Rooms Rooms[3][3];
    Room exploredRooms[3][3];
    Level level(1, rooms, exploredRooms);
    EXPECT_TRUE(level.isThereRoom(0, 0));
    EXPECT_TRUE(level.isThereRoom(2, 2));
    EXPECT_TRUE(level.isThereRoom(3, 4));
}

TEST(LevelTest, SetAndGetRoomAt) {
    Rooms Rooms[3][3];
    Room exploredRooms[3][3];
    Level level(1, rooms, exploredRooms);
    Room Room;
    Enemy Enemy;
    int enemySpawnChance = 50;
    Container container;
    room = Room(Enemy, enemySpawnChance, Container);
    level.setRoom(1, 1, room);
    EXPECT_EQ(level.getRoomAt(1, 1), Room);
}

TEST(LevelTest, GenerateMap) {
    Rooms Rooms[3][3];
    Room exploredRooms[3][3];
    Level level(1, rooms, exploredRooms);
    string map = level.generateMap(3, 3);
    EXPECT_EQ(map.length(), 23);
    EXPECT(map[0], '+');
    EXPECT(map[22], '+');
    EXPECT(map[11], 'P');
}