#include "gtest/gtest.h"
#include  "gmock/gmock.h"
#include "../header/spider.h"
#include "../header/zombie.h"
#include "../header/rat.h"

using namespace std;
TEST(EnemyTests, testSpiderConstructor){
    Spider* spider = new Spider("Spider",100,20,2);
    EXPECT_THAT(spider->getName(), "Spider");
    EXPECT_EQ(spider->getHealth(), 100);
    EXPECT_EQ(spider->getBaseDamage(), 20);
    EXPECT_EQ(spider->getDamageSpread(), 2);
} 

TEST(EnemyTests, testZombieConstructor){
    Zombie* zombie = new Zombie("Zombie", 100, 10, 1);
    EXPECT_THAT(zombie->getName(), "Zombie");
    EXPECT_EQ(zombie->getHealth(), 100);
    EXPECT_EQ(zombie->getBaseDamage(), 10);
    EXPECT_EQ(zombie->getDamageSpread(), 1);
}

TEST(EnemyTests, testRatConstructor){
    Rat* rat = new Rat("Rat", 100, 10, 1);
    EXPECT_THAT(rat->getName(), "Rat");
    EXPECT_EQ(rat->getHealth(), 100);
    EXPECT_EQ(rat->getBaseDamage(), 10);
    EXPECT_EQ(rat->getDamageSpread(), 1);
}

TEST(EnemyTests, testSetHealth){
    Spider* spider = new Spider("Spider", 200, 20, 2);
    spider->setHealth(50);
    EXPECT_EQ(spider->getHealth(), 150);
}

TEST(EnemyTests, testCheckIfDead){
    Spider* spider = new Spider("Spider", 200, 20, 2);
    spider->setHealth(200);
    EXPECT_FALSE(spider->checkIfDead());
}

TEST(EnemyTests, testEscapeChance){
    Spider* spider = new Spider("Spider", 200, 20, 20);
    EXPECT_TRUE(spider->getEscapeChance() > 0 && spider->getEscapeChance() < 101);
}