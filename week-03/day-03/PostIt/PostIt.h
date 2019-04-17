//
// Created by megha on 2019. 04. 17..
//

#ifndef POSTIT_POSTIT_H
#define POSTIT_POSTIT_H


class PostIt {
public:
    const std::string &getBackGroundColor() const;

    const std::string &getText() const;

    const std::string &getTextColor() const;

    PostIt(const std::string &backGroundColor, const std::string &text, const std::string &textColor);

private:
    std::string _backGroundColor;
    std::string _text;
    std::string _textColor;
};


#endif //POSTIT_POSTIT_H
