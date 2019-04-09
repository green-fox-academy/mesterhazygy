#include <iostream>
#include <map>

int main() {

    std::map<int, char> myMap;
    if (myMap.empty()) {
        std::cout << "The map is empty" << std::endl;
    } else {
        std::cout << "The map is not empty" << std::endl;
    }
    myMap[97] = 'a';
    myMap[98] = 'b';
    myMap[99] = 'c';
    myMap[65] = 'A';
    myMap[66] = 'B';
    myMap[67] = 'C';
    std::map<int, char>::iterator myIterator;
    for (myIterator = myMap.begin(); myIterator != myMap.end(); myIterator++) {
        std::cout << myIterator->first << " " << myIterator->second << std::endl;
    }
    myMap.insert(std::make_pair(68, 'D'));
    std::cout << myMap.size() << std::endl;
    std::cout << myMap[99] << std::endl;
    myMap.erase(97);
    for (myIterator = myMap.begin(); myIterator != myMap.end(); myIterator++){
        if (myIterator->first == 100) {
            std::cout << "There is an element with key 100" << std::endl;
        }
    } std::cout << "There's no element with key 100" << std::endl;
    myMap.clear();


    return 0;
}