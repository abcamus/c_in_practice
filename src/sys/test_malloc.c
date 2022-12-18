#include <stdio.h>
#include "dlmalloc.h"

int main(int argc, char const *argv[])
{
    char *f = dlmalloc(12);
    dlfree(f);

    return 0;
}
