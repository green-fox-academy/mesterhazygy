#include <iostream>
#include <gtest/gtest.h>
#include "Apple.h"


TEST(is_Apple, test_apple){
    ASSERT_EQ(getApple(), "apple");
}

