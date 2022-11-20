#include <stdio.h>

#include "factory.h"

static void benz_body_paint() {
    printf("%s, %d\n", __func__, __LINE__);
}

static Body *benz_create_body()
{
    static Body benz_body = {
        .paint = benz_body_paint
    };

    return &benz_body;
}

static void benz_window_open() {
    printf("%s, %d\n", __func__, __LINE__);
}

static Window *benz_create_window()
{
    static Window benz_window = {
        .open = benz_window_open
    };

    return &benz_window;
}

static CarFactory benz_factory = {
    .create_body = benz_create_body,
    .create_window = benz_create_window,
};

CarFactory *get_benz_factory()
{
    return &benz_factory;
}