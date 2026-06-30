#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListAppendTest, AppendSingleElement)
{
    LinkedList<int> list;

    list.append(10);

    EXPECT_EQ(list.length(), 1);
    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.tail->data, 10);
}

TEST(LinkedListAppendTest, AppendMultipleElements)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    EXPECT_EQ(list.length(), 3);

    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.head->next->data, 20);
    EXPECT_EQ(list.tail->data, 30);
}

TEST(LinkedListAppendTest, TailUpdatesCorrectly)
{
    LinkedList<int> list;

    list.append(5);
    list.append(15);
    list.append(25);

    EXPECT_EQ(list.tail->data, 25);
    EXPECT_EQ(list.tail->next, nullptr);
}

TEST(LinkedListAppendTest, AppendAfterClear)
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

TEST(LinkedListAppendTest, AppendLargeDataset)
{
    LinkedList<int> list;

    for(int i = 0; i < 1000; i++)
        list.append(i);

    EXPECT_EQ(list.length(), 1000);
    EXPECT_EQ(list.head->data, 0);
    EXPECT_EQ(list.tail->data, 999);
}