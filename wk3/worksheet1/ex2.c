#include <stdio.h>

int main()
{
    int input;

    printf("Enter a number: ");
    scanf("%d", &input);

    if(input % 4 == 0 && input % 5 == 0)
    {
        printf("The number %d is divisible by both 4 & 5.\n", input);
    }
    else
    {
        printf("The number %d is not divisible by both 4 & 5\n", input);
    }

    return 0;
}