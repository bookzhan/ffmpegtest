#include <jni.h>
#include <string>
#include <common/ffmpeg_base_info.h>
#include <JvmManager.h>
#include <ActionMethodInfo.h>
#include "CallBackTest.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ffmpegtest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    printFFmpegBaseInfo();
    return env->NewStringUTF(hello.c_str());
}

void callBackGateway(int64_t methodHandle, float progress) {
    JNIEnv *jniEnv = nullptr;
    bool needDetach = JvmManager::getJNIEnv(&jniEnv);
    if (methodHandle == 0 || nullptr == jniEnv) {
        jniEnv = nullptr;
        if (needDetach)
            JvmManager::getJavaVM()->DetachCurrentThread();
        return;
    }
    auto *videoPlayerMethodInfo = (ActionMethodInfo *) methodHandle;

    jniEnv->CallVoidMethod(videoPlayerMethodInfo->listenerObj,
                           videoPlayerMethodInfo->onProgressMethodId, progress);
    jniEnv = nullptr;
    if (needDetach)
        JvmManager::getJavaVM()->DetachCurrentThread();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ffmpegtest_MainActivity_testCallBack(JNIEnv *env, jobject thiz, jobject on_action_listener) {
    CallBackTest callBackTest;

    auto *videoPlayerMethodInfo = new ActionMethodInfo();
    //CallBack一般涉及到多线程交互,一般通过NewGlobalRef作为全局变量
    jobject listenerObj = env->NewGlobalRef(on_action_listener);
    videoPlayerMethodInfo->listenerObj = listenerObj;
    jclass listenerClass = env->GetObjectClass(on_action_listener);
    videoPlayerMethodInfo->onProgressMethodId = env->GetMethodID(listenerClass,
                                                                        "progress",
                                                                        "(F)V");
    env->DeleteLocalRef(listenerClass);
    callBackTest.init(reinterpret_cast<int64_t>(videoPlayerMethodInfo), callBackGateway);
    env->DeleteGlobalRef(listenerObj);
    delete videoPlayerMethodInfo;
}