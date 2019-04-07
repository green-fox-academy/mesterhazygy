#include <iostream>

int main() {

    int numberToGuess = 13;
    int userGuess;
    std::cout << "Hi, I have a number, can you guess it?" << std::endl;
    std::cin >> userGuess;
    while (userGuess < numberToGuess) {
        std::cout << "The stored number is higher, guess again!";
        std::cin >> userGuess;
    }
    while (userGuess > numberToGuess) {
        std::cout << "The stored number is lower, guess again!";
        std::cin >> userGuess;
    }
    if (userGuess == numberToGuess) {
        std::cout << "You found my number, it's: " << numberToGuess << std::endl;
    }

    return 0;
}