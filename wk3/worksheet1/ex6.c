#include <stdio.h>

void renderMenu()
{
    printf("<================================>\n1 -> Option 1\n2 -> Option 2\n3 -> Option 3\n4 -> Option 4\n5 -> Quit\n\nEnter selection (1 - 5) > ");
}

int takeInput()
{   
    int input;
    scanf("%d", &input);
    return input;
}

int main()
{
    int input = 0;

    while (input != -1)
    {
        printf("\nEnter input -> ");
        input = takeInput();
        if(input > 0 && input < 100)
        {
            printf("\nInput '%d' in range\n", input);
        }
        else if(input == -1)
        {
            printf("\nTermination value of -1 entered, shutting down.\n");
        }
        else
        {
            printf("\nInput %d invalid- not in range\n", input);
        }
    }   

    return 0;
}