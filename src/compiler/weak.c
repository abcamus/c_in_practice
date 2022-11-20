#include <stdio.h>

void __attribute__((weak)) foo()
{
    printf("weak\n");
}