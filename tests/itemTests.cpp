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
};

class MockEntity: public Entity{
    public:
        MockEntity(std::string Name, int Health): Entity(Name, Health){};
        bool addEffect(StatusEffect eff) override{
            this->Effects.push_back(eff);
            return true;
        }
        bool removeEffect(StatusEffect effect) override{
            return false;
        }
};

TEST(Item, Construct){
    ASSERT_NO_THROW(MockItem item("testName"));
}

TEST(Item, getName){
    MockItem item("testName");
    EXPECT_EQ(item.getName(), "testName");
}

TEST(Weapon, Construct){
    ASSERT_NO_THROW(Weapon weapon("testWeapon", 10, 10));
}

TEST(Weapon, ConstructInvalidDamage){
    EXPECT_DEATH(Weapon weapon("testWeapon", -10, 10), "Damage of a weapon should not be less than 0");
}

TEST(Weapon, ConstructInvalidDurability){
    EXPECT_DEATH(Weapon weapon("testWeapon", 10, -10), "Durability of a weapon should not be less than 0");
}

TEST(Weapon, getDamage){
    Weapon weapon("testWeapon", 15, 5);
    EXPECT_EQ(weapon.getDamage(), 15);
}

TEST(Weapon, getDurability){
    Weapon weapon("testWeapon", 15, 5);
    EXPECT_EQ(weapon.getDurability(), 5);
}

TEST(Weapon, lowerDurability){
    Weapon weapon("testWeapon", 15, 5);
    weapon.lowerDurability();
    EXPECT_EQ(weapon.getDurability(), 4);
}

TEST(Weapon, lowerDurabilityAtZero){
    Weapon weapon("testWeapon", 15, 0);
    weapon.lowerDurability();
    EXPECT_EQ(weapon.getDurability(), 0);
}

TEST(Weapon, use){
    MockEntity entity("testEntity", 100);
    Weapon weapon("testWeapon", 15, 0);
    EXPECT_TRUE(weapon.use(&entity));
    EXPECT_EQ(weapon.getDamage(), 100-entity.getHealth());
}

TEST(Key, Construct){
    ASSERT_NO_THROW(Key key("testKey"));
}

TEST(Key, use){
    Key key("testKey");
    MockEntity entity("testEntity", 100);
    EXPECT_DEATH(key.use(&entity), "Key should not be used this way.");
}

TEST(Consumable, Construct){
    ASSERT_NO_THROW(Consumable consumable("testConsumable", StatusEffect::Slow, UsageType::enemy));
}

TEST(Consumable, getEffectSlow){
    Consumable consumable("testConsumable", StatusEffect::Slow, UsageType::enemy);
    EXPECT_EQ(consumable.getEffect(), StatusEffect::Slow);
}

TEST(Consumable, getEffectReduceBaseDamage){
    Consumable consumable("testConsumable", StatusEffect::ReduceBaseDamage, UsageType::enemy);
    EXPECT_EQ(consumable.getEffect(), StatusEffect::ReduceBaseDamage);
}

TEST(Consumable, getUsageSelf){
    Consumable consumable("testConsumable", StatusEffect::ReduceBaseDamage, UsageType::self);
    EXPECT_EQ(consumable.getUsage(), UsageType::self);
}

TEST(Consumable, getUsageEnemy){
    Consumable consumable("testConsumable", StatusEffect::ReduceBaseDamage, UsageType::enemy);
    EXPECT_EQ(consumable.getUsage(), UsageType::enemy);
}

TEST(Consumable, useReduceBaseDamage){
    Consumable consumable("testConsumable", StatusEffect::ReduceBaseDamage, UsageType::enemy);
    MockEntity entity("testEntity", 100);
    EXPECT_TRUE(consumable.use(&entity));
    EXPECT_EQ(entity.getEffects().at(0), StatusEffect::ReduceBaseDamage);
}

TEST(Consumable, ReduceMaxHealth){
    Consumable consumable("testConsumable", StatusEffect::ReduceMaxHealth, UsageType::enemy);
    MockEntity entity("testEntity", 100);
    EXPECT_TRUE(consumable.use(&entity));
    EXPECT_EQ(entity.getEffects().at(0), StatusEffect::ReduceMaxHealth);
}