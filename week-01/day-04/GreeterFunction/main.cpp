#include <iostream>

void saygreet (std::string);

int main() {

    std::string a1 = "Greenfox";
    saygreet (a1);

    return 0;
}

void saygreet (std::string a1) {
    std::cout << "greetings, dear " << a1 << std::endl;
}