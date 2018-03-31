#ifndef GRAPHICS_GAMEAPP_HPP
#define GRAPHICS_GAMEAPP_HPP

#include "GraphicsObject.hpp"

class GameApp {
protected:
    uint32_t frameCount;
    GraphicsObject *gfx;

    int8_t Controls();

    void Render();

    bool Load();

public:
    GameApp();

    ~GameApp();

    int Run();

};

#endif //GRAPHICS_GAMEAPP_HPP
