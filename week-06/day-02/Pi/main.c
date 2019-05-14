#include <stdio.h>
#define PI 3.14;

float area(float);

int main()
{
    float radius;
    printf("Give me the radius of the circle!\n");
    scanf("%f", &radius);
    float circleArea = area(radius);
    printf("The area of the circle is: %f\n", circleArea);
    return 0;
}

float area(float radius)
{
    float area = radius * radius * PI;
    return area;
}