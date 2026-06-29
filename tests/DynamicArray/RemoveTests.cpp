#include "../../external/googletest/googletest/include/gtest/gtest.h"
#include "../../include/DynamicArray.h"

class DynamicArrayRemoveTest : public ::testing::Test {
protected:
    DynamicArray<int> arr;

    void SetUp() override {
        for (int i = 1; i <= 5; i++)
            arr.push_back(i);
    }
};

TEST_F(DynamicArrayRemoveTest, RemoveFromBeginning)
{
    arr.remove(0);

    EXPECT_EQ(arr.size(),4);
    EXPECT_EQ(arr[0],2);
    EXPECT_EQ(arr[1],3);
    EXPECT_EQ(arr[2],4);
    EXPECT_EQ(arr[3],5);
}

TEST_F(DynamicArrayRemoveTest, RemoveFromMiddle)
{
    arr.remove(2);

    EXPECT_EQ(arr.size(),4);
    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],4);
    EXPECT_EQ(arr[3],5);
}

TEST_F(DynamicArrayRemoveTest, RemoveFromEnd)
{
    arr.remove(arr.size()-1);

    EXPECT_EQ(arr.size(),4);
    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],3);
    EXPECT_EQ(arr[3],4);
}

TEST(DynamicArrayRemoveStandalone, RemoveOnlyElement)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.remove(0);

    EXPECT_EQ(arr.size(),0);
}

TEST(DynamicArrayRemoveStandalone, RemoveFromEmptyThrows)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.remove(0),std::out_of_range);
}

TEST(DynamicArrayRemoveStandalone, RemoveNegativeIndexThrows)
{
    DynamicArray<int> arr;
    arr.push_back(10);

    EXPECT_THROW(arr.remove(-1),std::out_of_range);
}

TEST(DynamicArrayRemoveStandalone, RemovePastEndThrows)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    EXPECT_THROW(arr.remove(2),std::out_of_range);
}

TEST(DynamicArrayRemoveStandalone, RemoveLargeDataset)
{
    DynamicArray<int> arr;

    for(int i=0;i<1000;i++)
        arr.push_back(i);

    arr.remove(500);

    EXPECT_EQ(arr.size(),999);

    for(int i=0;i<500;i++)
        EXPECT_EQ(arr[i],i);

    for(int i=500;i<999;i++)
        EXPECT_EQ(arr[i],i+1);
}