#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "factory_method.h"

typedef struct {
    Document parent;
    int type;
} MyDocument;

static void my_close(void *obj)
{
    MyDocument *doc = (MyDocument *)obj;
    printf("%s, %d\n", __func__, __LINE__);
}

static void my_open(void *obj)
{
    MyDocument *doc = (MyDocument *)obj;
    printf("%s, %d\n", __func__, __LINE__);
}

static void my_save(void *obj)
{
    MyDocument *doc = (MyDocument *)obj;
    printf("%s, %d\n", __func__, __LINE__);
}

static void my_revert(void *obj)
{
    MyDocument *doc = (MyDocument *)obj;
    printf("%s, %d\n", __func__, __LINE__);
}

static Document *my_create_document()
{
    static int doc_num = 0;
    MyDocument *doc = (MyDocument *)malloc(sizeof(MyDocument));
    Document *parent = (Document *)doc;
    parent->open = my_open;
    parent->close = my_close;
    parent->save = my_save;
    parent->revert = my_revert;

    printf("%s, %d; num: %d\n", __func__, __LINE__, doc_num++);

    return (Document *)doc;
}

typedef struct {
    Application parent;
    int id;
} MyApplication;

void test_app_client()
{
    Application *app = new_app(my_create_document, sizeof(MyApplication));

    app->new_document(app);
    app->new_document(app);

    app->close(app);
}

void test_factory_method()
{
    test_app_client();
}