#include <stdio.h>

int main()
{
    float side1;
    float side2;

    printf("Enter side one length: ");
    scanf("%f", &side1);

    printf("Enter side two length: ");
    scanf("%f", &side2);

    printf("Rectangle length : %f\n", side1 * side2);

    return 0;
}