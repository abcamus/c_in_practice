/**
 * 装饰，别名wrapper
 *
 */
struct Coffee {
    int a;
};

typedef struct _Producer {
    struct Coffee *(*produce)(void *self);
} Producer;

typedef struct {
    Producer cofferProcuder;
    struct Coffee (*procuce)(void *self);
} ProducerWithSugar;

static struct Coffee *produce_coffee_with_sugar(void *self)
{
    ProducerWithSugar *p = (ProducerWithSugar *)self;
    Producer *coffeeProducer = &p->cofferProcuder;
    struct Coffee *coffee = coffeeProducer->produce(coffeeProducer);
    // TODO: 给咖啡加点糖

    return coffee;
}