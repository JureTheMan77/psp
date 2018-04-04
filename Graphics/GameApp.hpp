#ifndef GRAPHICS_GAMEAPP_HPP
#define GRAPHICS_GAMEAPP_HPP

#include <pspgum.h>
#include "GraphicsObject.hpp"
#include "Triangle.hpp"

class GameApp {
protected:
    uint32_t frameCount;
    GraphicsObject *gfx;
    Triangle *triangle;
    ScePspFMatrix4 projection;
    ScePspFMatrix4 view;

    int8_t Controls();

    void Render();

    bool Load();

public:
    GameApp();

    ~GameApp();

    int Run();

};

#endif //GRAPHICS_GAMEAPP_HPP
