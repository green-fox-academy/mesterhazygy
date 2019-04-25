//
// Created by megha on 2019. 04. 25..
//

#include "Apple.h"

std::string getApple()
{
    return "apple";
}

int sum(std::vector<int> myVector)
{
    int summary = 0;
    for (int i = 0; i < myVector.size(); i++) {
        summary += myVector[i];
    }
    return summary;
}