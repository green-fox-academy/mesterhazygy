#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> dataB;
    dataB["Eggs"] = 200;
    dataB["Milk"] = 200;
    dataB["Fish"] = 400;
    dataB["Apples"] = 150;
    dataB["Bread"] = 50;
    dataB["Chicken"] =550;
    std::map<std::string, int>::iterator mapIt;
    for (mapIt = dataB.begin(); mapIt != dataB.end(); mapIt++){
        if(mapIt->first == "Fish"){
            std::cout << "the fish costs " << mapIt->second << " forints." << std::endl;
        }
    }
    int biggest = 0;
    for (mapIt = dataB.begin(); mapIt != dataB.end() ; mapIt++) {
        if (mapIt->second > biggest){
            biggest = mapIt->second;
        }
    }
    for (mapIt = dataB.begin(); mapIt != dataB.end() ; mapIt++) {
        if (mapIt->second == biggest){
            std::cout << "The most expensive stuff on the list is " << mapIt->first << "." << std::endl;
        }
    }
    float average = 0;
    for (mapIt = dataB.begin(); mapIt != dataB.end() ; mapIt++) {
        average += mapIt->second;
    }
    average /= dataB.size();
    std::cout << "The average price is " << average << " forints." << std::endl;
    int belowCounter = 0;
    for (mapIt = dataB.begin(); mapIt != dataB.end() ; mapIt++) {
        if (mapIt->second < 300){
            belowCounter++;
        }
    }
    std::cout << "There are " << belowCounter << " items cheaper than 300 forints." << std::endl;
    int ourMoney = 125;
    for (mapIt = dataB.begin(); mapIt != dataB.end() ; mapIt++) {
        if (mapIt->second == ourMoney){
            std::cout << "For " << ourMoney << " forints we can buy " << mapIt->first << "." << std::endl;
        }
    }
    std::cout << "There's nothing that costs exactly 125 forints :(" << std::endl;
    int lowest = 1000;
    for (mapIt = dataB.begin(); mapIt != dataB.end() ; mapIt++) {
        if (mapIt->second < lowest){
            lowest = mapIt->second;
        }
    }
    for (mapIt = dataB.begin(); mapIt != dataB.end() ; mapIt++) {
        if (mapIt->second == lowest){
            std::cout << "The least expensive stuff on the list is " << mapIt->first << "." << std::endl;
        }
    }

    return 0;
}