#include <stdio.h>
#include <string.h>

typedef struct {
    char name[40];
    float price;
    float weight;
} sandwich_t;

float order(sandwich_t sandwich, int);

int main()
{
    sandwich_t sandwich1;
    strcpy(sandwich1.name, "salami sandwich");
    sandwich1.price = 2.3;
    sandwich1.weight = 0.34;
    float cost1 = order(sandwich1, 3);
    printf("I'm a %s, I cost %.1f euros and weight %.1f kgs\n", sandwich1.name, sandwich1.price, sandwich1.weight);
    printf("you ordered 3 %s, they cost %.2f euros\n", sandwich1.name, cost1);
    return 0;
}

float order(sandwich_t sandwich, int amount)
{
    return amount * sandwich.price;
}