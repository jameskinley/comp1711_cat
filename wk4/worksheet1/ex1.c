#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("squares.dat", "w");
    int n;

    printf("Enter a positive integer n > ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        fprintf(file, "%d\n", (i * i));
    }

    fclose(file);

    return 0;
}