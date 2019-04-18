#include <iostream>
#include "Domino.h"
#include <vector>

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main()
{
    std::vector<Domino> dominoes = initializeDominoes();
    int a = 0;
    for (int i = a; i < dominoes.size(); i++) {
        for (int j = 1; j < dominoes.size(); j++) {
            if (dominoes[a].getValues().second == dominoes[j].getValues().first) {
                a = j;
                std::cout << dominoes[j].toString();
            }
        }
    }
    /*for (it = dominoes.begin(); it != dominoes.end(); it++) {
        if (it->getValues().second == (it + 1)->getValues().first) {
            std::cout << it->toString() << (it + 1)->toString() << std::endl;
        } else {

        }
    }*/

    return 0;
}