#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double x;
    double y;
} point;

int main()
{
    point coordinates[10];

    for (int i = 0; i < 10; i++)
    {
        point tempPoint = {
            .x = rand(),
            .y = rand()
        };
        coordinates[i] = tempPoint;
    }
    
    int pointLen = sizeof(coordinates) / sizeof(coordinates[0]);

    for (int i = 0; i < pointLen; i++)
    {
        printf("%15.2f, %15.2f\n", coordinates[i].x, coordinates[i].y);
    }
    
    return 0;
}