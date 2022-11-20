/**
 * @file abstract_factory.c
 * @author abcamus_dev@163.com
 * @brief 抽象工厂模式
 * @version 0.1
 * @date 2022-04-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdlib.h>
#include "factory.h"

extern CarFactory *get_porsche_factory();
extern CarFactory *get_benz_factory();

CarFactory *get_car_factory(enum CarFactoryType car_type)
{
    switch (car_type)
    {
    case FACTORY_PORSCHE:
        return get_porsche_factory();
    case FACTORY_BENZ:
        return get_benz_factory();
    default:
        break;
    }
    return NULL;
}

void test_abstract_factory()
{
    CarFactory *factory = get_car_factory(FACTORY_PORSCHE);
    Window *window = factory->create_window();
    Body *body = factory->create_body();

    // use windows and body
    window->open();
    body->paint();
}