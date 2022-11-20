#include <stdio.h>
#include <stdlib.h>
#include "singleton.h"
#include "factory.h"
#include "builder.h"
#include "factory_method.h"
#include "log.h"

void test_app_client();
void demo_adapter();
void test_prototype();
void test_singleton();
void test_abstract_factory();
void test_builder();
void test_factory_method();

int main(int argc, char const *argv[])
{
    if (argc == 1) {
        INFO("Demo: Singleton\n");
        test_singleton();
        return 0;
    }
    switch (atoi(argv[1]))
    {
    case 0:
        INFO("Demo: Singleton\n");
        test_singleton();
        break;
    case 1:
        INFO("Demo: Abstract Factory\n");
        test_abstract_factory();
        break;
    case 2:
        INFO("Demo: Builder\n");
        test_builder();
        break;
    case 3:
        INFO("Demo: Factory Method\n");
        test_factory_method();
        break;
    case 4:
        INFO("Demo: prototype\n");
        test_prototype();
        break;
    case 5:
        INFO("Demo: Adapter\n");
        demo_adapter();
        break;
    default:
        INFO("Demo: Singleton\n");
        test_singleton();
        break;
    }

    return 0;
}
