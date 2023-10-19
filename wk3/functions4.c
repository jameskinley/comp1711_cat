#include <stdio.h>

float fahr_to_celsius (float f_temp)
{
    float c_temp;
    c_temp = (f_temp - 32)/1.8;
    return c_temp;
}

float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    return k_temp;
}

float fahr_to_newton (float f_temp)
{
    return (f_temp - 32) * (11.0 / 60.0);
}

int main () 
{
    float fahrenheit;
    char option;

    printf ("Enter a temperature to convert in Fahrenheit: ");
    scanf ("%f", &fahrenheit);

    printf ("\n");
    printf ("Select A to convert to Celsius\n");
    printf ("Select B to convert to Kelvin\n");
    printf ("Select C to convert to Newton temperature scale\n");
    printf ("Select Q to quit\n");

    scanf(" %c", &option);

    switch (option)
    {
        case 'A': printf ("Converted to degrees Celsius: %f\n", fahr_to_celsius(fahrenheit));
                  break;

        case 'B': printf ("Converted to Kelvin: %f\n", fahr_to_kelvin(fahrenheit));
                  break;

        case 'C': printf ("Convered to Newton: %f\n", fahr_to_newton(fahrenheit));
                  break;

        case 'Q': break;

        default:  break;
    }

    return 0;
}