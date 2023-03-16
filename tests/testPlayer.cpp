#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/Player.h"
#include "../header/Container.h"
#include "../header/Item.h"
#include "../header/Weapon.h"
#include "../header/Entity.h"
#include "../header/Enemy.h"
#include <vector>

using namespace std;

class MockEnemy : public Entity {
    public:
        MockEnemy(string name, int health, int baseDamage, int damageSpread, int difficultyMultiplier) : Entity(Name, Health) {};
        ~MockEnemy(){};
        bool addEffect(StatusEffect effect) override{
            this->Effects.push_back(effect);
            return true;
        }
        bool removeEffect(StatusEffect effect) override{
            if(this->Effects.empty()){
                return true;
            }
            else{
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

TEST(PlayerTests, testGetName) {
    Item myItem = Item("key");
    //Item* myItemPointer = new Item("key");
    vector<Item*> contents = {&myItem};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    EXPECT_THAT(player->getName(), "Nick");
}

TEST(PlayerTests, testGetHealth) {
    Item myItem = Item("key");
    //Item* myItemPointer = new Item("key");
    vector<Item*> contents = {&myItem};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    EXPECT_THAT(player->getHealth(), 100);
}

TEST(PlayerTests, testGetBaseDamage) {
    Item myItem = Item("key");
    //Item* myItemPointer = new Item("key");
    vector<Item*> contents = {&myItem};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    EXPECT_THAT(player->getBaseDamage(), 25);
}

TEST(PlayerTests, testContainerGetName) {
    Item myItem = Item("key");
    //Item* myItemPointer = new Item("key");
    vector<Item*> contents = {&myItem};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    EXPECT_THAT(newContainer->getName(), "inv");
}

TEST(PlayerTests, testGetContentsAmount) {
    Item myItem = Item("key");
    //Item* myItemPointer = new Item("key");
    vector<Item*> contents = {&myItem};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    EXPECT_THAT(newContainer->getContentsAmount(), 1);
}

TEST(PlayerTests, testGetContentsAmount2) {
    Item key = Item("key");
    Item weapon = Item("weapon");
    //Item* myItemPointer = new Item("key");
    vector<Item*> contents = {&key, &weapon};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    EXPECT_THAT(newContainer->getContentsAmount(), 2);
}

TEST(PlayerTests, testGetItemIndex) {
    Item key = Item("key");
    Item weapon = Item("weapon");
    Item wrench = Item("wrench");
    //Item* myItemPointer = new Item("key");
    vector<Item*> contents = {&key, &weapon, &wrench};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    EXPECT_THAT(newContainer->getItemIndex(2), &wrench);
}

TEST(PlayerTests, testGetWeapon) {
    Item key = Item("key");
    Weapon* gun = new Weapon("Gun", 35, 25);
    //Item* myItemPointer = new Item("key");
    vector<Item*> contents = {&key, gun};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    player->setWeapon(gun);
    EXPECT_THAT(player->getWeapon(), gun);
}

TEST(PlayerTests, testAddEffect) {
    vector<Item*> contents = {};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    EXPECT_TRUE(player->addEffect(ReduceMaxHealth));
}

TEST(PlayerTests, testRemoveEffect) {
    vector<Item*> contents = {};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,25,newContainer);
    player->addEffect(ReduceMaxHealth);
    EXPECT_TRUE(player->removeEffect(ReduceMaxHealth));
}

TEST(PlayerTests, testDamageEntity) {
    vector<Item*> contents = {};
    Container* newContainer = new Container(contents,"inv",5,"ABCD");
    Player* player = new Player("Nick",100,20,newContainer);
    MockEnemy* enemy = new MockEnemy("Rat", 100, 10, 1, 1);
    player->damageEntity(enemy);
    EXPECT_EQ(enemy->getHealth(), 80);
}