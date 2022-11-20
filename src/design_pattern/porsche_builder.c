#include <stdio.h>
#include <stdlib.h>
#include "builder.h"

static int get_result(PorscheBuilder *self)
{
    PorscheBuilder *builder = (PorscheBuilder *)self;
    return builder->count;
}

static void build_body(void *self, void *params)
{
    PorscheBuilder *builder = (PorscheBuilder *)self;
    builder->count++;
    printf("%s, %d\n", __func__, __LINE__);
}

static void build_windows(void *self, int num)
{
    PorscheBuilder *builder = (PorscheBuilder *)self;
    builder->count++;
    printf("%s, %d\n", __func__, __LINE__);
}

PorscheBuilder *new_porsche_builder()
{
    PorscheBuilder *builder = (PorscheBuilder *)malloc(sizeof(PorscheBuilder));
    builder->parent.build_body = build_body;
    builder->parent.build_windows = build_windows;
    builder->get_result = get_result;

    return builder;
}