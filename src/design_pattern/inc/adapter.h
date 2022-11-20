#ifndef ADAPTER_H
#define ADAPTER_H

#define DEVICE_NAME_SIZE 16

typedef struct {
    void *dev_list;
} TypeCHost;

/* 定义一个设备，也有自己的plugin接口，但是是type-c接口实现 */
typedef struct _Device {
    char name[DEVICE_NAME_SIZE];
    int major_id;
} Device;

typedef struct {
    char name[DEVICE_NAME_SIZE];
    int major_id;
} LegacyAudioHost;

/* 老的音频设备，能插入3.5mm音频口 */
typedef struct {
    char name[DEVICE_NAME_SIZE];
    int major_id;
} LegacyDevice;

#endif