#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main()
{
    Cat kutya("joe");
    Cat cat;
    kutya.toString();
    kutya.heal();
    kutya.toString();
    cat.heal();
    cat.toString();
    return 0;
}