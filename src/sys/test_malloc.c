#include <stdio.h>
#include <string.h>
#include "dlmalloc.h"

int main(int argc, char const *argv[])
{
    char *msg = dlmalloc(12);
    memcpy(msg, "hello", 5);
    printf("msg: %s\n", msg);
    dlfree(msg);

    return 0;
}
