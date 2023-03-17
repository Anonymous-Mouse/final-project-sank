#include <gtest/gtest.h>
#include "../header/Container.h"
#include "../header/Item.h"

using namespace std;

TEST(ContainerTest, IsLockedTest) {
    vector<Item*> contents = {new Item("key"), new Item("book")};
    Container container(contents, "chest", 5);
    container.unlock("key");

    EXPECT_FALSE(container.isLocked());
}

TEST(ContainerTest, UnlockTest) {
    vector<Item*> contents = {new Item("book"), new Item("pen")};
    Container container(contents, "drawer", 3, "password");

    EXPECT_FALSE(container.unlock("key"));
    EXPECT_TRUE(container.unlock("password"));
    EXPECT_FALSE(container.isLocked());
}

TEST(ContainerTest, GetContentsAmountTest) {
    vector<Item*> contents = {new Item("book"), new Item("pen"), new Item("phone")};
    Container container(contents, "box", 4);

    EXPECT_EQ(container.getContentsAmount(), 3);
}

TEST(ContainerTest, GetItemIndexTest) {
    vector<Item*> contents = {new Item("book"), new Item("pen"), new Item("phone")};
    Container container(contents, "box", 4);

    EXPECT_EQ(container.getItemIndex(1)->getName(), "pen");
}

TEST(ContainerTest, RemoveItemIndexTest) {
    vector<Item*> contents = {new Item("book"), new Item("pen"), new Item("phone")};
    Container container(contents, "box", 4);
    container.removeItemIndex(0);

    EXPECT_EQ(container.getContentsAmount(), 2);
}


TEST(ContainerTest, GetNameTest) {
    vector<Item*> contents = {new Item("book"), new Item("pen"), new Item("phone")};
    Container container(contents, "box", 4);

    EXPECT_EQ(container.getName(), "box");
}

TEST(LockedContainerTest, UnlockTest) {
    vector<Item*> contents = {new Item("book"), new Item("pen"), new Item("phone")};
    Container container(contents, "box", 4, "password");

    EXPECT_TRUE(container.isLocked());

    EXPECT_FALSE(container.unlock("wrong password"));
    EXPECT_TRUE(container.isLocked());

    EXPECT_TRUE(container.unlock("password"));
    EXPECT_FALSE(container.isLocked());
}

TEST(LockedContainerTest, IsLockedTest) {
    vector<Item*> contents = {new Item("book"), new Item("pen"), new Item("phone")};
    Container container(contents, "box", 4, "1234");

    EXPECT_TRUE(container.isLocked());

    container.unlock("1234");

    EXPECT_FALSE(container.isLocked());
}
