#include <iostream>
#include <vector>

class Tree{
    public:
        std::string type;
        std::string color;
        std::string age;
        std::string gender;
        Tree (std::string aType, std::string aColor, std::string aAge, std::string aGender) {
            type = aType;
            color = aColor;
            age = aAge;
            gender = aGender;
        }
};
int main()
{
    Tree tree1("pine", "dark green", "54", "male");
    Tree tree2("maple", "light green", "23", "female");
    Tree tree3("oak", "dark grey", "232", "male");
    Tree tree4("birch", "dark brown", "33", "female");

    /*std::vector<std::string> tree1 = {"pine", "dark green", "54", "male"};
    std::vector<std::string> tree2 = {"maple", "light green", "23", "female"};
    std::vector<std::string> tree3 = {"oak", "green", "232", "male"};
    std::vector<std::string> tree4 = {"birch", "dark grey", "33", "female"};*/
    return 0;
}