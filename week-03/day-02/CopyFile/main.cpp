#include <iostream>
#include <fstream>

int copyFiles(std::string, std::string);

int main()
{
    std::string fileFrom = "../filetocopy.txt";
    std::string fileTo = "../filetocopyinto.txt";
    std::cout << copyFiles(fileFrom, fileTo) << std::endl;
    std::cout << copyFiles(fileFrom, fileTo) << std::endl;
    return 0;
}

int copyFiles(std::string fileFrom, std::string fileTo)
{
    std::ifstream file1;
    file1.open(fileFrom);
    std::ofstream file2;
    file2.open(fileTo);
    std::string text;
    bool isWorking = true;
    while (isWorking) {
        while (getline(file1, text)) {
            file2 << text << "\n";
        }
        return isWorking;
    }
}