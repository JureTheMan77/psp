#include <pspkernel.h>
#include <string>
#include <sstream>
#include <ctime>
#include <pspdebugkb.h>
#include <pspctrl.h>
#include <psputility.h>
#include <pspdisplay.h>
#include "pspcallbacks.hpp"

#define printf pspDebugScreenPrintf
typedef long long ll;

using namespace std;

PSP_MODULE_INFO("TIS2", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

//global variable declaration


//function declaration
void generiraj(const string &s, int dolzina, int dolzinaNiza, int stEnic, uint64_t *stNizov,
               uint64_t tab[5]);

int preveriStEnk(string s);

void preveriKodo(string s, int dolzinaNiza, uint64_t tab[5]);

string uint64_t_tabToString(uint64_t tab[], int size);

string uint64_t_toString(uint64_t argument);

string uint32_t_toString(uint32_t argument);

string long_double_ToString(long double argument);

void izracunaj(uint32_t dolzinaNiza);

bool IsValidAddress(u32 address);
//

int main() {
    pspDebugScreenInit();
    SetupCallbacks();

    uint32_t dolzinaNiza = 20;

    izracunaj(dolzinaNiza);

    auto *izpis = new string;
    auto *oskData = new SceUtilityOskData;
    oskData->unk_00 = 0;
    oskData->unk_04 = 0;
    oskData->unk_12 = 0;
    oskData->unk_24 = 0;
    oskData->language = PSP_UTILITY_OSK_LANGUAGE_ENGLISH;
    oskData->inputtype = PSP_UTILITY_OSK_INPUTTYPE_LATIN_LOWERCASE;
    oskData->lines = 1;
    oskData->desc = (unsigned short *) "Testna tipkovnica";
    oskData->intext = (unsigned short *) "test";
    oskData->outtext = reinterpret_cast<unsigned short *>(izpis);
    oskData->result = PSP_UTILITY_OSK_RESULT_UNCHANGED;
    oskData->outtextlimit = 30;

    auto *base = new pspUtilityDialogCommon;
    base->result = 0;
    base->language = 0;
    base->accessThread = 0;
    base->buttonSwap = 0;
    base->fontThread = 0;
    base->graphicsThread = 0;
    base->soundThread = 0;
    base->reserved[0] = 0;
    base->reserved[1] = 0;
    base->reserved[2] = 0;
    base->reserved[3] = 0;
    base->size = sizeof(SceUtilityOskParams);

    auto *oskParams = new SceUtilityOskParams;
    oskParams->datacount = 1;
    oskParams->unk_60 = 0;
    oskParams->base = *base;
    oskParams->data = oskData;
    oskParams->state = PSP_UTILITY_OSK_DIALOG_VISIBLE;

    printf("\npspUtilityDialogCommon %d\n", static_cast<int>(sizeof(pspUtilityDialogCommon)));
    printf("base %d\n", static_cast<int>(sizeof(*base)));
    printf("base.size %d\n\n", oskParams->base.size);

    printf("SceUtilityOskParams %d %d\n", static_cast<int>(sizeof(SceUtilityOskParams)),
           static_cast<int>(sizeof(oskParams)));
    printf("SceUtilityOskParams->datacount %d\n", static_cast<int>(sizeof(oskParams->datacount)));
    printf("SceUtilityOskParams->unk_60 %d\n", static_cast<int>(sizeof(oskParams->unk_60)));
    printf("SceUtilityOskParams->data %d\n", static_cast<int>(sizeof(oskParams->data)));
    printf("SceUtilityOskParams->state %d\n", static_cast<int>(sizeof(oskParams->state)));

    if (IsValidAddress(reinterpret_cast<const u32>(oskParams->data))) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    sceUtilityOskInitStart(oskParams);

    printf("Keyboard state: %d\n", sceUtilityOskGetStatus());;

    /*while (sceUtilityOskGetStatus() != PSP_UTILITY_OSK_DIALOG_INITED) {
        sceKernelDelayThread(100000);
    }
    printf("inited\n");*/
    sceUtilityOskUpdate(1);
    printf("Keyboard state: %d\n", sceUtilityOskGetStatus());

    printf("fps: %f\n", sceDisplayGetFramePerSec());

    int mode, width, height;
    sceDisplayGetMode(&mode, &width, &height);

    printf("mode: %d\nwidth: %d\nheight: %d\n", mode, width, height);

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_DIGITAL);

    SceCtrlData input{};

    int i = 1;
    while (true) {
        sceCtrlReadBufferPositive(&input, 1);
        if (input.Buttons & PSP_CTRL_CROSS) {
            pspDebugScreenClear();
            i++;
            printf("St. izvedbe: %d\n", i);
            izracunaj(dolzinaNiza);
            continue;
        }
        if (input.Buttons & PSP_CTRL_CIRCLE) {
            break;
        }
    }

    printf("\nKONEC");
    sceKernelSleepThread();
}

