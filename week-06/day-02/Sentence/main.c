#include <stdio.h>
#include <string.h>

int main()
{
    char string[256] = "Ez egy nagyon nagyon hosszu mondat jeee";
    char *word = strtok(string, " ");
    while(word != NULL){
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
    return 0;
}