/**
 * @file command.c
 * @author your name (you@domain.com)
 * @brief 命令，将请求封装成对象，提供抽象的执行接口
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

typedef struct {
    void (*execute)(void *p);
} Command;

static void handle_document(void *doc)
{

}

static void handle_application(void *app)
{

}

static Command doc_cmd = {
    .execute = handle_document,
};

static Command app_cmd = {
    .execute = handle_application,
};

/* 由命令的源触发 */
typedef struct {
    Command cmd;
} Invoker;