#include <iostream>
#include <gtest/gtest.h>
#include "Apple.h"


TEST(is_Apple, test_apple){
    ASSERT_EQ(getApple(), "apple");
}

TEST(test_sum, test_summary){

    std::vector<int> myVector = {1, 3, 65, 7, 23};

    ASSERT_EQ(sum(myVector), 99);
}

TEST(test_sum, test_summaryWithZeroElements){

    std::vector<int> myVector2 = {};

    ASSERT_EQ(sum(myVector2), 0);
}

TEST(test_sum, test_summaryOneElement){

    std::vector<int> myVector3 = {3};

    ASSERT_EQ(sum(myVector3), 3);
}

TEST(test_sum, test_summaryIsNegative){

    std::vector<int> myVector4 = {1, 3, -65, 7, 23};
    bool isNegative = sum(myVector4) < 0;

    ASSERT_EQ(isNegative, true);
}
