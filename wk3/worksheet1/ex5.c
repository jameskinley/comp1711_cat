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

void clearScreen()
{
    printf("\e[1;1H\e[2J");
}

int main()
{
    int input = 0;

    while (input != 5)
    {
        //clearScreen();
        renderMenu();

        switch (input = takeInput())
        {
            case 1:
                printf("\nDoing option 1\n");
                break;
            
            case 2:
                printf("\nDoing option 2\n");
                break;
            
            case 3:
                printf("\nDoing option 3\n");

            case 4:
                printf("\nDoing option 4\n");

            case 5:
                printf("\nQuitting application...\n");
                break;
            
            default:
                printf("\nINVALID INPUT, PLEASE TRY AGAIN!");
                break;
        }
    }

    return 0;
}