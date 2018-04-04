//
// Created by root on 1.4.2018.
//

#include <malloc.h>
#include <pspgum.h>
#include <pspgu.h>
#include "Triangle.hpp"

Triangle::Triangle() {
    triangle = (Vertex *) memalign(16, 3 * sizeof(Vertex));
    triangle[0].color = 0xff000000;
    triangle[0].x = -1;
    triangle[0].y = 1;
    triangle[0].z = 5;

    triangle[1].color = 0x00ff0000;
    triangle[1].x = 0;
    triangle[1].y = -1;
    triangle[1].z = 5;

    triangle[2].color = 0x0000ff00;
    triangle[2].x = 1;
    triangle[2].y = 1;
    triangle[2].z = 5;

    rot = 0;
}

Triangle::~Triangle() {
    delete (triangle);
}

void Triangle::Render() {
    rot += 0.05;
    sceGumMatrixMode(GU_MODEL);
    sceGumLoadIdentity();
    sceGumRotateY(rot);

    sceGumDrawArray(GU_TRIANGLES, GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D,
                    3, nullptr, triangle);
}