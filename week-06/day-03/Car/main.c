#include <stdio.h>
#include <string.h>

enum car_type {
    VOLVO,
    TOYOTA,
    LAND_ROVER,
    TESLA
};

typedef struct {
    enum car_type carType;
    double km;
    double gas;
    char type[10];
} car_t;

void introduce(car_t car);

int main()
{
    car_t Volvo;
    Volvo.carType = 0;
    Volvo.km = 172534;
    Volvo.gas = 30.5;
    strcpy(Volvo.type, "Volvo");

    introduce(Volvo);
    return 0;
}

void introduce(car_t car)
{
    int a = car.carType;
    switch(a)
    {
        case 0:
            strcpy(car.type, "Volvo");
            break;
        case 1:
            strcpy(car.type, "Toyota");
            break;
        case 2:
            strcpy(car.type, "Land Rover");
            break;
        case 3:
            strcpy(car.type, "Tesla");
            break;
        default:
            strcpy(car.type, "Trabant");
            break;
    }

    printf("Hi, I'm a %s, I ran %.1lf kms and have %.1lf litres of gas left.\n", car.type, car.km, car.gas);
}