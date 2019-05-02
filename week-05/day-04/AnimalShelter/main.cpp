#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"
#include "Shelter.h"

int main()
{
    Cat kutya("joe");
    Cat cat;
    kutya.toString();
    cat.heal();
    cat.toString();
    Shelter ss;
    ss.rescue(&kutya);
    ss.heal();
    ss.addAdopter();
    ss.earnDonation(232);


    return 0;
}