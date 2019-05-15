#include <stdio.h>
#include "House.h"



int main()
{
    house_t haz1 = createHouse(4, 120, 50000, "1101 BP");
    house_t haz2 = createHouse(3, 65, 2000, "1101 BP");
    house_t houseList[2];
    houseList[0] = haz1;
    houseList[1] = haz2;
    if(isItWorthIt(haz1))
        printf("This house is worth it.\n");
    else
        printf("This house is not worth it.\n");
    printf("%d\n", housesToBuy(houseList, 2));


    return 0;
}