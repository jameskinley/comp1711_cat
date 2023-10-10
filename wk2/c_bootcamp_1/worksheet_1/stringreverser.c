#include <stdio.h>
#include <string.h>

int main()
{
    char input[10];
    char output[10];

    printf("Enter a word: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++)
    {
        output[i] = input[strlen(input) - i - 1];
    }
    
    printf("\nOutput : %s\n", output);

    return 0;
}