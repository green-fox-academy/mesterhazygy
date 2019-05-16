#include <stdio.h>
#include <stdlib.h>

// with calloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits
// what's the difference between this and the previous excersice?

int main()
{
    int *numArray;
    int temp = 0;
    numArray = (int *)calloc(10, sizeof(numArray));
    for (int i = 0; i < 5; ++i) {
        numArray[i] = temp;
        temp++;
    }
    for (int j = 0; j < 10; ++j) {
        printf("%d\n", numArray[j]);
    }
    free(numArray);
    numArray = NULL;
    return 0;
}