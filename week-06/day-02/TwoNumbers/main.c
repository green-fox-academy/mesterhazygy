#include <stdio.h>

int main()
{
    int number1 = 22;
    int number2 = 13;
    printf("%d \n", number1 + number2);
    printf("%d \n", number1 - number2);
    printf("%d \n", number1 * number2);
    printf("%.2f \n", (float)number1 / (float)number2);
    printf("%d \n", number1 % number2);
    return 0;
}