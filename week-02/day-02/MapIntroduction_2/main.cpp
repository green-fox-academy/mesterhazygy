#include <iostream>
#include <map>

int main() {

    std::map<std::string, std::string> myMap;
    myMap["978-1-60309-452-8"] = "A Letter to Jo";
    myMap["978-1-60309-459-7"] = "Lupus";
    myMap["978-1-60309-444-3"] = "Red Panda and Moon Bear";
    myMap["978-1-60309-461-0"] = "The Lab";
    std::map<std::string, std::string>::iterator mapIt;
    for (mapIt = myMap.begin(); mapIt != myMap.end(); mapIt ++) {
        std::cout << mapIt->second << "(" << mapIt->first << ")" << std::endl;
    }
    for (mapIt = myMap.begin(); mapIt != myMap.end(); mapIt++) {
        if (mapIt->first == "978-1-60309-444-3") {
            myMap.erase(mapIt);
        }
    }
    for (mapIt = myMap.begin(); mapIt != myMap.end(); mapIt++) {
        if (mapIt->second == "The Lab") {
            myMap.erase(mapIt);
        }
    }
    myMap["978-1-60309-450-4"] = "They Called Us Enemy";
    myMap["978-1-60309-453-5"] = "Why Did We Trust Him?";
    if (myMap.count("478-0-61159-424-8") == 0) {
        std::cout << "There's no element with the specified key." << std::endl;
    } else {
        std::cout << "There's an element with the specified key." << std::endl;
    }
    std::cout << myMap.find("978-1-60309-453-5")->second << std::endl;

    return 0;
}