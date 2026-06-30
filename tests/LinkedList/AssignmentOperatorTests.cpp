#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LinkedListAssignmentOperatorTest, AssignPopulatedList)
{
    LinkedList<int> list1;

    list1.append(10);
    list1.append(20);
    list1.append(30);

    LinkedList<int> list2;

    list2 = list1;

    EXPECT_EQ(list2.length(), 3);
    EXPECT_TRUE(list2 == list1);
}

TEST(LinkedListAssignmentOperatorTest, AssignEmptyList)
{
    LinkedList<int> list1;
    LinkedList<int> list2;

    list2.append(10);
    list2.append(20);

    list2 = list1;

    EXPECT_EQ(list2.length(), 0);
    EXPECT_EQ(list2.head, nullptr);
    EXPECT_EQ(list2.tail, nullptr);
}

TEST(LinkedListAssignmentOperatorTest, SelfAssignment)
{
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    list = list;

    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.head->data, 1);
    EXPECT_EQ(list.head->next->data, 2);
    EXPECT_EQ(list.tail->data, 3);
}

TEST(LinkedListAssignmentOperatorTest, DeepCopyVerification)
{
    LinkedList<int> list1;

    list1.append(10);
    list1.append(20);

    LinkedList<int> list2;

    list2 = list1;

    list1.append(30);

    EXPECT_EQ(list1.length(), 3);
    EXPECT_EQ(list2.length(), 2);

    EXPECT_FALSE(list1 == list2);
}

TEST(LinkedListAssignmentOperatorTest, OverwriteExistingList)
{
    LinkedList<int> list1;

    list1.append(100);
    list1.append(200);

    LinkedList<int> list2;

    list2.append(1);
    list2.append(2);
    list2.append(3);

    list2 = list1;

    EXPECT_EQ(list2.length(), 2);
    EXPECT_EQ(list2.head->data, 100);
    EXPECT_EQ(list2.tail->data, 200);

    EXPECT_TRUE(list2 == list1);
}