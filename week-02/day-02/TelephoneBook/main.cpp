#include <iostream>
#include <map>

int main() {

    std::map<std::string, std::string> telBook;
    telBook["William A. Lathan"] = "405-709-1865";
    telBook["John K. Miller"] = "402-247-8568";
    telBook["Hortensia E. Foster"] = "606-481-6467";
    telBook["Amanda D. Newland"] = "319-243-5613";
    telBook["Brooke P. Askew"] = "307-687-2982";
    std::cout << "John K. Miller's number is " << telBook.find("John K. Miller")->second << std::endl;
    std::map<std::string, std::string>::iterator telIterator;
    for (telIterator = telBook.begin(); telIterator != telBook.end(); telIterator ++) {
        if (telIterator->second == "307-687-2982") {
            std::cout << "This is " << telIterator->first << "'s number." << std::endl;
        }
    }
    if (telBook.count("Chris E. Myers") == 0) {
        std::cout << "There's no such entry in the book." << std::endl;
    } else {
        std::cout << "There's a number for this name." << std::endl;
    }

    return 0;
}