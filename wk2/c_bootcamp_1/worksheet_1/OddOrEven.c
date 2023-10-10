#include <stdio.h>

int main()
{
    int number;

    printf("Input number: ");
    scanf("%d", &number);

    int modResult = number % 2;

    if (modResult == 1)
    {
       printf("Number %d is odd.\n", number);
    }
    else
    {
        printf("Number %d is even.\n", number);
    }

    return 0;
}