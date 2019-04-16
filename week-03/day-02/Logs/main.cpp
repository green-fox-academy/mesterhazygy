#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> uniqueIP(std::string);
float getPost(std::string);

int main()
{
    std::vector<std::string> ipVector = uniqueIP("../logs.txt");
    for (int j = 0; j < ipVector.size(); j++) {
        std::cout << ipVector[j] << std::endl;
    }
    std::cout << getPost("../logs.txt") << std::endl;
    return 0;
}

std::vector<std::string> uniqueIP(std::string fileName)
{
    std::ifstream myLogs("../logs.txt");
    std::string addresses;
    std::vector<std::string> ipAddresses;

    while (getline(myLogs, addresses)) {
        std::istringstream addr(addresses);
        std::string IP;
        int counter = 0;
        while (getline(addr, IP, ' ')) {
            counter++;
            if (counter == 9) {
                ipAddresses.push_back(IP);
            }
        }
    }
    std::sort(ipAddresses.begin(), ipAddresses.end());
    auto last = std::unique(ipAddresses.begin(), ipAddresses.end());
    ipAddresses.erase(last, ipAddresses.end());
    return ipAddresses;
}

float getPost (std::string)
{
    std::ifstream myLogs("../logs.txt");
    std::string lines;
    float getCounter = 0;
    float posCounter = 0;
    while (getline(myLogs, lines)) {
        if (lines.find("GET") != std::string::npos) {
            getCounter++;
        }
        if (lines.find("POST") != std::string::npos) {
            posCounter++;
        }
    }
    float c = getCounter/posCounter;
    return c;
}