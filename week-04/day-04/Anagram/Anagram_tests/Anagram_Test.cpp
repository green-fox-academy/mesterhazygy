#include <iostream>
#include <gtest/gtest.h>
#include "Anagram.h"

TEST(is_Anagram, test_anagram){

    std::string firstWord = "thiswordisawesome";
    std::string secondWord = "swordisthiawesome";

    ASSERT_EQ(isAnagram(firstWord, secondWord), true);
}

