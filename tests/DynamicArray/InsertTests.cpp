#include "../../external/googletest/googletest/include/gtest/gtest.h"
#include "../../include/DynamicArray.h"



class DynamicArrayInsertTest : public ::testing::Test {
protected:
    DynamicArray<int> arr;

    void SetUp() override {
        for (int i = 1; i <= 5; i++)
            arr.push_back(i);
    }
};

TEST_F(DynamicArrayInsertTest, InsertAtBeginning)
{
    arr.insert(0,100);

    EXPECT_EQ(arr.size(),6);
    EXPECT_EQ(arr[0],100);
    EXPECT_EQ(arr[1],1);
    EXPECT_EQ(arr[2],2);
    EXPECT_EQ(arr[3],3);
    EXPECT_EQ(arr[4],4);
    EXPECT_EQ(arr[5],5);
}

TEST_F(DynamicArrayInsertTest, InsertAtMiddle)
{
    arr.insert(2,99);

    EXPECT_EQ(arr.size(),6);
    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],2);
    EXPECT_EQ(arr[2],99);
    EXPECT_EQ(arr[3],3);
    EXPECT_EQ(arr[4],4);
    EXPECT_EQ(arr[5],5);
}

TEST_F(DynamicArrayInsertTest, InsertAtEnd)
{
    arr.insert(arr.size(),200);

    EXPECT_EQ(arr.size(),6);
    EXPECT_EQ(arr[5],200);
}

TEST(DynamicArrayInsertStandalone, InsertIntoEmptyArray)
{
    DynamicArray<int> arr;
    arr.insert(0,10);

    EXPECT_EQ(arr.size(),1);
    EXPECT_EQ(arr[0],10);
}

TEST(DynamicArrayInsertStandalone, InsertTriggersResize)
{
    DynamicArray<int> arr(2,0);

    arr.pop_back();
    arr.pop_back();
    arr.push_back(1);
    arr.push_back(2);

    int oldCap = arr.capacity();

    arr.insert(1,99);

    EXPECT_GT(arr.capacity(),oldCap);
    EXPECT_EQ(arr.size(),3);

    EXPECT_EQ(arr[0],1);
    EXPECT_EQ(arr[1],99);
    EXPECT_EQ(arr[2],2);
}

TEST(DynamicArrayInsertStandalone, InsertNegativeIndexThrows)
{
    DynamicArray<int> arr;
    EXPECT_THROW(arr.insert(-1,5),std::out_of_range);
}

TEST(DynamicArrayInsertStandalone, InsertPastEndThrows)
{
    DynamicArray<int> arr;
    arr.push_back(10);

    EXPECT_THROW(arr.insert(2,5),std::out_of_range);
}

TEST(DynamicArrayInsertStandalone, InsertLargeDataset)
{
    DynamicArray<int> arr;

    for(int i=0;i<1000;i++)
        arr.push_back(i);

    arr.insert(500,-1);

    EXPECT_EQ(arr.size(),1001);
    EXPECT_EQ(arr[500],-1);

    for(int i=0;i<500;i++)
        EXPECT_EQ(arr[i],i);

    for(int i=501;i<1001;i++)
        EXPECT_EQ(arr[i],i-1);
}
