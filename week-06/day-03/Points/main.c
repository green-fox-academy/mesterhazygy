#include <stdio.h>
#include "Points.h"

int main()
{
    point_t p1 = create_point(1, 1);
    point_t p2 = create_point(4, 5);
    printf("%f\n", dist(p1, p2));

    return 0;
}