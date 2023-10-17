#include <stdio.h>

short tempInRange(int temperature)
{
    if(temperature > -10 && temperature < 40)
    {
        return 1;
    }
    
    return 0;
}

int main()
{
    int input;

    printf("Enter a temperature: ");
    scanf("%d", &input);


    switch (tempInRange(input))
    {
    case 1:
        printf("Temperature %d is in range -10 to 40 celsius.", input);
        break;

    default:
        printf("Temperature %d is not in range -10 to 40 celsius.", input);
        break;
    }


    return 0;
}