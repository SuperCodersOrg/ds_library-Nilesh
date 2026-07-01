#include <gtest/gtest.h>
#include "DynamicArray.h"

TEST(DynamicArrayCopyConstructorTest, DeepCopy)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    DynamicArray<int> copy(arr);

    EXPECT_EQ(copy.size(), arr.size());

    for(int i=0;i<arr.size();i++)
        EXPECT_EQ(copy[i], arr[i]);
}

TEST(DynamicArrayCopyConstructorTest, ModifyOriginal)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    DynamicArray<int> copy(arr);

    arr[0]=100;

    EXPECT_EQ(copy[0],10);
}

TEST(DynamicArrayCopyConstructorTest, EmptyArray)
{
    DynamicArray<int> arr;

    DynamicArray<int> copy(arr);

    EXPECT_EQ(copy.size(),0);
}