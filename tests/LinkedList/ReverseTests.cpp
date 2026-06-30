#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListReverseTest, ReverseEmptyList)
{
    LinkedList<int> list;

    list.reverse();

    EXPECT_EQ(list.length(), 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

TEST(LinkedListReverseTest, ReverseSingleElement)
{
    LinkedList<int> list;

    list.append(10);

    list.reverse();

    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.tail->data, 10);
}

TEST(LinkedListReverseTest, ReverseMultipleElements)
{
    LinkedList<int> list;

    list.append(10);
    list.append(20);
    list.append(30);

    list.reverse();

    EXPECT_EQ(list.head->data, 30);
    EXPECT_EQ(list.head->next->data, 20);
    EXPECT_EQ(list.tail->data, 10);
}

TEST(LinkedListReverseTest, ReverseTwiceReturnsOriginal)
{
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    list.reverse();
    list.reverse();

    EXPECT_EQ(list.head->data, 1);
    EXPECT_EQ(list.head->next->data, 2);
    EXPECT_EQ(list.tail->data, 3);
}