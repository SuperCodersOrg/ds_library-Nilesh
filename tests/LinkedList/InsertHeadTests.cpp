#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListInsertHeadTest, InsertSingleElement)
{
    LinkedList<int> list;

    list.insertHead(10);

    EXPECT_EQ(list.length(), 1);
    EXPECT_NE(list.head, nullptr);
    EXPECT_NE(list.tail, nullptr);

    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.tail->data, 10);
}

TEST(LinkedListInsertHeadTest, InsertMultipleElements)
{
    LinkedList<int> list;

    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);

    EXPECT_EQ(list.length(), 3);

    EXPECT_EQ(list.head->data, 30);
    EXPECT_EQ(list.head->next->data, 20);
    EXPECT_EQ(list.tail->data, 10);
}

TEST(LinkedListInsertHeadTest, TailRemainsFirstInsertedElement)
{
    LinkedList<int> list;

    list.insertHead(5);
    list.insertHead(15);
    list.insertHead(25);

    EXPECT_EQ(list.tail->data, 5);
    EXPECT_EQ(list.tail->next, nullptr);
}

TEST(LinkedListInsertHeadTest, HeadChangesAfterEveryInsertion)
{
    LinkedList<int> list;

    list.insertHead(1);
    EXPECT_EQ(list.head->data, 1);

    list.insertHead(2);
    EXPECT_EQ(list.head->data, 2);

    list.insertHead(3);
    EXPECT_EQ(list.head->data, 3);

    EXPECT_EQ(list.length(), 3);
}

TEST(LinkedListInsertHeadTest, InsertAfterClear)
{
    LinkedList<int> list;

    list.insertHead(10);
    list.insertHead(20);

    list.clear();

    list.insertHead(100);

    EXPECT_EQ(list.length(), 1);
    EXPECT_EQ(list.head->data, 100);
    EXPECT_EQ(list.tail->data, 100);
}