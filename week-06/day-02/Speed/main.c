#include <stdio.h>
#define DISTANCE 1313

int main()
{
    float seconds = 17;
    float speed = DISTANCE / seconds;

    printf("%f", speed);
    return 0;
}