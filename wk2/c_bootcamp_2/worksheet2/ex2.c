#include <stdio.h>

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int reversedArray[5];

    int length = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < length; i++)
    {
        reversedArray[i] = array[length - i - 1];
    }

    printf("Initial array :\n");

    for (int i = 0; i < length; i++)
    {
        printf("%d, ", array[i]);
    }

    printf("\nReversed array:\n");

    for (int i = 0; i < length; i++)
    {
        printf("%d, ", reversedArray[i]);
    }
    
    printf("\n");

    return 0;
}