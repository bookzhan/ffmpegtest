//
/**
 * Created by raoyun on 2023-06-13 20:02.
 * description:
 */
//

#include "CallBackTest.h"

int CallBackTest::init(int64_t handle, void (*progressCallBack)(int64_t, float)) {
    progressCallBack(handle, 0);
    progressCallBack(handle, 0.2);
    progressCallBack(handle, 0.4);
    progressCallBack(handle, 0.6);
    progressCallBack(handle, 0.8);
    progressCallBack(handle, 1);
    return 0;
}
