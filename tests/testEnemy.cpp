#include "gtest/gtest.h"
#include  "gmock/gmock.h"
#include "../header/PlayerClass.h"
#include "../header/StatusEffect.h"
#include "../header/Spider.h"
#include "../header/Zombie.h"
#include "../header/Rat.h"

using namespace std;

class MockPlayer: public Entity{
    public:
    MockPlayer(string Name, int Health) : Entity(Name, Health){

    };
    ~MockPlayer(){};
    bool addEffect(StatusEffect effect) override{
        this->Effects.push_back(effect);
        return true;
    }
    bool removeEffect(StatusEffect effect) override{
         if(this->Effects.empty()){
            return true;
        }else{
            auto it = find(Effects.begin(), Effects.end(), effect);
            if(it != Effects.end()){
                this->Effects.erase(it);
            }
            auto doubleCheck = find(Effects.begin(), Effects.end(), effect);
            if(doubleCheck != Effects.end()){
                return false;
            }
            else{
                return true;
            }
        }
    }


};

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
    Spider* spider = new Spider("Spider", 100,10,1,1);
    spider->addEffect(ReduceMaxHealth);
    EXPECT_TRUE(spider->addEffect(Slow));
}

TEST(EnemyTests, testRemoveEffect){
    Zombie* zombie = new Zombie("Zombie", 100,10,1,1);
    zombie->addEffect(ReduceMaxHealth);
    EXPECT_TRUE(zombie->removeEffect(ReduceMaxHealth));
}

TEST(EnemyTests, testDamageEntity){
    Spider* spider = new Spider("Spider", 200,20,1,1);
    MockPlayer* mockplayer = new MockPlayer("Officer", 100);
    spider->addEffect(ReduceMaxHealth);
    spider->damageEntity(mockplayer);
    EXPECT_EQ(mockplayer->getHealth(), 80);
    
    vector<StatusEffect> v = mockplayer->getEffects();
    EXPECT_EQ(v.size(), 1);
    EXPECT_THAT(v[0], ReduceMaxHealth);
}

TEST(EnemyTests, testMultipleEffects){
    Zombie* zombie = new Zombie("Zombie", 100, 10, 1,1);
    MockPlayer* mockplayer = new MockPlayer("EMT", 100);
    zombie->addEffect(Slow);
    zombie->addEffect(ReduceMaxHealth);
    zombie->addEffect(ReduceBaseDamage);
    zombie->damageEntity(mockplayer);

    vector<StatusEffect> v = mockplayer->getEffects();
    EXPECT_EQ(v.size(), 3);
    EXPECT_THAT(v[0], Slow);
    EXPECT_THAT(v[1], ReduceMaxHealth);
    EXPECT_THAT(v[2], ReduceBaseDamage);

}
