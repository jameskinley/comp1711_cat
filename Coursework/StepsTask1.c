#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
const char *delimiter = ",";

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);
}

// Helper function to utilise the 'tokeniseRecord' function to populate a FITNESS_DATA struct.
FITNESS_DATA toFitnessData(char line[1024])
{
    FITNESS_DATA data;
    char tempSteps[10];

    tokeniseRecord(line, delimiter, data.date, data.time, tempSteps);

    // cast the tempSteps to an integer
    data.steps = atoi(tempSteps);

    return data;
}

// Complete the main function
int main() 
{
    FILE* fileStream = fopen("FitnessData_2023.csv", "r");
    FITNESS_DATA data[3];

    char buffer[1024];
    int lineNum = 0;

    // Learnt from : https://stackoverflow.com/questions/12911299/read-csv-file-in-c (prior to the C Bootcamp that covered this!)
    while(fgets(buffer, 1024, fileStream))
    {
        // Only store the first 3 lines for the time being
        if(lineNum < 3)
        {
            data[lineNum] = toFitnessData(buffer);
        }

        lineNum++;
    }

    fclose(fileStream);

    printf("Number of records in file: %d\n", lineNum);
    
    //Prints the first 3 rows in the file.
    for (int i = 0; i < 3; i++)
    {
        printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    return 0;
}