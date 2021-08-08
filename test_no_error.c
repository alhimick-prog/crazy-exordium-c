/* This is not a program, this is an error display test. */
/* This code compiles but gives an error. */
#include <stdio.h>
int main()
{
    char str[]="Hello";
    str[4]=0;
    printf(str);
    return 0;
}
