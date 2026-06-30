#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListPopTest, PopLastElement)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.pop();

    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.tail->data, 20);
}

TEST(LinkedListPopTest, PopUntilEmpty)
{
    LinkedList<int> list;

    list.append(1);
    list.append(2);

    list.pop();
    list.pop();

    EXPECT_EQ(list.length(), 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

TEST(LinkedListPopTest, PopSingleElement)
{
    LinkedList<int> list;

    list.append(100);

    list.pop();

    EXPECT_EQ(list.length(), 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

TEST(LinkedListPopTest, PopFromEmptyList)
{
    LinkedList<int> list;

    EXPECT_THROW(list.pop(), std::underflow_error);
}