#include <stdio.h>
#include <limits.h>

void foo();

void foo()
{
    printf("Good\n");
}

void __attribute__((constructor))init()
{
    printf("%s, %d\n", __func__, __LINE__);
}

void __attribute__((destructor))my_exit()
{
    printf("%s, %d\n", __func__, __LINE__);
}

int main(int argc, char *argv[])
{
    void (*callback)() = foo;
    callback();

    return 0;
}
