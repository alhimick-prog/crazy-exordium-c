#include <stdio.h>
int main()
{
    char *ptr = "Hello";
    ptr[4]=0;
    for(; *ptr; ptr++)
        printf(*ptr);
    return 0;
}
