#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename[100];
int filelength;

// Define the struct for the fitness data
typedef struct
{
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps)
{
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL)
    {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL)
        {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL)
            {
                *steps = atoi(ptr);
            }
        }
    }
}

short checkRowValid(FitnessData fitnessData)
{
    if(fitnessData.date == NULL || fitnessData.date == "" || fitnessData.time == NULL || fitnessData.time == "")
    {
        return 0;
    }
    return 1;
}

// Helper function to utilise the 'tokeniseRecord' function to populate a FitnessData struct.
FitnessData toFitnessData(char line[1024])
{
    FitnessData data;
    malloc(sizeof(FitnessData));

    tokeniseRecord(line, ',', data.date, data.time, &data.steps);

    return data;

    //return NULL;
}

// allocates the required memory for the a given file.
// learnt from: https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
// https://stackoverflow.com/questions/28931034/how-to-correctly-allocate-memory-for-an-array-of-structs-in-c
FitnessData *allocateFitnessDataMemory(FILE *fileStream)
{
    char buffer[1024];
    int size = 0;

    while (fgets(buffer, 1024, fileStream))
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

        char buffer[1024];
        int lineNum = 0;

        while (fgets(buffer, 1024, stream))
        {
            data[lineNum] = toFitnessData(buffer);
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
    scanf("%s", filename);
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