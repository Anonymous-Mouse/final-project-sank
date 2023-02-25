#include "gtest/gtest.h"
#include  "gmock/gmock.h"
#include "../header/entity.hpp"
using Enemies::Entity;
using Monsters::Monster;

TEST(MonsterTests, testMonsterConstructor){
    Monster* monster = new Monster();
    EXPECT_EQ(monster.addEffect(), Monsters::Monster::StatusEffect::ZOMBIEBITE);

}