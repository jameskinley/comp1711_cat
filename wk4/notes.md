# Reading + Writing files

## fopen([filename], [mode]); `Returns FILE pointer`

## Modes:
- r : Read from file
- w : Write to file - create if needed
- a : Append to file - create if needed
### Mode+
- r+ : Read & write, from beginning
- w+ : Read & write, overwriting
- a+ : Read & write, appending

## fclose([file]) - `Close the file off - always do before returning`

## fprintf([file], [string], [variables])

## fgets(char[line_buffer], int[buffer_size], [file]) = `Read from file - outputs line contents to [line_buffer] and returns TRUE when can read`

## perror([error]) - `Output an error`

## atoi(char[]) - `ascii to integer`
## atof(char[]) - `ascii to float`

# Header files
## Compile with: `gcc headerfile.h mainfile.c -o outputfile.exes`
## Can use `#ifndef UTILS_H #define UTILS_H (code) #endif /* UTILS_H */`
### Header files often only have forward declarations for functions - we can supply definitions in separate files.