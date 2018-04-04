#include <pspuser.h>
#include <string>
#include <pspgu.h>
#include "pspcallbacks.hpp"
#include "GameApp.hpp"

#define printf pspDebugScreenPrintf

using namespace std;

PSP_MODULE_INFO("Graphics", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

//tutorial: http://www.ghoti.nl/PSPtutorial1.php

int main() {
    SetupCallbacks();
    //pspDebugScreenInit();

    auto *game = new GameApp;
    int ret = game->Run();

    if (ret == 0) {
        printf("All  ok!\n");
    } else {
        printf("Loading failed!\n");
    }

    sceGuTerm();
    sceKernelExitGame();

    return 0;
}