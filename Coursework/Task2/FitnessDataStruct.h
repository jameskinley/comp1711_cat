
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Define an appropriate struct
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

void executeInstruction(const char command);

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

// Helper function to utilise the 'tokeniseRecord' function to populate a FITNESS_DATA struct.
FITNESS_DATA toFitnessData(char line[1024])
{
    FITNESS_DATA data;
    char tempSteps[10];

    tokeniseRecord(line, ",", data.date, data.time, tempSteps);

    // cast the tempSteps to an integer
    data.steps = atoi(tempSteps);

    return data;
}

// allocates the required memory for the a given file.
// learnt from: https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
// https://stackoverflow.com/questions/28931034/how-to-correctly-allocate-memory-for-an-array-of-structs-in-c
FITNESS_DATA *allocateFitnessDataMemory(FILE *fileStream)
{
    char buffer[1024];
    int size = 0;

    while (fgets(buffer, 1024, fileStream))
    {
        size++;
    }
    fseek(fileStream, 0L, SEEK_SET);

    FITNESS_DATA *array = malloc(size * sizeof(FITNESS_DATA));
    return array;
}

FITNESS_DATA *loadFile(const char *fileName, int *length)
{
    FILE *fileStream;

    if ((fileStream = fopen(fileName, "r")))
    {
        FITNESS_DATA *data = allocateFitnessDataMemory(fileStream);

        char buffer[1024];
        int lineNum = 0;

        while (fgets(buffer, 1024, fileStream))
        {
            data[lineNum] = toFitnessData(buffer);
            lineNum++;
        }

        fclose(fileStream);
        *length = lineNum;
        return data;
    }
    return NULL;
}

FITNESS_DATA getFewestSteps(FITNESS_DATA *array, int length)
{
    int fewest = INT_MAX;
    FITNESS_DATA fewestData;

    for (int i = 0; i < length; i++)
    {
        if (array[i].steps < fewest)
        {
            fewest = array[i].steps;
            fewestData = array[i];
        }
    }

    return fewestData;
}

FITNESS_DATA getMostSteps(FITNESS_DATA *array, int length)
{
    int max = -1;
    FITNESS_DATA maxData;

    for (int i = 0; i < length; i++)
    {
        if (array[i].steps > max)
        {
            max = array[i].steps;
            maxData = array[i];
        }
    }

    return maxData;
}

int roundFloat(float input)
{
    return (int) (input + 0.5); //way to deal with int. truncation without using math.h (thank you gradescope for not letting us use it)
}

int getMeanStepCount(FITNESS_DATA *array, const int length)
{
    int mean = 0;

    for (int i = 0; i < length; i++)
    {
        mean += array[i].steps;
    }
    
    return roundFloat((float)mean / (float)length);
}

void getLongestFiveHunPeriod(const FITNESS_DATA *array, const int length)
{
    FITNESS_DATA start, end;

    short foundPeriod = -1;
    int currentPeriodLength = 0;
    int maxPeriodLength = -1;

    for (int i = 0; i < length; i++)
    {
        if(foundPeriod == -1 && array[i].steps > 500)
        {
            foundPeriod = i;
            currentPeriodLength = 1;
        }
        else if(array[i].steps > 500)
        {
            currentPeriodLength++;
        }
        else if(foundPeriod != -1)
        {
            if(currentPeriodLength > maxPeriodLength)
            {
                maxPeriodLength = currentPeriodLength;
                start = array[foundPeriod];
                end = array[i - 1];
            }
            foundPeriod = -1;
            currentPeriodLength = 0;
        }
    }
    printf("Longest period start: %s %s\nLongest period end: %s %s", start.date, start.time, end.date, end.time);
}

void renderMenu()
{
    printf("\nMenu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\nEnter choice: ");
}

char getOption()
{
    char option = '0';
    while ((int)option != 81 && ((int)option < 65 || (int)option > 70))
    {
        renderMenu();
        scanf(" %c", &option);
        option = (char)toupper((int)option);

        if ((int)option != 81 && ((int)option < 65 || (int)option > 70))
        {
            printf("Invalid choice. Try again.");
        }
    }

    return option;
}

#endif // FITNESS_DATA_STRUCT_H