void izracunaj(uint32_t dolzinaNiza) {
    printf("dolzina niza: %d\n", dolzinaNiza);

    clock_t begin = clock();
    uint64_t tab[] = {0, 0, 0, 0, 0};
    uint64_t v_stNIzov = 0, *stNizov = &v_stNIzov;

    auto stEnic = static_cast<uint32_t>(dolzinaNiza / 5);

    generiraj("", 0, dolzinaNiza, stEnic, stNizov, tab);

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("%s nizov\n", uint64_t_toString(*stNizov).c_str());
    printf("1: %s\n01: %s\n001: %s\n0001: %s\n0000: %s\nskupaj %s posameznih kod\n",
           uint64_t_toString(tab[0]).c_str(),
           uint64_t_toString(tab[1]).c_str(),
           uint64_t_toString(tab[2]).c_str(),
           uint64_t_toString(tab[3]).c_str(),
           uint64_t_toString(tab[4]).c_str(),
           uint64_t_toString(tab[0] + tab[1] + tab[2] + tab[3] + tab[4]).c_str());

    double povprecnaDolzina = static_cast<double>(tab[0] + 2 * tab[1] + 3 * tab[2] + 4 * tab[3] + 4 * tab[4]) /
                              static_cast<double>(tab[0] + tab[1] + tab[2] + tab[3] + tab[4]);
    printf("povprecna dolzina: ");
    pspDebugScreenSetTextColor(0x00ffff);
    printf("%lf\n", povprecnaDolzina);
    pspDebugScreenSetTextColor(0xffffff);

    printf("Cas izvajanja: ");
    pspDebugScreenSetTextColor(0x00ff00);
    printf("%lf", time_spent);
    pspDebugScreenSetTextColor(0xffffff);
    printf(" sekund\n");
}

bool IsValidAddress(const u32 address) {
    printf("0x%08X\n", address);
    if ((address & 0x3E000000) == 0x08000000) {
        return true;
    } else if ((address & 0x3F800000) == 0x04000000) {
        return true;
    } else if ((address & 0xBFFF0000) == 0x00010000) {
        return (address & 0x0000FFFF) < 0x00004000;
    } else return (address & 0x3F000000) >= 0x08000000 && (address & 0x3F000000) < 0x08000000 + 0x02000000;
}

string uint64_t_tabToString(uint64_t tab[], int size) {
    std::ostringstream oss;
    for (int i = 0; i < size; i++) {
        oss << tab[i];
        if (i < size - 1) {
            oss << ", ";
        }
    }
    return oss.str();
}

string uint64_t_toString(uint64_t argument) {
    std::ostringstream oss;
    oss << argument;
    return oss.str();
}

string uint32_t_toString(uint32_t argument) {
    std::ostringstream oss;
    oss << argument;
    return oss.str();
}

string long_double_ToString(long double argument) {
    std::ostringstream oss;
    oss << argument;
    return oss.str();
}

void generiraj(const string &s, int dolzina, int dolzinaNiza, int stEnic, uint64_t *stNizov,
               uint64_t tab[5]) {
    if (dolzina > dolzinaNiza || preveriStEnk(s) > stEnic) {
        return;
    }
    if (dolzina == dolzinaNiza) {
        if (preveriStEnk(s) == stEnic) {
            //printf("%s\n", s.c_str());
            *stNizov = *stNizov + 1;
            //printf("%ld\n", *stNizov);
            preveriKodo(s, dolzina, tab);
            return;
        } else {
            return;
        }
    }

    generiraj(s + "1", dolzina + 1, dolzinaNiza, stEnic, stNizov, tab);
    generiraj(s + "01", dolzina + 2, dolzinaNiza, stEnic, stNizov, tab);
    generiraj(s + "001", dolzina + 3, dolzinaNiza, stEnic, stNizov, tab);
    generiraj(s + "0001", dolzina + 4, dolzinaNiza, stEnic, stNizov, tab);
    generiraj(s + "0000", dolzina + 4, dolzinaNiza, stEnic, stNizov, tab);
}

int preveriStEnk(string s) {
    int stevilo = 0;
    for (char i : s) {
        if (i == '1') {
            stevilo++;
        }
    }
    return stevilo;
}

void preveriKodo(string s, int dolzinaNiza, uint64_t tab[5]) {
    int state = 0;

    for (int i = 0; i < dolzinaNiza; i++) {

        if (state == 0 && s[i] == '1') {
            tab[0] += 1;
            continue;
        }
        if (state == 0 && s[i] == '0') {
            state = 1;
            continue;
        }

        if (state == 1 && s[i] == '1') {
            tab[1] += 1;
            state = 0;
            continue;
        }
        if (state == 1 && s[i] == '0') {
            state = 2;
            continue;
        }

        if (state == 2 && s[i] == '1') {
            tab[2] += 1;
            state = 0;
            continue;
        }
        if (state == 2 && s[i] == '0') {
            state = 3;
            continue;
        }

        if (state == 3 && s[i] == '1') {
            tab[3] += 1;
            state = 0;
            continue;
        }
        if (state == 3 && s[i] == '0') {
            tab[4] += 1;
            state = 0;
        }
    }
}