#include <gtest/gtest.h>
#include "../header/Container.h"
#include "../header/Item.h"

using namespace std;

TEST(ContainerTest, IsLockedTest) {
    vector<Item> contents = {Item("key"), Item("book")};
    Container container(contents, "chest", 5);
    container.unlock("key");

    EXPECT_FALSE(container.isLocked());
}

TEST(ContainerTest, UnlockTest) {
    vector<Item> contents = {Item("book"), Item("pen")};
    Container container(contents, "drawer", 3);

    EXPECT_FALSE(container.unlock("key"));
    EXPECT_TRUE(container.unlock("password"));
    EXPECT_FALSE(container.isLocked());
}

TEST(ContainerTest, GetContentsAmountTest) {
    vector<Item> contents = {Item("book"), Item("pen"), Item("phone")};
    Container container(contents, "box", 4);

    EXPECT_EQ(container.getContentsAmount(), 3);
}

TEST(ContainerTest, GetItemIndexTest) {
    vector<Item> contents = {Item("book"), Item("pen"), Item("phone")};
    Container container(contents, "box", 4);

    EXPECT_EQ(container.getItemIndex(1).getName(), "pen");
}

TEST(ContainerTest, RemoveItemIndexTest) {
    vector<Item> contents = {Item("book"), Item("pen"), Item("phone")};
    Container container(contents, "box", 4);
    container.removeItemIndex(0);

    EXPECT_EQ(container.getContentsAmount(), 2);
}


TEST(ContainerTest, GetNameTest) {
    vector<Item> contents = {Item("book"), Item("pen"), Item("phone")};
    Container container(contents, "box", 4);

    EXPECT_EQ(container.getName(), "box");
}

TEST(LockedContainerTest, UnlockTest) {
    LockedContainer container("password");

    EXPECT_FALSE(container.unlock("wrong password"));
    EXPECT_TRUE(container.unlock("password"));
    EXPECT_FALSE(container.isLocked());
}

TEST(LockedContainerTest, IsLockedTest) {
    LockedContainer container("1234");
    container.unlock("1234");

    EXPECT_FALSE(container.isLocked());
}
