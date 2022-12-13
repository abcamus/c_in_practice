#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define PRINT_ARRAY(array, num) \
    for (int i = 0; (i < num) || (printf("\n") && false); print(&array[i]),i++)

#define SWAP(a, b)      \
    do {                \
        int _temp = a;  \
        a = b;          \
        b = _temp;      \
    } while (0)

#define SWAP_GENERIC(a, b, size)        \
    do {                                \
        char _temp[128];               \
        memcpy(_temp, a, size);         \
        memcpy(a, b, size);             \
        memcpy(b, _temp, size);         \
    } while (0)

bool compare_ascend(int a, int b)
{
    return a > b;
}

bool compare_descend(int a, int b)
{
    return a < b;
}

bool compare_int_ascend(const void *_a, const void *_b)
{
    return *(int *)_a > *(int *)_b;
}


typedef struct {
    int score;
    char *name;
} Student;

/**
 * @brief 按照成绩从高到低排序，同样的成绩按照名字字典顺序排序
 *
 * @param _a
 * @param _b
 * @return true
 * @return false
 */
bool compare_descend_generic(const void *_a, const void *_b)
{
    const Student *a = (const Student *)_a;
    const Student *b = (const Student *)_b;

    return (a->score == b->score && strcmp(a->name, b->name)) ||
           (a->score < b->score);
}

void bubble_sort3(void *data, int size, int num,
                  bool (*compare)(const void *, const void *))
{
    int i, j;
    uint8_t *oprand1, *oprand2;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            oprand1 = (uint8_t *)data + j * size;
            oprand2 = (uint8_t *)data + (j + 1) * size;
            if (compare(oprand1, oprand2)) {
                SWAP_GENERIC(oprand1, oprand2, size);
            }
        }
    }
}

/**
 * @brief 能兼容递增和递减排序
 *
 * @param data
 * @param num
 * @param compare
 */
void bubble_sort2(int *data, int num,
                  bool (*compare)(int, int))
{
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (compare(data[j], data[j+1])) {
                SWAP(data[j], data[j+1]);
            }
        }
    }
}

void bubble_sort1(int *data, int num)
{
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (data[j] > data[j+1]) {
                SWAP(data[j], data[j+1]);
            }
        }
    }
}

void bubble_sort(int *data, int num)
{
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void print(Student *s)
{
    printf("grade : %d, name : %s\n", s->score, s->name);
}

int main(int argc, char const *argv[])
{
    int array[128] = { 5, 4, 2, 1, 3};
    int num = 5;

    Student data[5] = {
        {
            .score = 100,
            .name = "alice",
        },
        {
            .score = 90,
            .name = "GGG",
        },
        {
            .score = 90,
            .name = "FFF",
        }
    };

    num = 3;

    // bubble_sort(array, num - 1);
    // bubble_sort1(array, num - 1);
    // bubble_sort2(array, num, compare_ascend);
    // bubble_sort2(array, num, compare_descend);
    bubble_sort3(data, sizeof(Student), num, compare_descend_generic);
    PRINT_ARRAY(data, num);

    bubble_sort3(array, sizeof(int), 5, compare_int_ascend);
    for (int i = 0; (i < 5) || (printf("\n") && false);
         printf("%d ", array[i]),i++);

    return 0;
}
