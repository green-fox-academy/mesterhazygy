#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Mentor.h"

int main()
{
    Person pista("Pista", 235, MALE);
    Mentor janeDoe;
    Mentor gyula("Gyula", 23, MALE, JUNIOR);

    janeDoe.introduce();

    return 0;
}