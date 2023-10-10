#include <stdio.h>

int main()
{
    int number;

    printf("Input number: ");
    scanf("%d", &number);

    int factorial = 1;

    for (int i = 0; i < number; i++)
    {
        factorial = factorial * (i + 1);
    }

    printf("%d! = %d", number, factorial);

    return 0;
}