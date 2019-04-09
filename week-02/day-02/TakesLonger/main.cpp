#include <iostream>

int main() {

    std::string quote("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");
    quote.replace(20, 1, " always takes longer than ");
    std::cout << quote << std::endl;

    return 0;
}