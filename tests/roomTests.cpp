#include "gtest/gtest.h"
#include "../header/Room.h"
#include "../header/lockedRoom.h"
#include "../header/Enemy.h"
#include "../header/Container.h"
#include "../header/Item.h"
#include <vector>
#include <iostream>


std::vector<Item> fakeItems;
class stubContainer: public Container{
    public:
    stubContainer(): Container(fakeItems, std::string("test"), 0){};
};

std::string fakeName("test");
class stubEnemy: public Enemy{
    public:
    stubEnemy(): Enemy(fakeName,0,0,0,0){};
};

TEST(RoomConstructors, onlyName){
    ASSERT_NO_THROW(Room("Room1"));
}

TEST(RoomConstructors, nameAndEnemy){
    Enemy* enemy = new stubEnemy;
    EXPECT_NO_THROW(Room("Room1", enemy));
}

TEST(RoomConstructors, nameAndEnemyAndEnemySpawnChance){
    Enemy* enemy = new stubEnemy;
    EXPECT_NO_THROW(Room("Room1", enemy, 21));
}

TEST(RoomConstructors, nameAndEnemyAndEnemySpawnChanceAndContainer){
    Enemy* enemy = new stubEnemy;
    Container* container = new stubContainer;
    EXPECT_NO_THROW(Room("Room1", enemy, 21, container));
}

TEST(RoomConstructors, onlyContainer){
    Container* container = new stubContainer;
    EXPECT_NO_THROW(Room("Room1", nullptr, 0, container));
}

TEST(RoomContstructors, bareRoom){
     ASSERT_NO_THROW(Room room("Room1", nullptr, 0, nullptr));
}

TEST(RoomGetters, getName){
    Room room("Room1");
    EXPECT_EQ(room.getName(), "Room1");
}

TEST(RoomGetters, getChest){
    Container* container = new stubContainer();
    Room room("Room1", nullptr, 0, container);
    EXPECT_EQ(&(room.getChest()), container);
}

TEST(RoomGetters, getEnemy){
    Enemy* enemy = new stubEnemy;
    Room room("Room1", enemy);
    EXPECT_EQ(&(room.getEnemy()), enemy);
}

TEST(rollEnemySpawn, rollEnemySpawn0Chance){
    Enemy* enemy = new stubEnemy;
    Room room("Room1", enemy, 0);
    EXPECT_FALSE(room.rollEnemySpawn());
}

TEST(rollEnemySpawn, rollEnemySpawn100Chance){
    Enemy* enemy = new stubEnemy;
    Room room("Room1", enemy, 100);
    EXPECT_TRUE(room.rollEnemySpawn());
}

TEST(rollEnemySpawn, rollEnemyNoEnemy){
    Room room("Room1", nullptr, 100);
    EXPECT_FALSE(room.rollEnemySpawn());
}

TEST(RoomCheckers, isThereEnemyTrue){
    Enemy* enemy = new stubEnemy;
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
    Container* container = new stubContainer;
    Room room("Room1", nullptr, 0, container);
    EXPECT_TRUE(room.isThereChest());
}

TEST(RoomCheckers, isLocked){
    Room room("Room1", nullptr, 0, nullptr);
    EXPECT_FALSE(room.isLocked());
}

TEST(lockedRoomConstructor, Construct){
    ASSERT_NO_THROW(lockedRoom("testKey", "testName", nullptr, 0, nullptr));
}

TEST(lockedRoomUnlock, UnlockWrongKey){
    lockedRoom room("rightKey", "testName", nullptr, 0, nullptr);
    EXPECT_FALSE(room.unlock("wrongKey"));
}

TEST(lockedRoomUnlock, UnlockRightKey){
    lockedRoom room("rightKey", "testName", nullptr, 0, nullptr);
    EXPECT_TRUE(room.unlock("rightKey"));
}

TEST(lockedRoomCheckers, isLockedWhileLocked){
    lockedRoom room("testKey", "testName", nullptr, 0, nullptr);
    EXPECT_TRUE(room.isLocked());
}

TEST(lockedRoomCheckers, isLockedWhileUnlocked){
    lockedRoom room("rightKey", "testName", nullptr, 0, nullptr);
    EXPECT_TRUE(room.unlock("rightKey"));
    EXPECT_FALSE(room.isLocked());
}

