#include <stdio.h>

char* getGrade(int mark)
{
    if(mark >= 70)
    {
        return "Passed with distinction";
    }
    else if(mark >= 50)
    {
        return "Passed";
    }
    else
    {
        return "Failed";
    }
}

int main()
{
    int input;

    printf("Enter a mark: ");
    scanf("%d", &input);

    printf("Student has %s with a mark of %d", getGrade(input), input);

    return 0;
}