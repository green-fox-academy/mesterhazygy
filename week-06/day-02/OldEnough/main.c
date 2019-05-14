#include <stdio.h>
#include "AgeCalculator.h"

int main()
{
    float age;
    printf("How old are you?\n");
    scanf("%f", &age);
    if(ageCalc(age))
        printf("Yay, you are old enough to buy drinks!\n");
    else
        printf("You are way too young to drink!\n");
    return 0;
}