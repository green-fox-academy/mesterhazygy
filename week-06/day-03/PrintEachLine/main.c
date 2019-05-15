#include <stdio.h>

int main()
{
    FILE *file = fopen("../myText.txt", "r");

    if (file == NULL) {
        printf("Unable to open file");
    } else {
        char buffer[100];
        while (fgets(buffer, 100, file) != NULL) {
            fprintf(stdout, "%s", buffer);
        }
    }
    fclose(file);
    return 0;
}