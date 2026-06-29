#include "../../external/googletest/googletest/include/gtest/gtest.h"
#include "../../include/DynamicArray.h"

TEST(DynamicArraySizeTest, InitiallyZero)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.size(),0);
}

TEST(DynamicArraySizeTest, SizeAfterInsertions)
{
    DynamicArray<int> arr;

    for(int i=0;i<10;i++)
        arr.push_back(i);

    EXPECT_EQ(arr.size(),10);
}

TEST(DynamicArraySizeTest, SizeAfterRemoval)
{
    DynamicArray<int> arr;

    for(int i=0;i<5;i++)
        arr.push_back(i);

    arr.remove(2);

    EXPECT_EQ(arr.size(),4);
}