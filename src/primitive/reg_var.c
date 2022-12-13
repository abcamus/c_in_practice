#include <stdio.h>
#include <limits.h>

int test_reg_var(int argc, char *argv[])
{
    register int count;
    for (count = 0; count < INT_MAX; count++);

    return 0;
}
