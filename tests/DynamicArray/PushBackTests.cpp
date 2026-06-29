#include "../../external/googletest/googletest/include/gtest/gtest.h"
#include "../../include/DynamicArray.h"

TEST(DynamicArrayPushBackTest, PushSingleElement)
{
    DynamicArray<int> arr;

    arr.push_back(10);

    EXPECT_EQ(arr.size(),1);
    EXPECT_EQ(arr[0],10);
}

TEST(DynamicArrayPushBackTest, PushMultipleElements)
{
    DynamicArray<int> arr;

    for(int i=1;i<=5;i++)
        arr.push_back(i);

    EXPECT_EQ(arr.size(),5);

    for(int i=0;i<5;i++)
        EXPECT_EQ(arr[i],i+1);
}

TEST(DynamicArrayPushBackTest, PushTriggersResize)
{
    DynamicArray<int> arr(2,0);

    arr.pop_back();
    arr.pop_back();

    arr.push_back(1);
    arr.push_back(2);

    int oldCap=arr.capacity();

    arr.push_back(3);

    EXPECT_GT(arr.capacity(),oldCap);
    EXPECT_EQ(arr.size(),3);
}

TEST(DynamicArrayPushBackTest, PushLargeDataset)
{
    DynamicArray<int> arr;

    for(int i=0;i<10000;i++)
        arr.push_back(i);

    EXPECT_EQ(arr.size(),10000);

    for(int i=0;i<10000;i++)
        EXPECT_EQ(arr[i],i);
}