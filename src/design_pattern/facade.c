#include <stddef.h>

/**
 * 1. 为一个复杂子系统提供一个简单接口；
 * 2. 客户程序和抽象类的实现部分存在很大依赖性，提高子系统的独立性和可移植性
 */

typedef struct {

} Parser;

typedef struct {

} Node;

typedef struct _Scanner {
    Node *(*next_node)(const struct _Scanner *self);
} Scanner;

static void parse_node(Parser *parser, const Node *node)
{}

static void scan(Scanner *scanner, const char *byte_stream)
{}

static void parse(Parser *parser, const Scanner *scanner)
{
    parse_node(parser, scanner->next_node(scanner));
}

void compile(const char *byte_stream, size_t size)
{
    // 编译一个文件字节流
    Scanner scanner;
    Parser parser;
    scan(&scanner, byte_stream);
    parse(&parser, &scanner);
}

