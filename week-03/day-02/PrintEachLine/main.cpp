#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream myFile;
    myFile.open("../my-file.txt");
    std::string text;
    while (getline(myFile, text)) {
        std::cout << text << std::endl;
    }

    myFile.close();
    return 0;
}