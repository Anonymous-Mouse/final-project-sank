#include "gtest/gtest.h"
#include "../header/Item.h"
#include "../header/Key.h"
#include "../header/Weapon.h"
#include "../header/Consumable.h"
#include <iostream>

class MockItem: public Item{
    public:
    bool use(Entity*) override{
        return true;
    }
    MockItem(std::string Name): Item(Name){}
}

TEST(Item, Construct){
    EXPECT_NO_DEATH(MockItem item("testName"));
}