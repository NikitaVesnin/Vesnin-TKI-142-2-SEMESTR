#include "gtest/gtest.h"
#include "CircularList.h"

TEST(CircularListTest, DefaultConstructor) {
    CircularList list;
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 0);
}

TEST(CircularListTest, InitializerListConstructor) {
    CircularList list = {1, 2, 3};
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_TRUE(list.contains(1));
    EXPECT_TRUE(list.contains(2));
    EXPECT_TRUE(list.contains(3));
}

TEST(CircularListTest, InsertAndContains) {
    CircularList list;
    list.insert(10);
    list.insert(20);
    EXPECT_EQ(list.getSize(), 2);
    EXPECT_TRUE(list.contains(10));
    EXPECT_TRUE(list.contains(20));
    EXPECT_FALSE(list.contains(30));
}

TEST(CircularListTest, Remove) {
    CircularList list = {1, 2, 3};
    list.remove(2);
    EXPECT_EQ(list.getSize(), 2);
    EXPECT_FALSE(list.contains(2));
}

TEST(CircularListTest, CopyConstructor) {
    CircularList list1 = {1, 2, 3};
    CircularList list2(list1);
    EXPECT_EQ(list1.toString(), list2.toString());
}

TEST(CircularListTest, MoveConstructor) {
    CircularList list1 = {1, 2, 3};
    CircularList list2(std::move(list1));
    EXPECT_TRUE(list1.isEmpty());
    EXPECT_EQ(list2.getSize(), 3);
}