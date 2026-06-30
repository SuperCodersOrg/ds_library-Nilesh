#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListInsertTest, InsertAtBeginning)
{
    LinkedList<int> list;

    list.append(20);
    list.append(30);

    list.insert(0, 10);

    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.head->data, 10);
}

TEST(LinkedListInsertTest, InsertAtMiddle)
{
    LinkedList<int> list;

    list.append(10);
    list.append(30);

    list.insert(1, 20);

    EXPECT_EQ(list.length(), 3);

    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.head->next->data, 20);
    EXPECT_EQ(list.tail->data, 30);
}

TEST(LinkedListInsertTest, InsertAtEnd)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);

    list.insert(2, 30);

    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.tail->data, 30);
}

TEST(LinkedListInsertTest, InsertIntoEmptyList)
{
    LinkedList<int> list;

    list.insert(0, 100);

    EXPECT_EQ(list.length(), 1);
    EXPECT_EQ(list.head->data, 100);
    EXPECT_EQ(list.tail->data, 100);
}

TEST(LinkedListInsertTest, InvalidNegativeIndex)
{
    LinkedList<int> list;

    list.append(10);

    EXPECT_THROW(list.insert(-1, 100), std::out_of_range);
}

TEST(LinkedListInsertTest, InvalidLargeIndex)
{
    LinkedList<int> list;

    list.append(10);

    EXPECT_THROW(list.insert(5, 100), std::out_of_range);
}