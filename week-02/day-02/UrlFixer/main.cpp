#include <iostream>
#include <string>

int main() {

    std::string url("https//www.reddit.com/r/nevertellmethebots");
    url.insert(5, ":");
    url.replace(39, 4, "odds");
    std::cout << url << std::endl;

    return 0;
}