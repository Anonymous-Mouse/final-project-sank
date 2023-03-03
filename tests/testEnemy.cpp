#include "gtest/gtest.h"
#include  "gmock/gmock.h"
#include "../header/spider.h"
#include "../header/zombie.h"
#include "../header/rat.h"

using namespace std;
TEST(EnemyTests, testSpiderConstructor){
    Spider* spider = new Spider("Spider",100,10,2,2);
    EXPECT_THAT(spider->getName(), "Spider");
    EXPECT_EQ(spider->getHealth(), 110);
    EXPECT_EQ(spider->getBaseDamage(), 20);
    EXPECT_EQ(spider->getDamageSpread(), 2);
} 

TEST(EnemyTests, testZombieConstructor){
    Zombie* zombie = new Zombie("Zombie", 100, 10, 1,1);
    EXPECT_THAT(zombie->getName(), "Zombie");
    EXPECT_EQ(zombie->getHealth(), 105);
    EXPECT_EQ(zombie->getBaseDamage(), 10);
    EXPECT_EQ(zombie->getDamageSpread(), 1);
}

TEST(EnemyTests, testRatConstructor){
    Rat* rat = new Rat("Rat", 100, 10, 1,1);
    EXPECT_THAT(rat->getName(), "Rat");
    EXPECT_EQ(rat->getHealth(), 105);
    EXPECT_EQ(rat->getBaseDamage(), 10);
    EXPECT_EQ(rat->getDamageSpread(), 1);
}


TEST(EnemyTests, testCheckIfDeadTRUE){
    Spider* spider = new Spider("Spider", 200, 20, 2,1);
    spider->setHealth(0);
    EXPECT_TRUE(spider->isDead());
}

TEST(EnemyTests, testCheckIfDeadFALSE){
    Spider* spider = new Spider("Spider", 200, 20, 2,1);
    EXPECT_FALSE(spider->isDead());
}

TEST(EnemyTests, testEscapeChance){
    Spider* spider = new Spider("Spider", 200, 20, 20,1);
    EXPECT_TRUE(spider->getEscapeChance() >= 0 && spider->getEscapeChance() < 101);
}

TEST(EnemyTests, testSetHealth){
    Zombie* zombie = new Zombie("Zombie",100,10,1,1);
    zombie->setHealth(0);
    EXPECT_EQ(zombie->getHealth(), 0);

}
TEST(EnemyTests, testNegativeHealth){
    Rat* rat = new Rat("Rat", 100,10,1,1);
    rat->setHealth(-15);
    EXPECT_EQ(rat->getHealth(), 0);
}

TEST(EnemyTests, testAddEffect){
    Rat* rat = new Rat("Rat", 100,10,1,1);
    EXPECT_TRUE(rat->addEffect(ReduceMaxHealth));
}

TEST(EnemyTests, testAddTwoEffects){
    Rat* rat = new Rat("Rat", 100,10,1,1);
    rat->addEffect(ReduceMaxHealth);
    EXPECT_TRUE(rat->addEffect(Slow));
}

TEST(EnemyTests, testRemoveEffect){
    Rat* rat = new Rat("Rat", 100,10,1,1);
    rat->addEffect(ReduceMaxHealth);
    EXPECT_TRUE(rat->removeEffect(ReduceMaxHealth));
}

