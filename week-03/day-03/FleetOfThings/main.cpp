#include <iostream>
#include "Fleet.h"
#include "Thing.h"

int main()
{
    Fleet fleet;
    Thing milk("Get milk");
    Thing remove("Remove the obstacles");
    Thing stand("Stand up");
    Thing eat("Eat lunch");
    fleet.add(milk);
    fleet.add(remove);
    stand.complete();
    fleet.add(stand);
    eat.complete();
    fleet.add(eat);
    std::cout << fleet.toString() << std::endl;
    return 0;
}