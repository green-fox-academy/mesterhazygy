#include <iostream>
#include <vector>

int main() {

    std::vector<int> myMoney = {500, 1000, 1250, 175, 800, 120};
    int myVariable = 0;
    for (int i = 0; i < myMoney.size(); i++ ) {
        myVariable += myMoney[i];
    }
    std::cout << "I spent " << myVariable << " dollars :(" << std::endl;
    for (int j = 0; j < myMoney.size(); j ++) {
        if (j == 0) {
            myVariable = myMoney[j];
        } else if (myMoney[j] > myVariable) {
            myVariable = myMoney[j];
        }
    }
    std::cout << "My biggest expense was " << myVariable << " dollars." << std::endl;
    for (int k = 0; k < myMoney.size(); k ++) {
        if (myMoney[k] < myVariable) {
            myVariable = myMoney[k];
        }
    }
    std::cout << "My cheapest spending was " << myVariable << " dollars." << std::endl;
    int myAverage = 0;
    for (int l = 0; l < myMoney.size(); l ++) {
        myAverage += myMoney[l];
    }
    std::cout << "My average spending was " << myAverage / myMoney.size() << " dollars." << std::endl;

    return 0;
}