#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("squares.dat", "r");
    float sum = 0.0;
    int i = 0;

    int buffer = 100;
    char line[buffer];

    while(fgets(line, buffer, file))
    {
        sum += atoi(line);
        i++;
    }

    fclose(file);

    printf("Average num : %.2f\n", (sum / (float)i));

    return 0;
}