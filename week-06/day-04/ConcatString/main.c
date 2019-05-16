#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string();

char *concatenator(char *, char *);

int main()
{
    printf("Give me a word!\n");
    char *string1 = read_string();
    printf("Give me another word!\n");
    char *string2 = read_string();
    printf("first word is: %s\n", string1);
    printf("second word is: %s\n", string2);
    printf("%s\n", concatenator(string1, string2));
    free(string1);
    free(string2);
    string1 = NULL;
    string2 = NULL;
    return 0;
}

char *read_string()
{
    size_t size = 1;
    char *string = (char *) calloc(sizeof(char), size);
    char c = getc(stdin);
    while (c != '\n') {
        size++;
        string = (char *) realloc(string, size);
        string[size - 2] = c;
        string[size - 1] = '\0';
        c = getc(stdin);
    }
    return string;
}

char *concatenator(char *string1, char *string2)
{
    char *result = (char *) malloc(strlen(string1) + strlen(string2) + 1);
    strcpy(result, string1);
    strcat(result, string2);
    return result;
}