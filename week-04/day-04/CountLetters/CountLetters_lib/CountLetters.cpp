//
// Created by megha on 2019. 04. 25..
//

#include "CountLetters.h"

std::map<char, int> letterCounter(std::string userWord)
{
    std::map<char, int> counter;
    for (int j = 0; j < userWord.length(); j++){
        if (counter.find(userWord[j])->first) {
            counter[j]++;
        } else{
            counter.insert(std::pair<char, int>(userWord[j], 1));
        }
    }
    return counter;
}
