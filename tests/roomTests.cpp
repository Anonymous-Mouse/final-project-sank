#include "gtest/gtest.h"
#include "../header/Room.h"
#include "../header/lockedRoom.h"
#include "../header/Enemy.h"
#include "../header/Container.h"
#include <iostream>


TEST(RoomConstructors, onlyName){
    ASSERT_NO_THROW(Room("Room1"));
}

TEST(RoomConstructors, nameAndEnemy){
    Enemy* enemy = new Enemy(std::string("test"),0,0,0,0);
    EXPECT_NO_THROW(Room("Room1", enemy));
}

TEST(RoomConstructors, nameAndEnemyAndEnemySpawnChance){
    Enemy* enemy = new Enemy(std::string("test"),0,0,0,0);
    EXPECT_NO_THROW(Room("Room1", enemy, 21));
}

TEST(RoomConstructors, nameAndEnemyAndEnemySpawnChanceAndContainer){
    Enemy* enemy = new Enemy(std::string("test"),0,0,0,0);
    Container* container = new Container;
    EXPECT_NO_THROW(Room("Room1", enemy, 21, container));
}

TEST(RoomConstructors, onlyContainer){
    Container* container = new Container;
    EXPECT_NO_THROW(Room("Room1", nullptr, 0, container));
}

TEST(RoomGetters, getName){
    Room room("Room1");
    EXPECT_EQ(room.getName(), "Room1");
}

TEST(RoomGetters, getChest){
    Container* container = new Container;
    Room room("Room1", nullptr, 0, container);
    EXPECT_EQ(&(room.getChest()), container);
}

TEST(RoomGetters, getEnemy){
    Enemy* enemy = new Enemy(std::string("test"),0,0,0,0);
    Room room("Room1", enemy);
    EXPECT_EQ(&(room.getEnemy()), enemy);
}

TEST(rollEnemySpawn, rollEnemySpawn0Chance){
    Enemy* enemy = new Enemy(std::string("test"),0,0,0,0);
    Room room("Room1", enemy, 0);
    EXPECT_FALSE(room.rollEnemySpawn());
}

TEST(rollEnemySpawn, rollEnemySpawn100Chance){
    Enemy* enemy = new Enemy(std::string("test"),0,0,0,0);
    Room room("Room1", enemy, 100);
    EXPECT_TRUE(room.rollEnemySpawn());
}

TEST(rollEnemySpawn, rollEnemyNoEnemy){
    Room room("Room1", nullptr, 100);
    EXPECT_FALSE(room.rollEnemySpawn());
}

TEST(RoomCheckers, isThereEnemyTrue){
    Enemy* enemy = new Enemy(std::string("test"),0,0,0,0);
    Room room("Room1", enemy, 100);
    room.rollEnemySpawn();
    EXPECT_TRUE(room.isThereEnemy());
}

TEST(RoomCheckers, isThereEnemyFalse){
    Room room("Room1", nullptr, 0);
    room.rollEnemySpawn();
    EXPECT_FALSE(room.isThereEnemy());
}


TEST(RoomCheckers, isThereChestFalse){
    Room room("Room1", nullptr, 0, nullptr);
    EXPECT_FALSE(room.isThereChest());
}

TEST(RoomCheckers, isThereChestTrue){
    Container* container = new Container;
    Room room("Room1", nullptr, 0, container);
    EXPECT_TRUE(room.isThereChest());
}