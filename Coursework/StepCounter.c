#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char *filename;
FITNESS_DATA *fitnessData;
int fileLength;
short terminate = 0;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

void getFileName()
{
    printf("\nInput filename: ");
    scanf("%s", filename);
}

void executeInstruction(const char command)
{
    switch (command)
    {
    case 'A':
        getFileName();
        fitnessData = loadFile(filename, fileLength);

        if (fitnessData == NULL)
        {
            printf("\nError: Could not find or open the file.");
            terminate = 1;
        }
        else
        {
            printf("\nFile successfully loaded.");
        }
        break;

    case 'B':
        printf("\nTotal records: %d", fileLength);
        break;

    case 'C':
        FITNESS_DATA temp = getFewestSteps(fitnessData, fileLength);
        printf("\nFewest steps: %s %s", temp.date, temp.time);
        break;

    case 'D':
        FITNESS_DATA temp = getMostSteps(fitnessData, fileLength);
        printf("\nLargest steps: %s %s", temp.date, temp.time);
        break;

    case 'E':
        printf("\nMean step count: %d", getMeanStepCount(fitnessData, fileLength));
        break;

    case 'F':
        FITNESS_DATA temp1, temp2;
        getLongestFiveHunPeriod(fitnessData, fileLength, temp1, temp2);
        printf("\nLongest period start: %s %s\nLongest period end: %s %s", temp1.date, temp1.time, temp2.date, temp2.time);
        break;

    default:
        terminate = 1;
        break;
    }
}

// Complete the main function
int main()
{
    while (terminate != 1)
    {
        executeInstruction(getOption());
    }

    return 0;
}
