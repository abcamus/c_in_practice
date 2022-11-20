#include <stdint.h>
#include <stddef.h>

struct _DataElement;

#define MAX_HANDLER_NUM 16
typedef struct _DataElement *(*DataHandler)(struct _DataElement *data_obj, void *param);

static DataHandler hdls[16];
static uint8_t total_hdl_num = 0;

#define REGISTER_HANDLER(handler) \
    hdls[total_hdl_num++] = handler

typedef struct _DataElement {
    uint8_t *addr;
    size_t size;
    DataHandler func;
} DataElement;

void kernel(uint8_t *data, uint32_t size, void *param)
{
    if (total_hdl_num == 0) {
        return;
    }

    DataElement header = {
        .addr = data,
        .size = size,
        .func = hdls[0]
    };

    DataElement *next = &header;

    for (uint8_t loop_cnt = 0; loop_cnt < MAX_HANDLER_NUM && next->func; ) {
        next->func(next, param);
    }
}