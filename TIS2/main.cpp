#include <pspkernel.h>
#include <string>
#include <sstream>
#include <ctime>
#include <pspdebugkb.h>
#include <pspctrl.h>
#include <psputility.h>
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
//

int main() {
    pspDebugScreenInit();
    SetupCallbacks();

    printf("Start\n");

    clock_t begin = clock();

    int dolzinaNiza = 20;
    uint64_t tab[] = {0, 0, 0, 0, 0};
    uint64_t v_stNIzov = 0, *stNizov = &v_stNIzov;

    auto stEnic = static_cast<uint32_t>(dolzinaNiza / 5);

    generiraj("", 0, dolzinaNiza, stEnic, stNizov, tab);
    printf("%s nizov\n", uint64_t_toString(*stNizov).c_str());
    printf("1: %s\n01: %s\n001: %s\n0001: %s\n0000: %s\nskupaj %s posameznih kod\n",
           uint64_t_toString(tab[0]).c_str(),
           uint64_t_toString(tab[1]).c_str(),
           uint64_t_toString(tab[2]).c_str(),
           uint64_t_toString(tab[3]).c_str(),
           uint64_t_toString(tab[4]).c_str(),
           uint64_t_toString(tab[0] + tab[1] + tab[2] + tab[3] + tab[4]).c_str());

    /*printf("%f\n", static_cast<float>(tab[0] + 2 * tab[1] + 3 * tab[2] + 4 * tab[3] + 4 * tab[4]));
    auto deljitelj = static_cast<long>(tab[0] + tab[1] + tab[2] + tab[3] + tab[4]);
    printf("%ld\n", deljitelj);*/
    double povprecnaDolzina = static_cast<double>(tab[0] + 2 * tab[1] + 3 * tab[2] + 4 * tab[3] + 4 * tab[4]) /
                              static_cast<double>(tab[0] + tab[1] + tab[2] + tab[3] + tab[4]);
    printf("povprecna dolzina: %lf\n", povprecnaDolzina);

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Cas izvajanja: %lf sekund\n", time_spent);

    /*sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_DIGITAL);

    SceCtrlData input{};

    string izpis;
    auto *izpisPtr = reinterpret_cast<unsigned short *>(&izpis);
    SceUtilityOskData *oskData{};
    oskData->unk_00 = 0;
    oskData->unk_04 = 0;
    oskData->unk_12 = 0;
    oskData->unk_24 = 0;
    oskData->language = PSP_UTILITY_OSK_LANGUAGE_DEFAULT;
    oskData->inputtype = PSP_UTILITY_OSK_INPUTTYPE_ALL;
    oskData->lines = 1;
    oskData->desc = (unsigned short *) "Testna tipkovnica";
    oskData->intext = (unsigned short *) "";
    oskData->outtext = izpisPtr;
    oskData->result = PSP_UTILITY_OSK_RESULT_CHANGED;
    oskData->outtextlimit = 30;

    auto *base = new pspUtilityDialogCommon;
    base->result = 0;
    base->language = 0;
    base->accessThread = 0;
    base->buttonSwap = 0;
    base->fontThread = 0;
    base->graphicsThread = 0;
    base->soundThread = 0;
    base->reserved[0]=0;
    base->reserved[1]=0;
    base->reserved[2]=0;
    base->reserved[3]=0;
    base->size = sizeof(SceUtilityOskParams);

    auto *oskParams = new SceUtilityOskParams;
    oskParams->datacount = 1;
    oskParams->unk_60 = 0;
    oskParams->base = *base;
    oskParams->data = oskData;

    printf("%d\n", static_cast<int>(sizeof(SceUtilityOskParams)));
    printf("%d\n", static_cast<int>(sizeof(*base)));
    printf("%d\n", oskParams->base.size);

    sceUtilityOskInitStart(oskParams);*/

    /*pspDebugScreenSetTextColor(0xffffffff);
    pspDebugScreenSetBackColor(0x00000000);
    printf("\nstri = \"%s\"\n", izpis.c_str());

    printf("%s\n", izpis.c_str());*/

    /*char str[PSP_DEBUG_KB_MAXLEN];
    wmemset(reinterpret_cast<wchar_t *>(str), '0', PSP_DEBUG_KB_MAXLEN);

    while (true) {
        sceCtrlReadBufferPositive(&input, 1);

        if (input.Buttons & PSP_CTRL_CROSS) {
            pspDebugKbInit(str);

            pspDebugScreenSetTextColor(0xffffffff);
            pspDebugScreenSetBackColor(0x00000000);
            printf("\nstri = \"%s\"\n", str);
            break;
            //printf("str is %d characters long", str);
        }
    }*/


    sceKernelSleepThread();
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