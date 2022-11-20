#include <stdio.h>
#include <malloc.h>

#include "builder.h"

/**
 * @brief 引导员
 *
 * 控制具体的build过程
 *
 * @param director
 */
static void construct(void *director)
{
    Builder *self = (Builder *)director;
    CarBuilder *builder = self->builder;
    builder->build_windows(builder, 2);
    builder->build_body(builder, NULL);
}

static Builder __d = {
    .construct = construct,
};

Builder *new_builder(void *builder)
{
    __d.builder = (CarBuilder *)builder;
    return &__d;
}

void test_builder()
{
    PorscheBuilder *concrete_builder = new_porsche_builder();
    Builder *d = new_builder(concrete_builder);

    d->construct(d);

    int build_count = concrete_builder->get_result(concrete_builder);
    printf("total build count: %d\n", build_count);

    free(concrete_builder);
}