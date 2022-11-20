#include <stdbool.h>
#include <stdint.h>

typedef enum {
    SUCCESS,
    FAILURE,
    NOT_SUPPORTED,
} HandleResult;

typedef struct _Handler {
    unsigned handle_id;
    HandleResult (*handle_request)(void *self, void *req);
    struct _Handler *successor;
} Handler;

typedef struct {
    uint8_t type_id;
} Request;

HandleResult handle_request(void *handler, void *_req)
{
    Handler *self = (Handler *)handler;
    Request *req = (Request *)_req;
    // 识别是否是发给自己的请求
    if (req->type_id == self->handle_id) {
        // 处理，根据处理结果返回成功或失败
        return SUCCESS;
    }
    Handler *next = self->successor;
    while (next) {
        HandleResult result = next->handle_request(next, req);
        if (result == NOT_SUPPORTED) {
            next = next->successor;
        } else {
            return result;
        }
    }
    return SUCCESS;
}