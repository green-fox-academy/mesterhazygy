#include <stdio.h>

int main()
{
    int array[] = { 103, 114, 101, 101, 110, 32, 102, 111, 120};
    for (int i = 0; i < 9; ++i) {
        printf("%c", array[i]);
    }
    return 0;
}