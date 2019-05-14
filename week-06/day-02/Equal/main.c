#include <stdio.h>
#include "Equal.h"

int main()
{
    int userNum1, userNum2;
    printf("Give me 2 numbers!\n");
    scanf("%d", &userNum1);
    scanf("%d", &userNum2);
    if(equal(userNum1, userNum2))
        printf("They are equal!\n");
    else
        printf("They are not equal!\n");
    return 0;
}