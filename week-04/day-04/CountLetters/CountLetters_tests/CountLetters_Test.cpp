#include <iostream>
#include <gtest/gtest.h>
#include "CountLetters.h"

TEST(testcounter, test_counter){
    std::string userWord = "kutyus";

    std::map<char, int> myMap = letterCounter(userWord);

    ASSERT_EQ(myMap['u'], 2);
}

