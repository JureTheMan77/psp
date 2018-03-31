//
// Created by root on 31.3.2018.
//

#ifndef GRAPHICS_BUTTONS_H
#define GRAPHICS_BUTTONS_H


class Buttons {
public:
    static const int8_t none = -1;
    static const int8_t cross = 0;
    static const int8_t circle = 1;
    static const int8_t square = 2;
    static const int8_t triangle = 3;
    static const int8_t leftTrigger = 4;
    static const int8_t rightTrigger = 5;
    static const int8_t select = 6;
    static const int8_t start = 7;
    static const int8_t home = 8;
    static const int8_t volumeDown = 9;
    static const int8_t volumeUp = 10;
    static const int8_t screen = 11;

    static const int8_t DPadUp = 12;
    static const int8_t DPadRight = 13;
    static const int8_t DPadDown = 14;
    static const int8_t DPadLeft = 15;

    static const int8_t hold = 16;
    static const int8_t note = 17;
    static const int8_t wlanUp = 18;
    static const int8_t remoteHold = 19;
    static const int8_t discPresent = 20;
    static const int8_t memoryStickPresent = 21;

private:
    Buttons() = default;
};


#endif //GRAPHICS_BUTTONS_H
