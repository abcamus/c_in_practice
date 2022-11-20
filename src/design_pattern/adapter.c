#include <stdio.h>
#include <malloc.h>

#include "adapter.h"

/* 仅支持type-c口的Device */
static void plugin_device(Device *headphone, TypeCHost *host)
{
    /* 耳机插入手机中 */
    printf("plugin typec headphone\n");
}

static void adapt_legacy_device(LegacyDevice *dev, LegacyAudioHost *host)
{
    printf("plugin a legacy device into a legacy host\n");
}

static void plugin_legacy_host(LegacyAudioHost *audioAdapter, TypeCHost *host)
{
    printf("plugin a transformer into a type_c host\n");
}

static LegacyAudioHost *g_legacyHost;

/* 将一个旧设备插入到TypeC Host中 */
int plugin_legacy_device(LegacyDevice *dev, TypeCHost *host)
{
    if (g_legacyHost == NULL) {
        g_legacyHost = (LegacyAudioHost *)malloc(sizeof(LegacyAudioHost));
    }
    plugin_legacy_host(g_legacyHost, host);
    adapt_legacy_device(dev, g_legacyHost);
    return 0;
}

void demo_adapter()
{
    Device *dev = (Device *)malloc(sizeof(Device));
    TypeCHost *host = (TypeCHost *)malloc(sizeof(TypeCHost));
    LegacyDevice *legacyDev = NULL;

    /* 插入typec音频设备 */
    plugin_device(dev, host);
    /* 适配老音频设备 */
    legacyDev = (LegacyDevice *)malloc(sizeof(LegacyDevice));
    plugin_legacy_device(legacyDev, host);

    free(dev);
    free(host);
    free(legacyDev);
}