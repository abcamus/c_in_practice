#include <stdio.h>

#include "factory.h"

static void porsche_body_paint() {
    printf("%s, %d\n", __func__, __LINE__);
}

static Body *porsche_create_body()
{
    static Body porsche_body = {
        .paint = porsche_body_paint
    };

    return &porsche_body;
}

static void porsche_window_open() {
    printf("%s, %d\n", __func__, __LINE__);
}

static Window *porsche_create_window()
{
    static Window porsche_window = {
        .open = porsche_window_open
    };

    return &porsche_window;
}

static CarFactory porsche_factory = {
    .create_body = porsche_create_body,
    .create_window = porsche_create_window,
};

CarFactory *get_porsche_factory()
{
    return &porsche_factory;
}