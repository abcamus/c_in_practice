#ifndef FACTORY_H
#define FACTORY_H

enum CarFactoryType {
    FACTORY_PORSCHE,
    FACTORY_BENZ
};

typedef struct {
    void (*paint)();
} Body;

typedef struct {
    void (*open)();
} Window;

/* 生产房子的抽象工厂 */
typedef struct {
    Body *(*create_body)();
    Window *(*create_window)();
} CarFactory;

CarFactory *get_car_factory(enum CarFactoryType car_type);

#endif