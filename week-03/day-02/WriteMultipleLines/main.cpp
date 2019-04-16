#include <iostream>
#include <fstream>

int writerFunc(std::string, std::string, int);

int main()
{
    int rows = 5;
    std::string path = "../mytext.txt";
    std::string word = "lol";
    std::cout << writerFunc(path, word, rows) << std::endl;
    return 0;
}

int writerFunc(std::string path, std::string word, int rows)
{
    std::ofstream myFile;
    myFile.open(path);
    for (int i = 0; i < rows; i++) {
        myFile << word << std::endl;
        }
    myFile.close();
    return 0;
}