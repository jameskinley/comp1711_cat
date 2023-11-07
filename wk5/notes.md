## `unsigned` - best data type to use for unsigned ints
## Generally, using `strcopy(var, "string")` is good practice

## non-typedef struct:
<code>
struct student
{
    char name[20];
    char studentId[11];
    unsigned mark;
}
</code>

## Declare like this:
<code>
struct student new_student
</code>

## Randomness:
Can use <code>rand()</code> (stdlib.h) however if this is not seeded via <code>srand(time(null))</code> (time.h) it will produce the same numbers per runtime.