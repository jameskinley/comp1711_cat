# C Bootcamp 1

## Compile command - `gcc <filename.c> -o ./output (optional) -lm (loads math lib)`
## Standard IO Lib - `stdio.h`
## 'Main' function returns int error code (unlike C# doing this automatically for us)

## String formatting wildcards
%d - Integer
%s - String
%c - Single Char
%f - Float / Double
%ld - Decimal
%p - pointer

You can add padding via %[num spaces][wildcard]

## Variable declaration - same as C#!

## printf = output
## scanf = input - `scanf("<wildcard indicating datatype", &<variable>)` - '&' in this context means 'memory address of'

## library `string.h` includes string related methods such as strlen() which does what it sounds like it does

## sizeof(array) / sizeof(array[0]) = Array.Length

## for loop - exact same as C#

## strcmp() - returns 0 if equal, 1 if not

## Pointers - &var `Give address of var` , *(var) `give value at this mem location` 