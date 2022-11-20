#include <stdio.h>
#include <stdlib.h>
#include "factory_method.h"

static void new_document(void *self)
{
    Application *app = (Application *)self;
    Document *doc = (app->create_document)();
    app->docs[app->doc_num++] = doc;
    doc->open(doc);
}

static void close(void *p)
{
    Application *app = (Application *)p;
    for(int i = 0; i < app->doc_num; i++) {
        app->docs[i]->close(app->docs[i]);
        free(app->docs[i]);
    }
}

Application *new_app(Document *(*create_doc)(), size_t size)
{
    Application *app = (Application *)malloc(size);

    app->new_document = new_document;
    app->close = close;
    app->create_document = create_doc;

    return app;
}