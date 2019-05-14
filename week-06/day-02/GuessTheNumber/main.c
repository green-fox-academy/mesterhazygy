#include <stdio.h>

int main()
{
    int numToGuess = 13;
    int guessNum;
    printf("I have a number, guess!\n");
    while (guessNum != numToGuess) {
        scanf("%d", &guessNum);
        if (numToGuess > guessNum) {
            printf("My number is higher than that, guess again!\n");
        }
        if (numToGuess < guessNum) {
            printf("My number is lower than that, guess again! \n");
        }
    }
    if(guessNum == numToGuess)
        printf("That's correct!\n");
    return 0;
}