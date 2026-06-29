#include "../../external/googletest/googletest/include/gtest/gtest.h"
#include "../../include/DynamicArray.h"

TEST(DynamicArrayClearTest, ClearArray)
{
    DynamicArray<int> arr;

    for(int i=1;i<=10;i++)
        arr.push_back(i);

    arr.clear();

    EXPECT_EQ(arr.size(),0);
}

TEST(DynamicArrayClearTest, ClearEmptyArray)
{
    DynamicArray<int> arr;

    arr.clear();

    EXPECT_EQ(arr.size(),0);
}

TEST(DynamicArrayClearTest, ReuseAfterClear)
{
    DynamicArray<int> arr;

    for(int i=0;i<5;i++)
        arr.push_back(i);

    arr.clear();

    arr.push_back(100);

    EXPECT_EQ(arr.size(),1);
    EXPECT_EQ(arr[0],100);
}