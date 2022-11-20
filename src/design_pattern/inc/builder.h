#ifndef BUILDER_H
#define BUILDER_H

/**
 * @brief CarBuilder
 * 
 * builder，也称导向器，将对象的构建和表示分离，装配过程由ConcreteBuilder内部完成
 */
typedef struct {
    void (*build_windows)(void *obj, int num);
    void (*build_body)(void *obj, void *param);
} CarBuilder;

typedef struct
{
    CarBuilder *builder;
    void (*construct)(void *director);
} Builder;

typedef struct _PorscheBuilder {
    CarBuilder parent;
    int (*get_result)(struct _PorscheBuilder *self);
    int count;
} PorscheBuilder;

PorscheBuilder *new_porsche_builder();
Builder *new_builder(void *buider);

#endif