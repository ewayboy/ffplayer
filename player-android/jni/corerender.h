#ifndef _CORERENDER_H_
#define _CORERENDER_H_

// ����ͷ�ļ�
#include <android_runtime/AndroidRuntime.h>
#include <system/window.h>

extern "C" {
#include "libavformat/avformat.h"
}

// namespace android
using namespace android;

// ���Ͷ���
typedef struct
{
    int16_t *data;
    int32_t  size;
} AUDIOBUF;

// ��������
void* renderopen(sp<ANativeWindow> win, AVRational frate, int pixfmt, int w, int h,
                  int64_t ch_layout, AVSampleFormat sndfmt, int srate);

void renderclose     (void *hrender);
void renderaudiowrite(void *hrender, AVFrame *audio);
void rendervideowrite(void *hrender, AVFrame *video);
void renderstart     (void *hrender);
void renderpause     (void *hrender);
void renderseek      (void *hrender, int sec);
int  rendertime      (void *hrender);

#endif














