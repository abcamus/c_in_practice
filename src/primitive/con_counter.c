#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
// #include <sys/syscall.h>

static int count = 0;
static int loop = 0;

void *worker(void *args)
{
    for (int i = 0; i < loop; i++) {
        count++;
        // printf("tid: %d; count: %d\n", gettid(), count);
        /* 等待1秒 */
        // sleep(1);
    }

    return NULL;
}

#define THREAD_NUM 4

int main(int argc, char const *argv[])
{
    pthread_t pid1, pid2;

    if (argc < 2) {
        printf("usage thread [loop_count]");
        exit(0);
    }
    printf("initial count: %d\n", count);

    for (int i = 0; i < THREAD_NUM; i++) {
        (void)pthread_create(&pid1, NULL, worker, NULL);
        (void)pthread_create(&pid2, NULL, worker, NULL);
    }

    /* body */

    for (int i = 0; i < THREAD_NUM; i++) {
        pthread_join(pid1, NULL);
        pthread_join(pid2, NULL);
    }

    printf("final count: %d\n", count);

    return 0;
}
