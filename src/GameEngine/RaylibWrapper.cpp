//
// Created by lehen on 12/11/2023.
//

#include "../../headers/GameEngine/RaylibWrapper.h"
#include <cassert>

namespace GameEngine{

    void DrawRectangle(Vec2<int> position, Vec2<int> size, Color color) {
//        assert(position.GetX() >= 0 && position.GetY() >= 0 &&
//               position.GetX() < GetScreenWidth() &&
//               position.GetY() < GetScreenHeight()); // If asssertion triggers : Trying to draw ouside of the screen
        DrawRectangle(position.GetX(),
                      position.GetY(),
                      size.GetX(),
                      size.GetY(),
                      color);
    }

    void DrawRectangleLinesEx(Vec2<int> position, Vec2<int> size, int lineThickness, Color color) {
//        assert(position.GetX() >= 0 && position.GetY() >= 0 &&
//               position.GetX() < GetScreenWidth() &&
//               position.GetY() < GetScreenHeight()); // If asssertion triggers : Trying to draw ouside of the screen
        DrawRectangleLinesEx(
                {(float) position.GetX(), (float) position.GetY(), (float) size.GetX(), (float) size.GetY()},
                (float) lineThickness,
                color);
    }

    Vec2<int> GetMousePosition() {
        return {GetMouseX(), GetMouseY()};
    }

    bool CheckCollisionPointRec(const Vec2<int> point, const Vec2<int> position, const Vec2<int> size) {
        Vector2 targetPoint{static_cast<float>(point.GetX()), static_cast<float>(point.GetY())};
        Rectangle rec{static_cast<float>(position.GetX()),
                      static_cast<float>(position.GetY()),
                      static_cast<float>(size.GetX()),
                      static_cast<float>(size.GetY())};
        return CheckCollisionPointRec(targetPoint, rec);
    }

    void DrawText(const std::string& text, Vec2<float> position, int fontSize, Color color){
        DrawText(text.c_str(), (int)position.GetX(), (int)position.GetY(), fontSize, color);
    }

    void DrawTriangleUp(Vec2<int> position, Vec2<int> size, Color color){
        DrawTriangle(Vector2{static_cast<float>(position.GetX() + size.GetX()/2),
                             static_cast<float>(position.GetY())},
                     Vector2{static_cast<float>(position.GetX()),
                             static_cast<float>(position.GetY() + size.GetY())},
                     Vector2{static_cast<float>(position.GetX() + size.GetX()),
                             static_cast<float>(position.GetY() + size.GetY())},
                     color);
    }
    void DrawTriangleDown(Vec2<int> position, Vec2<int> size, Color color){
        DrawTriangle(Vector2{static_cast<float>(position.GetX()),
                             static_cast<float>(position.GetY())},
                     Vector2{static_cast<float>(position.GetX() + size.GetX()/2),
                             static_cast<float>(position.GetY() + size.GetY())},
                     Vector2{static_cast<float>(position.GetX() + size.GetX()),
                             static_cast<float>(position.GetY())},

                     color);
    }

}