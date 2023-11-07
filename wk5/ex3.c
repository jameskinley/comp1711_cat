#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <time.h>
#include "point.h"

double absolute(double value)
{
    if(value < 0)
    {
        return value * -1;
    }
    return value;
}

//using Netwton-Raphson
double sqrt(double value)
{
    double estimate = 1.0;
    double tolerance = 0.001;

    while(absolute(value / estimate - estimate) > tolerance)
    {
        estimate = (estimate + value / estimate) / 2.0;
    }

    return estimate;
}

double square(double value)
{
    return value * value;
}

/* double euclidianDistance(point point1, point point2)
{
    return pow(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2), 0.5);
} */

double euclidianDistance(point point1, point point2)
{
    return sqrt(square(point1.x - point2.x) + square(point1.y - point2.y));
}

double minimumDistance(point points[], int n)
{
    n = n--; //n provided actually n + 1

    double min = __DBL_MAX__;

    for (int i = 0; i < n; i++)
    {
        double distance_temp = euclidianDistance(points[i], points[i+1]);
        if(distance_temp < min)
        {
            min = distance_temp;
        }
    }

    return min;   
}

int main()
{
    point points[500];
    int len = sizeof(points) / sizeof(points[0]);

    srand(time(NULL));

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

    printf("Minimum Euclidian distance of points = %.2f\n", minimumDistance(points, len));

    return 0;
}