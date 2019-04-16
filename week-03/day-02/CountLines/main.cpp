#include <iostream>
#include <fstream>
#include <string>

int rowsNum(std::string);

int main()
{
    std::ifstream myText;
    std::string fileName = "../mytext.txt";
    std::cout << rowsNum(fileName) << std::endl;
    return 0;
}

int rowsNum(std::string fileName)
{
    std::ifstream myText;
    std::string text;
    myText.open(fileName);
    int rows = 0;
    while (!myText.eof()) {
        getline(myText, text);
        rows ++;
    }
    myText.close();
    return rows;
}