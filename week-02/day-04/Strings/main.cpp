#include <iostream>
#include <string>

std::string myString(std::string);

int main()
{
    std::string word;
    std::cout << "give me a word" << std::endl;
    std::cin >> word;
    std::cout << myString(word) << std::endl;


    return 0;
}

std::string myString(std::string word)
{
    if (word.size() == 0){
        return "";
    }
    if (word.at(word.length()-1) == 'x'){
        word.replace(word.length()-1, 1, "y");
    }
    char lastCharacter = word.at(word.length()-1);
    word.pop_back();
    return myString(word) + lastCharacter;
}