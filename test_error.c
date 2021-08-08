/* This is not a program, this is an error display test. */
/* This code does not compile because it gives an error. */
#include <stdio.h>
int main()
{
    char *ptr = "Hello";
    ptr[4]=0;
    for(; *ptr; ptr++)
        printf(*ptr);
    return 0;
}
