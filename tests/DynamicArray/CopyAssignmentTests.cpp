#include <gtest/gtest.h>
#include "DynamicArray.h"

TEST(DynamicArrayCopyAssignmentTest, NormalAssignment)
{
    DynamicArray<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    DynamicArray<int> copy;

    copy=arr;

    EXPECT_EQ(copy.size(),arr.size());

    for(int i=0;i<arr.size();i++)
        EXPECT_EQ(copy[i],arr[i]);
}

TEST(DynamicArrayCopyAssignmentTest, SelfAssignment)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    arr=arr;

    EXPECT_EQ(arr.size(),2);
    EXPECT_EQ(arr[0],10);
    EXPECT_EQ(arr[1],20);
}

TEST(DynamicArrayCopyAssignmentTest, DeepCopy)
{
    DynamicArray<int> arr;

    arr.push_back(5);

    DynamicArray<int> copy;

    copy=arr;

    arr[0]=99;

    EXPECT_EQ(copy[0],5);
}