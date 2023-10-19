#include <stdio.h>

int main()
{
    int input;

    printf("Enter a number: ");
    scanf("%d", &input);

    if(input > 0)
    {
        printf("The number %d is positive.", input);
    }
    else if(input < 0)
    {
        printf("The number %d is negative.", input);
    }
    else
    {
        printf("The number %d, is of course 0", input);
    }

    return 0;
}