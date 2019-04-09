#include <iostream>
#include <string>

int main() {

    std::string starWars = "In a dishwasher far, far away...";
    starWars.replace(5, 10, "galaxy");
    std::cout << starWars << std::endl;

    return 0;
}