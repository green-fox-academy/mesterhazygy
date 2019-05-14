#include <stdio.h>
#include "length.h"

int main()
{
    char name[20];
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Your name is %d characters long.\n", length(name));
    return 0;
}