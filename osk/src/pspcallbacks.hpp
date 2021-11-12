//
// Created by root on 13.3.2018.
//

#ifndef OSK_PSPCALLBACKS_H
#define OSK_PSPCALLBACKS_H

#include <pspuser.h>

int exit_callback(int arg1, int arg2, void *common) {
    sceKernelExitGame();
    return 0;
}

int CallbackThread(SceSize args, void *argp) {
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, nullptr);
    sceKernelRegisterExitCallback(cbid);
    sceKernelSleepThreadCB();
    return 0;
}

int SetupCallbacks() {
    int thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0,
                                     PSP_THREAD_ATTR_USER, nullptr);
    if (thid >= 0) {
        sceKernelStartThread(thid, 0, nullptr);
    }
    return thid;
}

#endif //OSK_PSPCALLBACKS_H
