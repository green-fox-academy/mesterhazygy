#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string decryptText(std::string fileName);

int main()
{
    std::string fileName = "../doublechars.txt";
    std::ifstream myFile;
    decryptText(fileName);

    return 0;
}

std::string decryptText(std::string fileName)
{
    std::ifstream myFile;
    std::string newText;
    myFile.exceptions(std::ifstream::badbit);
    try {
        myFile.open(fileName);
        std::string line;
        while(std::getline(myFile, line)) {
            std::istringstream ss(line);
            std::string word;
            while(std::getline(ss, word,' ')) {
                for (int i = 0; i < word.length(); i++){
                    word.erase(i, 1);
                }
                newText += word + " ";
            }
        }
        myFile.close();
    } catch (std::fstream::failure& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << newText << std::endl;
    return newText;
}