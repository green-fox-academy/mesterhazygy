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

