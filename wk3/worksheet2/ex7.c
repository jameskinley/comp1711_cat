#include <stdio.h>
#include <stdlib.h>

void reverseArray(int* intArray, const int arrayLength)
{
    int* reversedArray = malloc(arrayLength);
    int *ptr = &intArray[0];

    for (int i = 0; i < arrayLength; i++)
    {
        reversedArray[i] = *(intArray);
    }

    intArray = reversedArray;
}

int main()
{
    int array[] = {1, 3, 5, 7, 9};

    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Original array : \n");

    for (int i = 0; i < arraySize; i++)
    {
        printf("%d, ", array[i]);
    }
    
    printf("\nReversed array : \n");

    reverseArray(array, arraySize);

    for (int i = 0; i < arraySize; i++)
    {
        printf("%d, ", array[i]);
    }

    return 0;
}