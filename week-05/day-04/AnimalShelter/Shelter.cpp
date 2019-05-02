//
// Created by megha on 2019. 05. 02..
//

#include "Shelter.h"

Shelter::Shelter()
{
    _budget = 50;
    _animals = {};
    _adopters = {};
}

const std::vector<Animal *> &Shelter::getAnimals() const
{
    return _animals;
}

int Shelter::getBudget() const
{
    return _budget;
}

const std::vector<std::string> &Shelter::getAdopters() const
{
    return _adopters;
}

int Shelter::rescue(Animal *animal)
{
    _animals.push_back(animal);
    int a = _animals.size();
    return a;
}

std::string Shelter::addAdopter()
{
    std::string adopterName;
    std::cout << "Hi, give me the adopter's name" << std::endl;
    std::cin >> adopterName;
    _adopters.push_back(adopterName);
}

void Shelter::heal()
{
    for (int i = 0; i < _animals.size(); ++i) {
        if (!_animals[i]->isIsHealthy()) {
            bool temp = isIsHealthy();
            temp = true;
            setIsHealthy(temp);
            while (_budget > _animals[i]->getHealCost()) {
                _budget -= _animals[i]->getHealCost();
            }
        }
    }
}

void Shelter::findNewOwner()
{
    std::map<std::string, std::string> nameList;
    int size = _animals.size();
    int a = rand() % size;
    if (_adopters.size() > 0 && _animals.size() > 0) {
        nameList[_adopters[a]] = _animals[a]->getName();
        _animals.erase(_animals.begin() + a);
        _adopters.erase(_adopters.begin() + a);
    }
}

void Shelter::earnDonation(int amount)
{
    _budget += amount;
    std::cout << "The shelter's budget is:" << _budget << " dollars." << std::endl;
}
