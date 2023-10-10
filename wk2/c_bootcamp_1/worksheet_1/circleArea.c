#include <stdio.h>
#include <math.h>

double circleArea(double radius)
{
    double pi = 3.14;
    return pi * pow(radius, 2);
}

int main()
{
    double radius;

    printf("Input circle radius: ");
    scanf("%lf", &radius);

    double area = circleArea(radius);

    printf("Area of circle = %lf\n", area);

    return 0;
}