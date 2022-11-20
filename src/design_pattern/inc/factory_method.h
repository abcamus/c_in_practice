#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

typedef struct {
    void (*open)(void *obj);
    void (*close)(void *obj);
    void (*save)(void *obj);
    void (*revert)(void *obj);
} Document;

typedef struct {
    Document *docs[128];
    unsigned doc_num;
    Document *(*create_document)();
    void (*new_document)(void *app);
    void (*open_document)();
    void (*close)(void *app);
} Application;

Application *new_app(Document *(*create_doc)(), size_t size);

#endif