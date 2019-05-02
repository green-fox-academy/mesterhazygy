#include <iostream>
#include <vector>
#include "Printer.h"
#include "Printer2D.h"
#include "Printer3D.h"
#include "Scanner.h"
#include "Copier.h"

int main()
{
    Printer3D printer3d(10, 32, 21);
    Printer2D printer1(31, 121);
    Printer2D printer2(32, 322);
    Printer2D printer3(43, 12);
    Scanner scanner(100);
    Copier copier(10, 32, 323);
    std::vector<Printer*> myPrinters;
    myPrinters.push_back(&printer1);
    myPrinters.push_back(&printer2);
    myPrinters.push_back(&printer3);
    for (int i = 0; i < myPrinters.size(); ++i) {
        myPrinters[i]->print();
    }

    return 0;
}