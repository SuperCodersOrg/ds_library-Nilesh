#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

TEST(DynamicArrayCapacityTest, DefaultCapacity)
{
    DynamicArray<int> arr;

    EXPECT_GT(arr.capacity(),0);
}

TEST(DynamicArrayCapacityTest, CapacityGrows)
{
    DynamicArray<int> arr;

    int oldCap=arr.capacity();

    while(arr.capacity()==oldCap)
        arr.push_back(1);

    EXPECT_GT(arr.capacity(),oldCap);
}

TEST(DynamicArrayCapacityTest, CapacityAfterClear)
{
    DynamicArray<int> arr;

    for(int i=0;i<20;i++)
        arr.push_back(i);

    int cap=arr.capacity();

    arr.clear();

    EXPECT_EQ(arr.capacity(),cap);
}