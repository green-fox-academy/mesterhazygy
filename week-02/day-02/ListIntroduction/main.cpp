#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> list;
    std::cout << list.size() << std::endl;
    list.emplace_back("William");
    if (list.empty()) {
        std::cout << "the list is empty." << std::endl;
    } else {
        std::cout << "the list has elements." << std::endl;
    }
    //std::cout << list.empty() << std::endl;
    list.push_back("John");
    list.push_back("Amanda");
    std::cout << "The list has " << list.size() << " elements." << std::endl;
    std::cout << "The third element is " << list[2] << std::endl;

    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << std::endl;
    }
    list.erase(list.begin() + 1);

    for (int j = list.size(); j >= 0; j --) {
        std::cout << list[j] << std::endl;
    }

    return 0;
}