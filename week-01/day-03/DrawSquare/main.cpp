#include <iostream>

int main() {

    std::cout << "give me a number" << std::endl;
    int usernum;
    std::cin >> usernum;

    for (int i = 0; i < usernum; i++)
    {
        for (int j = 0; j < usernum; j++)
        { if ( i == 0) {                        //elso sor
            std::cout << "%";
        } else if ((i > 0) && (i < usernum))    //koztes sorok
        {
            if (j == 0)                         //elso poziciok
            {
                std::cout << "%";
            } else if (j < usernum){            //koztes poziciok
                std::cout << "0" <<;
            } else {
                std::cout << "%";               //utolso oszlop
            }

        }

        } std::cout << std::endl;
    }

    return 0;
}