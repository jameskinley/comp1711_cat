#include <stdio.h>
#include <stdlib.h>
#include "point.h"

/* typedef struct point
{
    double x;
    double y;
} point; */

double absolute(double num)
{
    if(num < 0)
    {
        return num * -1;
    }
    return num;
}

double manhattanDistance(point point1, point point2)
{
    return absolute(point1.x - point2.x) + absolute(point1.y - point2.y);
}

double avgManhattanDistance(point points[], int n)
{
    n = n--;
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += manhattanDistance(points[i], points[i+1]);
    }
    
    return sum / (double) (n + 1);
}

int main()
{
    point points[500];
    int len = sizeof(points) / sizeof(points[0]);

    for (int i = 0; i < len; i++)
    {
        point temp_point = 
        {
            .x = rand(),
            .y = rand()
        };

        points[i] = temp_point;

        printf("Point [%02d] : [%15.2f, %15.2f]\n", (i+1), points[i].x, points[i].y);
    }
    
    printf("Average manhattan distance = %15f\n", avgManhattanDistance(points, len));

    return 0;
}