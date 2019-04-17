//
// Created by megha on 2019. 04. 17..
//

#ifndef ANIMALS_ANIMAL_H
#define ANIMALS_ANIMAL_H


class Animal {
public:
    Animal(int thirst, int hunger);

    void setThirst(int thirst);

    void setHunger(int hunger);

    int getThirst() const;

    int getHunger() const;

    void eat();
    void drink();
    void play();

private:
    int _thirst;
    int _hunger;

};


#endif //ANIMALS_ANIMAL_H
