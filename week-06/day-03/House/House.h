//
// Created by megha on 2019. 05. 15..
//

#ifndef HOUSE_HOUSE_H
#define HOUSE_HOUSE_H

#include <string.h>

typedef struct {
    char address[30];
    int price;
    int roomNum;
    int area;
}house_t;

house_t createHouse(int, int, int, char*);

int isItWorthIt(house_t);

int housesToBuy(house_t[], int);

#endif //HOUSE_HOUSE_H
