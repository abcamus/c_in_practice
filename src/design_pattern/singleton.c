#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "singleton.h"
#include "log.h"

#define TEST_NAME "TEST_SINGLETON\n"

/**
 * @brief 单例模式
 *
 * 1. 受控访问HouseKeeper实例；
 * 2. 是对全局变量的一种改进，避免单一实例的全局变量污染命名空间
 *
 */
static HouseKeeper *_h = NULL;

static void take_a_rest(unsigned time)
{
    if (_h == NULL) {
        return;
    }

    _h->rest_time += time;;
    INFO("have a rest\n");
}

HouseKeeper *single_house_keeper()
{
    if (_h == NULL) {
        _h = (HouseKeeper *)malloc(sizeof(HouseKeeper));
        _h->rest_time = 0;
        _h->take_rest = take_a_rest;
    }

    return _h;
}

void delete_single_house()
{
    if (_h) {
        printf("delete, rest_time = %d\n", _h->rest_time);
        free(_h);
        _h = NULL;
    }
}

void test_singleton()
{
    HouseKeeper *h = single_house_keeper();

    h->take_rest(10);

    delete_single_house();
}