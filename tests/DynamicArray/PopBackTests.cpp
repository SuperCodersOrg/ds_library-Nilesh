#include <gtest/gtest.h>
#include "../../include/DynamicArray.h"

class DynamicArrayPopBackTest : public ::testing::Test
{
protected:

    DynamicArray<int> arr;

    void SetUp() override
    {
        for(int i=1;i<=5;i++)
            arr.push_back(i);
    }
};

TEST_F(DynamicArrayPopBackTest, RemoveLastElement)
{
    arr.pop_back();

    EXPECT_EQ(arr.size(),4);
    EXPECT_EQ(arr[3],4);
}

TEST_F(DynamicArrayPopBackTest, RemoveAllElements)
{
    while(arr.size())
        arr.pop_back();

    EXPECT_EQ(arr.size(),0);
}

TEST(DynamicArrayPopBackStandalone, PopFromEmptyThrows)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.pop_back(),std::underflow_error);
}