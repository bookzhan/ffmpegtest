#include <jni.h>
#include <string>
#include <common/ffmpeg_base_info.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ffmpegtest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    printFFmpegBaseInfo();
    return env->NewStringUTF(hello.c_str());
}