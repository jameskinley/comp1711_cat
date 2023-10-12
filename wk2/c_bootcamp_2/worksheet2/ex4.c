#include <stdio.h>

int main()
{
    int array[5] = {1, 2, 3, 4, 5};

    int arrayLength = sizeof(array) / sizeof(array[0]);

    int arrayShifted[5];

    for (int i = 0; i < arrayLength; i++)
    {
        if(i == arrayLength - 1)
        {
            arrayShifted[0] = array[i];
        }
        else
        {
            arrayShifted[i + 1] = array[i];
        }
    } 

    printf("Shifted array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d ", arrayShifted[i]);
    }
    
    printf("\n");

    return 0;
}