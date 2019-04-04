#include <iostream>

int main() {

    std::string abc [] = {"first", "second", "third"};
    std::string a = abc [0];
    abc [0] = abc [2];
    abc [2] = a;

    return 0;
}