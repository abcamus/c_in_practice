#include <stdbool.h>

/**
 * @file iterator.c
 * @author your name (you@domain.com)
 * @brief 提供一种方法顺序访问一个聚合对象中的各个元素，而不需要暴露该对象的内部表示
 * 有名游标，cursor
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

typedef struct {
    void *list;
    void *(*first)(void *self);
    void *(*next)(void *self);
    bool (*is_done)(void *self);
    void *(*current_item)(void *self);
} Iterator;