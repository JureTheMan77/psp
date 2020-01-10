#include <pspctrl.h>
#include <exception>
#include <pspuser.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include "GameApp.hpp"
#include "Buttons.hpp"

static unsigned int __attribute__((aligned(16))) list[262144];

GameApp::GameApp() {

}

GameApp::~GameApp() {

}

int GameApp::Run() {
    if (!Load()) {
        return 1;
    }

    //game loop
    while (true) {
        if (Controls() == Buttons::circle) {
            break;
        }
        Render();
    }
    return 0;
}

bool GameApp::Load() {
    try {
        //get Graphics ptr
        gfx = GraphicsObject::Instance();
        //set up environment
        gfx->Init3DGraphics();

        //setting the projection matrix
        sceGumMatrixMode(GU_PROJECTION);
        sceGumLoadIdentity();
        sceGumPerspective(75, 16.0f / 9.0f, 0.5, 1000);

        //create the triangle
        triangle = new Triangle();

        return true;

    } catch (std::exception e) {
        pspDebugScreenPrintf("Exception:\n%s", e.what());
        return false;
    }
}

int8_t GameApp::Controls() {
    frameCount++;
    pspDebugScreenPrintf("Frame %d\n", frameCount);

    //read structs
    SceCtrlData pad;
    sceCtrlReadBufferPositive(&pad, 1);

    //check no input
    if (pad.Buttons == 0) {
        return Buttons::none;
    }

    //check for actual buttons presses
    if (pad.Buttons & PSP_CTRL_CROSS) {
        return Buttons::cross;
    }
    if (pad.Buttons & PSP_CTRL_CIRCLE) {
        return Buttons::circle;
    }
    /*if (pad.Buttons & PSP_CTRL_SQUARE) {
        return Buttons::square;
    }
    if (pad.Buttons & PSP_CTRL_TRIANGLE) {
        return Buttons::triangle;
    }
    if (pad.Buttons & PSP_CTRL_LTRIGGER) {
        return Buttons::leftTrigger;
    }
    if (pad.Buttons & PSP_CTRL_RTRIGGER) {
        return Buttons::rightTrigger;
    }
    if (pad.Buttons & PSP_CTRL_SELECT) {
        return Buttons::select;
    }
    if (pad.Buttons & PSP_CTRL_START) {
        return Buttons::start;
    }
    if (pad.Buttons & PSP_CTRL_HOME) {
        return Buttons::home;
    }
    if (pad.Buttons & PSP_CTRL_VOLDOWN) {
        return Buttons::volumeDown;
    }
    if (pad.Buttons & PSP_CTRL_VOLUP) {
        return Buttons::volumeUp;
    }
    if (pad.Buttons & PSP_CTRL_SCREEN) {
        return Buttons::screen;
    }
    if (pad.Buttons & PSP_CTRL_UP) {
        return Buttons::DPadUp;
    }
    if (pad.Buttons & PSP_CTRL_RIGHT) {
        return Buttons::DPadRight;
    }
    if (pad.Buttons & PSP_CTRL_DOWN) {
        return Buttons::DPadDown;
    }
    if (pad.Buttons & PSP_CTRL_LEFT) {
        return Buttons::DPadLeft;
    }
    if (pad.Buttons & PSP_CTRL_HOLD) {
        return Buttons::hold;
    }
    if (pad.Buttons & PSP_CTRL_NOTE) {
        return Buttons::note;
    }
    if (pad.Buttons & PSP_CTRL_WLAN_UP) {
        return Buttons::wlanUp;
    }
    if (pad.Buttons & PSP_CTRL_REMOTE) {
        return Buttons::remoteHold;
    }
    if (pad.Buttons & PSP_CTRL_DISC) {
        return Buttons::discPresent;
    }
    if (pad.Buttons & PSP_CTRL_MS) {
        return Buttons::memoryStickPresent;
    }*/

    return Buttons::none;
}

void GameApp::Render() {
    sceGumMatrixMode(GU_VIEW);
    ScePspFVector3 lpos = {1, 0, 1};
    sceGuStart(GU_DIRECT, list);

    //clear screen
    sceGuClearColor(0xff554433);
    sceGuClearDepth(0);
    sceGuLight(0, GU_DIRECTIONAL, GU_DIFFUSE_AND_SPECULAR, &lpos);
    sceGuLightColor(0, GU_DIFFUSE_AND_SPECULAR, 0xffffffff);
    sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);
    sceGuSpecular(12.0f);

    //ambient light
    sceGuAmbientColor(0xffffffff);

    //set the view
    sceGumLoadIdentity();

    ScePspFQuaternion

    //render the model
    triangle->Render();

    //end render
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}
