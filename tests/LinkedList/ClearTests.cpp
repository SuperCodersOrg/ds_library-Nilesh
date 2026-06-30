#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListClearTest, ClearPopulatedList)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.clear();

    EXPECT_EQ(list.length(), 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

TEST(LinkedListClearTest, ClearEmptyList)
{
    LinkedList<int> list;

    list.clear();

    EXPECT_EQ(list.length(), 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

TEST(LinkedListClearTest, ReuseAfterClear)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);

    list.clear();

    list.append(100);

    EXPECT_EQ(list.length(), 1);
    EXPECT_EQ(list.head->data, 100);
    EXPECT_EQ(list.tail->data, 100);
}

TEST(LinkedListClearTest, MultipleClearCalls)
{
    LinkedList<int> list;

    list.append(10);

    list.clear();
    list.clear();

    EXPECT_EQ(list.length(), 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}