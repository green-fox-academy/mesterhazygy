#include <stdio.h>
#include "Circle.h"

int main()
{
    float radius;
    printf("Give me the radius of the circle!\n");
    scanf("%f", &radius);
    float circleArea = area(radius);
    float circum = circumference(radius);
    printf("The area of the circle is: %f\n", circleArea);
    printf("The circumference of the circle is: %f\n", circum);
    return 0;
}