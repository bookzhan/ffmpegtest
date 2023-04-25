//
/**
 * Created by bookzhan on 2020-05-25 17:00.
 *description:
 */
//

#include <common/BZLogUtil.h>
#include <cstring>
#include "ffmpeg_base_info.h"


void printFFmpegBaseInfo() {
    char buffer[4096];
    getFFmpegConfigure(buffer);
    BZLogUtil::logD(buffer);

    memset(buffer, 0, 4096);
    getFFmpegSupportProtocol(buffer);
    BZLogUtil::logD(buffer);

    memset(buffer, 0, 4096);
    getFFmpegSupportAVFormat(buffer);
    BZLogUtil::logD(buffer);

    memset(buffer, 0, 4096);
    getFFmpegSupportAVCodec(buffer);
    BZLogUtil::logD(buffer);

    memset(buffer, 0, 4096);
    getFFmpegSupportAVFilter(buffer);
    BZLogUtil::logD(buffer);

    testLib();
}

int getFFmpegConfigure(char *info) {
    return sprintf(info, "%s\n", avcodec_configuration());;
}

int getFFmpegSupportProtocol(char *info) {
    struct URLProtocol *pup = nullptr;
    int ret = 0;
    //Input
    struct URLProtocol **p_temp = &pup;
    avio_enum_protocols((void **) p_temp, 0);
    while ((*p_temp) != nullptr) {
        ret = sprintf(info, "%s[In ][%10s]\n", info, avio_enum_protocols((void **) p_temp, 0));
    }
    pup = nullptr;
    //Output
    avio_enum_protocols((void **) p_temp, 1);
    while ((*p_temp) != nullptr) {
        ret = sprintf(info, "%s[Out][%10s]\n", info, avio_enum_protocols((void **) p_temp, 1));
    }
    return ret;
}

int getFFmpegSupportAVFormat(char *info) {
    int ret = 0;
    void *opaque_in = nullptr;
    void *opaque_out = nullptr;
    const AVInputFormat *if_temp = av_demuxer_iterate(&opaque_in);
    const AVOutputFormat *of_temp = av_muxer_iterate(&opaque_out);
    //Input
    while (if_temp != nullptr) {
        ret = sprintf(info, "%s[In ][%10s]\n", info, if_temp->name);
        if_temp = av_demuxer_iterate(&opaque_in);;
    }
    //Output
    while (of_temp != nullptr) {
        ret = sprintf(info, "%s[Out][%10s]\n", info, of_temp->name);
        of_temp = av_muxer_iterate(&opaque_out);
    }
    return ret;
}

int getFFmpegSupportAVCodec(char *info) {
    int ret = 0;
    void *opaque = nullptr;
    const AVCodec *c_temp = av_codec_iterate(&opaque);

    while (c_temp != nullptr) {
        if (av_codec_is_decoder(c_temp) != 0) {
            ret = sprintf(info, "%s[Dec]", info);
        } else {
            ret = sprintf(info, "%s[Enc]", info);
        }
        switch (c_temp->type) {
            case AVMEDIA_TYPE_VIDEO:
                sprintf(info, "%s[Video]", info);
                break;
            case AVMEDIA_TYPE_AUDIO:
                sprintf(info, "%s[Audio]", info);
                break;
            default:
                sprintf(info, "%s[Other]", info);
                break;
        }
        ret = sprintf(info, "%s[%10s]\n", info, c_temp->name);
        c_temp = av_codec_iterate(&opaque);
    }
    return ret;
}

int getFFmpegSupportAVFilter(char *info) {
    int ret = 0;
    void *opaque = nullptr;
    const AVFilter *f_temp = av_filter_iterate(&opaque);
    while (nullptr != f_temp) {
        ret = sprintf(info, "%s[%10s]\n", info, f_temp->name);
        f_temp = av_filter_iterate(&opaque);
    }
    return ret;
}

int testLib() {
    const AVCodec *avCodec = avcodec_find_decoder(AV_CODEC_ID_H264);
    if (nullptr == avCodec) {
        BZLogUtil::logD("avcodec_find_decoder AV_CODEC_ID_H264 未发现");
    } else {
        BZLogUtil::logD("avcodec_find_decoder AV_CODEC_ID_H264 正常");
    }
    const AVCodec *avCodecAAC = avcodec_find_decoder(AV_CODEC_ID_AAC);
    if (nullptr == avCodecAAC) {
        BZLogUtil::logD("avcodec_find_decoder AV_CODEC_ID_AAC 未发现");
    } else {
        BZLogUtil::logD("avcodec_find_decoder AV_CODEC_ID_AAC 正常");
    }


    const AVCodec *avCodecEncoder = avcodec_find_encoder(AV_CODEC_ID_H264);
    if (nullptr == avCodecEncoder) {
        BZLogUtil::logD("avcodec_find_encoder AV_CODEC_ID_H264 未发现");
    } else {
        BZLogUtil::logD("avcodec_find_encoder AV_CODEC_ID_H264 正常");
    }


    const AVCodec *avCodecDecoderMp3 = avcodec_find_decoder(AV_CODEC_ID_MP3);
    if (nullptr == avCodecDecoderMp3) {
        BZLogUtil::logD("avcodec_find_decoder AV_CODEC_ID_MP3 未发现");
    } else {
        BZLogUtil::logD("avcodec_find_decoder AV_CODEC_ID_MP3 正常");
    }


    const AVCodec *avCodecAACEncoder = avcodec_find_encoder(AV_CODEC_ID_AAC);
    if (nullptr == avCodecAACEncoder) {
        BZLogUtil::logD("avcodec_find_encoder AV_CODEC_ID_AAC 未发现");
    } else {
        BZLogUtil::logD("avcodec_find_encoder AV_CODEC_ID_AAC 正常");
    }
    return 0;
}

