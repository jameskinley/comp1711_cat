#include <stdio.h>
#include <string.h>

int main()
{
    char string1[10] = "string";
    char string2[10] = "string";

    printf("Test -> %d", strcmp(string1, string2));

    return 0;
}