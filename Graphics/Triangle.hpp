//
// Created by root on 1.4.2018.
//

#ifndef GRAPHICS_TRIANGLE_H
#define GRAPHICS_TRIANGLE_H

#include <pspuser.h>

typedef struct {
    uint32_t color;
    float x, y, z;
} Vertex;

class Triangle {
protected:
    Vertex *triangle;
    float rot;
    ScePspFMatrix4 world;

public:
    Triangle();

    ~Triangle();

    void Render();
};


#endif //GRAPHICS_TRIANGLE_H
