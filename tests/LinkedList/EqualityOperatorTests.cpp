#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListEqualityOperatorTest, EqualLists)
{
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.append(10);
    list1.append(20);
    list1.append(30);

    list2.append(10);
    list2.append(20);
    list2.append(30);

    EXPECT_TRUE(list1 == list2);
}

TEST(LinkedListEqualityOperatorTest, DifferentSizes)
{
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.append(10);
    list1.append(20);

    list2.append(10);

    EXPECT_FALSE(list1 == list2);
}

TEST(LinkedListEqualityOperatorTest, DifferentValues)
{
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.append(10);
    list1.append(20);
    list1.append(30);

    list2.append(10);
    list2.append(99);
    list2.append(30);

    EXPECT_FALSE(list1 == list2);
}

TEST(LinkedListEqualityOperatorTest, EmptyLists)
{
    LinkedList<int> list1;
    LinkedList<int> list2;

    EXPECT_TRUE(list1 == list2);
}

TEST(LinkedListEqualityOperatorTest, OneEmptyOneNonEmpty)
{
    LinkedList<int> list1;
    LinkedList<int> list2;

    list2.append(100);

    EXPECT_FALSE(list1 == list2);
}