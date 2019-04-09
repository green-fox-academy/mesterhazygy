#include <iostream>
#include <vector>
#include <string>

int main() {

    std::vector<std::string> listA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};
    std::vector<std::string> listB = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};
    for (unsigned int i = 0; i < listA.size(); i++) {
        if ((listA.at(i).compare("Durian")) == 0) {
            std::cout << "Durian is on the list" << std::endl;
            break;
        } else if (i == listA.size() - 1) {
            std::cout << "There is no Durian" << std::endl;
        }
    }
    listB.erase(listB.begin() + 3);
    listA.insert(listA.begin() + 3, "Kiwifruit");

    if (listA.size() == listB.size()) {
        std::cout << "Same" << std::endl;
    } else if (listA.size() > listB.size()) {
        std::cout << "List A is bigger" << std::endl;
    } else if (listA.size() < listB.size()){
        std::cout << "List B is bigger" << std::endl;
    }
    for (unsigned int j = 0; j < listA.size(); j++) {
        if ((listA.at(j).compare("Avocado")) == 0) {
            std::cout << "The index of Avocado on the first list is " << j << std::endl;
        }
    }
    for (unsigned int k = 0; k < listB.size(); k++) {
        if ((listB.at(k).compare("Durian")) == 0) {
            std::cout << "The index of Durian on the second list is " << k << std::endl;
        }
    }
    listB.insert(listB.end(), {"Passion fruit", "Pummelo"});
    for (int l = 0; l < listB.size(); l++){
        std::cout << listB[l] << std::endl;
    }
    std::cout << listA[2] << std::endl;

    return 0;
}