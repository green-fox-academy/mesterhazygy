#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int *evenArray;
    int *oddArray;
    evenArray = (int *) calloc(10, sizeof(int));
    oddArray = (int *) calloc(10, sizeof(int));
    for (int i = 0; i < 10; ++i) {
        oddArray[i] = 2 * i - 1;
        evenArray[i] = 2 * i;
    }
    for (int j = 0; j < 10; ++j) {
        printf("%d, %d \n", oddArray[j], evenArray[j]);
    }
    printf("-------------------------------------------------------------------------\n");
    oddArray = (int *) realloc(oddArray, sizeof(int) * 20);
    for (int k = 0; k < 20; ++k) {
        if(k >= 10)
            oddArray[k] = evenArray[k - 10];
    }
    for (int l = 20; l > 0; l--) {
        printf("%d \n", oddArray[l - 1]);
    }
    free(oddArray);
    free(evenArray);
    oddArray = NULL;
    evenArray = NULL;
    return 0;
}