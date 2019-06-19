#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> shoppingList = {"eggs", "milk", "fish", "apples", "bread", "chicken"};
    for (int i = 0; i < shoppingList.size(); i++) {
        if (shoppingList[i] == "milk") {
            std::cout << "There's milk on the list already." << std::endl;
            break;
        } else if (i == shoppingList.size() - 1) {
            std::cout << "There's no milk on the list." << std::endl;
        }
    }
    for (int j = 0; j < shoppingList.size(); j++) {
        if (shoppingList[j] == "bananas") {
            std::cout << "There's bananas on the list already." << std::endl;
            break;
        } else if (j == shoppingList.size() - 1) {
            std::cout << "There's no bananas on the list." << std::endl;
        }
    }

    return 0;
}
