#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 1024
#define TRUE 1
#define FALSE 0

char filename[100];
int filelength;

typedef short bool;

// Define the struct for the fitness data
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FitnessData;

short checkCorrectNumFields(char line[BUFFER_LENGTH])
{
    int i = 0;
    int numFields = 0;
    while(i < BUFFER_LENGTH && line[i] != '\0')
    {
        if(line[i] == ',') numFields++;
    }

    // return 1 (TRUE) if there are exactly 3 fields (2 separators)
    if((numFields) == 2)
    {
        return 1;
    }
    return 0;
}

bool checkNoMissingFields(char line[BUFFER_LENGTH])
{
    int i = 1;
    short missingFields = FALSE;
    while(missingFields == 0 && i < BUFFER_LENGTH && line[i] != '\0')
    {
        if(line[i] == ',' && line[i - 1] == ',') 
            missingFields = TRUE;
    }
    return missingFields;
}

bool checkRowValid(char line[BUFFER_LENGTH])
{
    if(
        checkCorrectNumFields(line) == TRUE && 
        checkNoMissingFields(line) == TRUE)
        return TRUE;
    
    return FALSE;
}

bool isValidNumber(char *stepToken)
{
    //atoi returns 0 if string cannot be converted
    int tempStemps = atoi(stepToken);

    if(stepToken[0] == '0' || tempStemps != 0)
    {
        return TRUE;
    }
    return FALSE;
}

bool isValidDate(char *dateToken)
{
    int i = 0;
    int foundHyphens = 0;

    while(foundHyphens != 2 && dateToken[i] != '\0')
    {
        if(dateToken[i] == '-')
        {
            foundHyphens++;
        }
    }

    if(foundHyphens == 2) return TRUE;
    
    return FALSE;
}

bool isValidTime(char *timeToken)
{
    int i = 0;
    bool foundSplit = FALSE;
    while(foundSplit == FALSE && timeToken[i] != '\0')
    {
        if(timeToken[i] == ':') foundSplit == TRUE;
    }
    return foundSplit;
}

// Function to tokenize a record
bool tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps)
{
    if(checkRowValid(record) == FALSE) return FALSE;

    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL)
    {
        if(isValidDate(ptr) == FALSE) return FALSE;

        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL)
        {
            if(isValidTime(ptr) == FALSE) return FALSE;

            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL)
            {
                if(isValidNumber(ptr) == FALSE) return FALSE;

                *steps = atoi(ptr);
                return TRUE;
            }
        }
    }

    return FALSE;
}

// Helper function to utilise the 'tokeniseRecord' function to populate a FitnessData struct.
FitnessData toFitnessData(char line[BUFFER_LENGTH])
{
    FitnessData data;
    malloc(sizeof(FitnessData));

    if(tokeniseRecord(line, ',', data.date, data.time, &data.steps) == TRUE) 
        return data;

    data.steps = -1;

    return data;
}

// allocates the required memory for the a given file.
// learnt from: https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
// https://stackoverflow.com/questions/28931034/how-to-correctly-allocate-memory-for-an-array-of-structs-in-c
FitnessData *allocateFitnessDataMemory(FILE *fileStream)
{
    char buffer[BUFFER_LENGTH];
    int size = 0;

    while (fgets(buffer, BUFFER_LENGTH, fileStream))
    {
        size++;
    }
    fseek(fileStream, 0L, SEEK_SET);

    FitnessData *array = malloc(size * sizeof(FitnessData));
    return array;
}

FitnessData *loadFile(const char *fileName, int *length)
{
    FILE *stream;

    if ((stream = fopen(fileName, "r")))
    {
        FitnessData *data = allocateFitnessDataMemory(stream);

        char buffer[BUFFER_LENGTH];
        int lineNum = 0;

        while (fgets(buffer, BUFFER_LENGTH, stream))
        {
            data[lineNum] = toFitnessData(buffer);

            if(data[lineNum].steps == -1)
            {
                return NULL;
            }

            lineNum++;
        }

        fclose(stream);
        *length = lineNum;
        return data;
    }

    return NULL;
}

FitnessData *bubbleSort(FitnessData *loadedData, const int length)
{
    for (int i = 0; i < length; i++)
    {
        short swapped = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (loadedData[j].steps > loadedData[j + 1].steps)
            {
                FitnessData tempSteps = loadedData[j + 1];
                loadedData[j + 1] = loadedData[j];
                loadedData[j] = tempSteps;
                swapped = 1;
            }
        }

        if (swapped = 0)
        {
            break;
        }
    }
    return loadedData;
}

void getFileName()
{
    printf("\nEnter Filename: ");
    scanf("%s ", filename);
}

void writeToTsv(FitnessData *data)
{
    FILE *fileStream = fopen(strcat(filename, ".tsv"), "w");

    for (int i = 0; i < filelength; i++)
    {
        if (i == filelength - 1)
        {
            fprintf(fileStream, "%s\t%s\t%d", data[filelength - i - 1].date, data[filelength - i - 1].time, data[filelength - i - 1].steps);
        }
        else
        {
            fprintf(fileStream, "%s\t%s\t%d\n", data[filelength - i - 1].date, data[filelength - i - 1].time, data[filelength - i - 1].steps);
        }
    }

    fclose(fileStream);
}

int main()
{
    getFileName();
    FitnessData *data = loadFile(filename, &filelength);

    if (data != NULL)
    {
        data = bubbleSort(data, filelength);
        writeToTsv(data);
        printf("Data sorted and written to %s\n", filename);
        return 0;
    }

    printf("Error : invalid file\n");
    return 1;
}