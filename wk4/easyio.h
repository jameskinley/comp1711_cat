#ifndef EASYIO_H
#define EASYIO_H

#include <stdlib.h>
#include <stdio.h>

FILE* open_file(char filename[], char mode[])
{
    FILE *file = fopen(filename, mode);

    if(file == NULL)
    {
        perror("");
        exit(1);
    }
}

#endif
