#include <stdio.h>
#include "arethesame.h"

int main()
{
    char first[20];
    char second[20];
    printf("Give me two words!\n");
    scanf("%s", first);
    scanf("%s", second);
    if(areTheSame(first, second))
        printf("They are the same\n");
    else
        printf("They are not the same\n");
    return 0;
}