#include <stdio.h>

int main()
{
    double sideA, sideB, sideC;
    printf("Give me the sides of the cuboid pls\n");
    scanf("%lf", &sideA);
    scanf("%lf", &sideB);
    scanf("%lf", &sideC);
    double surface = 2 * sideA * sideB + 2 * sideA * sideC + 2 * sideB * sideC;
    double volume = sideA * sideB * sideC;
    printf("Surface is: %.2lf\n", surface);
    printf("Volume is: %.2lf\n", volume);
    return 0;
}