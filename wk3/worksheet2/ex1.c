#include <stdio.h>
#include <math.h>

#define PI 3.14

float circleArea(float radius)
{
    return PI * pow(radius, 2.0);
}

int main()
{
    float radius;
    printf("Enter circle radius : ");
    scanf("%f", &radius);

    printf("Circle with radius of %f has area %f", radius, circleArea(radius));

    return 0;
}