#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int numOfNums;
    printf("Give me a number!\n");
    scanf("%d", &numOfNums);
    int *num1;
    num1 = (int*) malloc(numOfNums * sizeof(int));
    printf("Now give me %d numbers:\n", numOfNums);
    for (int i = 0; i < numOfNums; ++i) {
        scanf("%d", &num1[i]);
    }
    int num2 = 0;
    for (int j = 0; j < numOfNums ; ++j) {
        num2 += num1[j];
    }
    int *num3;
    num3 = (int*) malloc(num2 * sizeof(int));
    for (int k = 0; k < num2; ++k) {
        num3[k] = k + 1;
    }
    for (int l = 0; l < num2; ++l) {
        printf("%d, ", num3[l]);
    }
    free(num1);
    free(num3);
    num1 = NULL;
    num3 = NULL;

    return 0;
}