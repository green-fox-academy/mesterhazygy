#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string();

char *repeater(char *, int);

int main()
{
    int userNum;
    printf("Give me a word!\n");
    char *string = read_string();
    printf("give me a number!!\n");
    scanf("%d", &userNum);
    char *result = repeater(string, userNum);
    printf("%s\n", result);
    free(string);
    free(result);
    string = NULL;
    result = NULL;
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

char *repeater(char *string, int userNum)
{
    char *result=(char *)malloc(strlen(string) * userNum + 1);
    strcpy(result, string);
    for (int i = 0; i < userNum - 1; ++i) {
        strcat(result, string);
    }
    return result;
}