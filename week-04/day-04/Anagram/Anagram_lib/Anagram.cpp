//
// Created by megha on 2019. 04. 25..
//

#include "Anagram.h"

bool isAnagram(std::string firstWord, std::string secondWord)
{
    bool flag = true;
    std::sort(firstWord.begin(), firstWord.end());
    std::sort(secondWord.begin(), secondWord.end());
    if (firstWord.length() != secondWord.length())
        return false;
    for (int i = 0; i < firstWord.length(); i++){
            if (firstWord[i] == secondWord[i]){
                flag = true;
            } else
                flag = false;
    }
    return flag;
}