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

void executeInstruction(const char command)
{
    switch (command)
    {
        case 'A':
            fitnessData = loadFile("FitnessData_2023.csv", fileLength);
            executeInstruction(getOption());
            break;
            
        case 'B':
            printf("Total records: %d", fileLength);
            break;

        case 'C':
            break;
        case 'D':
            break;
        case 'F':
            break;
        default:
            break;
    }
}

// Complete the main function
int main()
{
    executeInstruction(getOption());
    return 0;
}
