#include <stdio.h>

int main()
{
    char name[20];
    printf("Hi, what's your name?\n");
    scanf("%s", name);
    printf("Hello, %s \n", name);
    return 0;
}