# Functions + Role in modular programming

## atoi(char* string) - convert string to integer
## functions must be declared **before** they're used in C
## basic function declaration:
<code>[dtype] function([args])
{
    //code
    return x;
}</code>

## *function declaration* / *function prototype* - C allows us to declare a function without the 'payload' - ie:
<code>
int thisIsAFunction(float a);
</code>

## Format specifiers - decimals places: `Can use %{padding}.{decimal places}f`

## Header files
### Use file in default system directory -> #include <file.h>
### Use file in source code directory -> #include "file.h"