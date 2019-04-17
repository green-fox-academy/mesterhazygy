//
// Created by megha on 2019. 04. 17..
//
#include <iostream>
#include "PostIt.h"

const std::string &PostIt::getBackGroundColor() const
{
    return _backGroundColor;
}

const std::string &PostIt::getText() const
{
    return _text;
}

const std::string &PostIt::getTextColor() const
{
    return _textColor;
}

PostIt::PostIt(const std::string &backGroundColor, const std::string &text, const std::string &textColor){
    _backGroundColor = backGroundColor;
    _text = text;
    _textColor = textColor;
}

