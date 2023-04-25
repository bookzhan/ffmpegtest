//
/**
 * Created by bookzhan on 2020-05-25 17:00.
 *description:
 */
//

#ifndef BZMEDIA_FFMPEG_BASE_INFO_H
#define BZMEDIA_FFMPEG_BASE_INFO_H

extern "C" {
#include <arm64-v8a/libavcodec/avcodec.h>
#include <arm64-v8a/libavformat/avformat.h>
#include <arm64-v8a/libavfilter/avfilter.h>
#include "arm64-v8a/libavutil/avutil.h"
}

void printFFmpegBaseInfo();

int getFFmpegConfigure(char *info);

int getFFmpegSupportProtocol(char *info);

int getFFmpegSupportAVFormat(char *info);

int getFFmpegSupportAVCodec(char *info);

int getFFmpegSupportAVFilter(char *info);

int testLib();

#endif //BZMEDIA_FFMPEG_BASE_INFO_H
