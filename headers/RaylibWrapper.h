//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_RAYLIBWRAPPER_H
#define INC_2CCPP_PROJECT_RAYLIBWRAPPER_H

#include "Vec2.h"
#include <raylib.h>

namespace GameEngine {
    //raylib function:
    // void DrawRectangle(int posX, int posY, int width, int height, Color color)
    // ours:
    void DrawRectangle(Vec2<int> position, Vec2<int> size, Color color);
    //raylib function:
    // void DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color)
    // ours:
    void DrawRectangleLinesEx(Vec2<int> position, Vec2<int> size, int lineThickness, Color color);

    Vec2<int> GetMousePosition();

    bool CheckCollisionPointRec(Vec2<int> point, Vec2<int> position, Vec2<int> size);
}


#endif //INC_2CCPP_PROJECT_RAYLIBWRAPPER_H
