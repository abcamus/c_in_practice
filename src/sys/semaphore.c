#include <stdlib.h>

typedef void * sem_t;

#define MAX 1

int buffer[MAX];
int fill = 0;
int use  = 0;

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
}

int get() {
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    return tmp;
}

sem_t empty;
sem_t full;

void *producer(void *arg)
{
    return NULL;
}

void *consumer(void *arg)
{
    return NULL;
}

void sem_init(sem_t *sem, int value, int num)
{

}

int test_semaphore(int argc, char *argv[])
{
    sem_init(&empty, 0, MAX);
    sem_init(&full, 0, 0);

    return 0;
}