#include <stdio.h>

int counter(char*);

int main()
{
    char fileName[20] = {0};
    printf("What file do u want to open?\n");
    scanf("%s", fileName);
    printf("%d", counter(fileName));
    return 0;
}

int counter(char *fileName)
{
    int counter = 0;
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return 0;
    } else {
        char buffer[100];
        while (fgets(buffer, 100, file) != NULL) {
            counter++;
        }
    }
    fclose(file);
    return counter;
}