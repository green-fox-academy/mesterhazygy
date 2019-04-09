#include <iostream>
#include <string>

std::string reverse(std::string);

int main() {

    std::string reversed = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";
    std::cout << reverse(reversed) << std::endl;

    return 0;
}

std::string reverse(std::string myString) {
    std::string temp;
    for (int i = 0; i < myString.size(); i++) {
        if (i == 0) {
            temp = myString[myString.size() - i - 1];
        } else {
            temp += myString[myString.size() - i - 1];
        }
    }
    std::cout << temp;
}