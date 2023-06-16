//
/**
 * Created by raoyun on 2023-06-13 20:04.
 * description:
 */
//

#ifndef FFMPEGTEST_ACTIONMETHODINFO_H
#define FFMPEGTEST_ACTIONMETHODINFO_H

#include <jni.h>

typedef struct ActionMethodInfo {
    jobject listenerObj = NULL;
    jmethodID onProgressMethodId = NULL;
} ActionMethodInfo;


#endif //FFMPEGTEST_ACTIONMETHODINFO_H
