#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListExistsTest, ExistingElement)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    EXPECT_TRUE(list.exists(20));
}

TEST(LinkedListExistsTest, NonExistingElement)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);

    EXPECT_FALSE(list.exists(50));
}

TEST(LinkedListExistsTest, EmptyList)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.exists(10));
}

TEST(LinkedListExistsTest, FirstElementExists)
{
    LinkedList<int> list;

    list.append(100);
    list.append(200);

    EXPECT_TRUE(list.exists(100));
}

TEST(LinkedListExistsTest, LastElementExists)
{
    LinkedList<int> list;

    list.append(100);
    list.append(200);

    EXPECT_TRUE(list.exists(200));
}