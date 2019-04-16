#include <iostream>
#include <fstream>

int main()
{
    std::ofstream myFile;
    myFile.open("../my-file.txt");
    myFile << "Mesterházy Győző";
    myFile.close();

    return 0;
}