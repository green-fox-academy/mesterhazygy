#include <iostream>

class PostIt {
public:
    const std::string &getBackGroundColor() const
    {
        return _backGroundColor;
    }

    const std::string &getText() const
    {
        return _text;
    }

    const std::string &getTextColor() const
    {
        return _textColor;
    }

    PostIt(const std::string &backGroundColor, const std::string &text, const std::string &textColor)
            : _backGroundColor(
            backGroundColor), _text(text), _textColor(textColor)
    {
        _backGroundColor = backGroundColor;
        _text = text;
        _textColor = textColor;
    }

private:
    std::string _backGroundColor;
    std::string _text;
    std::string _textColor;
};

int main()
{
    PostIt postIt1("orange", "Idea 1", "blue");
    PostIt postIt2("pink", "Awesome", "black");
    PostIt postIt3("yellow", "Superb", "green");

    std::cout << postIt1.getTextColor() << std::endl;
    return 0;
}