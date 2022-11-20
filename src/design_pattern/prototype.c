#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    void (*draw)(void *self);
    void *(*clone)(void *self);
} Graphic;

static void rect_draw(void *self)
{
    printf("%s, %d\n", __func__, __LINE__);
}

static void *rect_clone(void *self)
{
    Graphic *new_rect = (Graphic *)malloc(sizeof(Graphic));
    memcpy(new_rect, self, sizeof(Graphic));

    return new_rect;
}

static Graphic rect = {
    .draw = rect_draw,
    .clone = rect_clone,
};

void test_prototype()
{
    Graphic *prototype = &rect;

    Graphic *p = (Graphic *)prototype->clone(prototype);
    p->draw(NULL);

    free(p);
}