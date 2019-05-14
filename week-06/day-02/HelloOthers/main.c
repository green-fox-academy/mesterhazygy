#include <stdio.h>

int main()
{
    char name1[20];
    char name2[20];
    char name3[20];
    printf("Hello, give me your names:\n");
    scanf("%s", name1);
    scanf("%s", name2);
    scanf("%s", name3);
    printf("Hello, %s, %s, %s \n", name1, name2, name3);

    return 0;
}