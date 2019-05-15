//
// Created by megha on 2019. 05. 15..
//

#include "House.h"

house_t createHouse(int roomNum, int area, int price, char *address)
{
    house_t house;
    house.roomNum = roomNum;
    house.area = area;
    house.price = price;
    strcpy(house.address, address);
    return house;
}

int isItWorthIt(house_t house)
{
    int customPrice = house.area * 400;
    if(customPrice > house.price)
        return 1;
    else
        return 0;
}

int housesToBuy(house_t houseList[], int a)
{
    int counter = 0;
    for (int i = 0; i < a; ++i) {
        if(isItWorthIt(houseList[i]))
        counter++;

    }
    return counter;
}