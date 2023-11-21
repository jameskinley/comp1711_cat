#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char filename[100];
FITNESS_DATA *fitnessData;
int fileLength;
short terminate = 0;
short errored = 0;

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
    printf("Input filename: ");
    scanf("%s", filename);
}

void executeInstruction(const char command)
{
    FITNESS_DATA temp1, temp2;

    switch (command)
    {
    case 'A':
        getFileName();
        fitnessData = loadFile(filename, &fileLength);

        if (fitnessData == NULL)
        {
            printf("Error: Could not find or open the file.\n");
            terminate = 1;
            errored = 1;
        }
        else
        {
            printf("File successfully loaded.");
        }
        break;

    case 'B':
        printf("Total records: %d", fileLength);
        break;

    case 'C':
        temp1 = getFewestSteps(fitnessData, fileLength);
        printf("Fewest steps: %s %s", temp1.date, temp1.time);
        break;

    case 'D':
        temp1 = getMostSteps(fitnessData, fileLength);
        printf("Largest steps: %s %s", temp1.date, temp1.time);
        break;

    case 'E':
        printf("Mean step count: %d", getMeanStepCount(fitnessData, fileLength));
        break;

    case 'F':
        getLongestFiveHunPeriod(fitnessData, fileLength);
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

    if(errored == 1)
    {
        return 1;
    }

    return 0;
}
