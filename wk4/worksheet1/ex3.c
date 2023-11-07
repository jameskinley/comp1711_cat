#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

short hasLineBreak(char string[], int strLen)
{
    int i = 0;

    while (i < strLen)
    {
        if(string[i] == '\n')
        {
            return 1;
        }

        i++;
    }
    
    return 0;
}

int main()
{
    FILE* file = fopen("numbers.dat", "a+");
    float sum = 0.0;
    int i = 0;

    int buffer = 100;
    char line[buffer];

    while(fgets(line, buffer, file))
    {
        sum += atof(line);
        i++;
    }

    if(hasLineBreak(line, buffer))
    {
        fprintf(file, "%f\n", (sum / (float)i));
    }
    else
    {
        fprintf(file, "\n%f\n", (sum / (float)i));
    }

    fclose(file);

    return 0;
}