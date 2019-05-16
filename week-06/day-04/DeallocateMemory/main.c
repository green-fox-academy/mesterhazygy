#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free
int main()
{
    int *numArray;
    numArray = (int *)malloc(10 * sizeof(numArray));
    for (int i = 0; i < 10; ++i) {
        numArray[i] = 2;
    }

    for (int j = 0; j < 10; ++j) {
        printf("%d\n", numArray[j]);
    }
    realloc(numArray, 0);

    for (int j = 0; j < 10; ++j) {
        printf("%d\n", numArray[j]);
    }

    free(numArray);
    numArray = NULL;
    return 0;
}