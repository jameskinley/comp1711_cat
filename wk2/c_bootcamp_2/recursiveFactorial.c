#include <stdio.h>

int factorial(int number)
{
    if(number == 0)
    {
        return 1;
    }
    return number * factorial(number - 1);
}

int main()
{
    int fiveFactorial = factorial(5);

    printf("Five factorial : %d\n", fiveFactorial);

    return 0;
}