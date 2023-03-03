#include <gtest/gtest.h>
#include "../header/Level.h"
#include "../header/Room.h"
#include "../header/Enemy.h"
#include "../header/Container.h"
#include <iostream>

TEST(LevelTest, ConstructorAndGetDifficulty) {
    Room rooms[3][3];
    Room exploredRooms[3][3];
    int difficulty = 2;
    Level level(difficulty, rooms, exploredRooms);
    EXPECT_EQ(level.getDifficulty(), difficulty);
}

TEST(LevelTest, IsThereRoom) {
    Room rooms[3][3];
    Room exploredRooms[3][3];
    Level level(1, rooms, exploredRooms);
    EXPECT_TRUE(level.isThereRoom(0, 0));
    EXPECT_TRUE(level.isThereRoom(2, 2));
    EXPECT_FALSE(level.isThereRoom(3, 3));
}

TEST(LevelTest, SetAndGetRoomAt) {
    Room rooms[3][3];
    Room exploredRooms[3][3];
    Level level(1, rooms, exploredRooms);
    Room room;
    Enemy enemy;
    int enemySpawnChance = 50;
    Container container;
    room = Room(enemy, enemySpawnChance, container);
    level.setRoom(1, 1, room);
    EXPECT_EQ(level.getRoomAt(1, 1), room);
}

TEST(LevelTest, GenerateMap) {
    Room rooms[3][3];
    Room exploredRooms[3][3];
    Level level(1, rooms, exploredRooms);
    string map = level.generateMap(3, 3);
    EXPECT_EQ(map.length(), 23);
    EXPECT_EQ(map[0], '+');
    EXPECT_EQ(map[22], '+');
    EXPECT_EQ(map[11], 'P');
}
