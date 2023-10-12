#include <stdio.h>

int main()
{
    int array[5] = {10, 22, 234, 12, 10};

    int max = -__INT32_MAX__;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < arrayLength; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }

    printf("Max value in the array: %d\n", max);
    return 0;
}