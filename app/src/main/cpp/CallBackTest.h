//
/**
 * Created by raoyun on 2023-06-13 20:02.
 * description:
 */
//

#ifndef FFMPEGTEST_CALLBACKTEST_H
#define FFMPEGTEST_CALLBACKTEST_H
#include <cstdint>

class CallBackTest {
public:
    int init(int64_t handle, void (*progressCallBack)(int64_t javaHandle, float progress));
};


#endif //FFMPEGTEST_CALLBACKTEST_H
