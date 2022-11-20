#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

struct House {
    int type;
};

typedef enum {
    RED,
    YELLOE,
    GREEN,
} Color;

typedef uint32_t Height;
typedef uint32_t Width;

static void start_car(struct House *car) {}

struct HouseProxy {
    struct House *house;
    bool ready;
    uint32_t width;
    uint32_t height;
    uint32_t color;
};

static struct HouseProxy proxy;

bool create_house(Width width, Height height, Color color)
{
    proxy.width = width;
    proxy.height = height;
    proxy.color = color;
    proxy.ready = true;
    return true;
}

Width get_house_width()
{
    return proxy.width;
}

bool is_house_ready()
{
    return proxy.ready;
}

void start_car_proxy()
{
    // 创建真正的house对象
    proxy.house = (struct House *)malloc(sizeof(struct House));
    // DO OTHER THINGS
}