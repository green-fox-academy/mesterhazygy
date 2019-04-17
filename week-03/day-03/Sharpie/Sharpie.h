//
// Created by megha on 2019. 04. 17..
//

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H
#include <iostream>


class Sharpie {
public:
    Sharpie(const std::string &color, float width, float inkAmount);

    Sharpie(const std::string &color, float width);

    const std::string &getColor() const;

    float getWidth() const;

    float getInkAmount() const;

    void use();

private:
    std::string _color;
    float _width;
    float _inkAmount;
};


#endif //SHARPIE_SHARPIE_H
