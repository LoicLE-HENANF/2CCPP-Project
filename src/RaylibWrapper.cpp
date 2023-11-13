//
// Created by lehen on 12/11/2023.
//

#include "../headers/RaylibWrapper.h"
#include <cassert>

void GameEngine::DrawRectangle(Vec2<int> position, Vec2<int> size, Color color)
{
    assert(position.GetX() >= 0 && position.GetY() >= 0 &&
    position.GetX() < GetScreenWidth() && position.GetY() < GetScreenHeight()); // If asssertion triggers : Trying to draw ouside of the screen
    DrawRectangle(position.GetX(),
                  position.GetY(),
                  size.GetX(),
                  size.GetY(),
                  color);
}
void GameEngine::DrawRectangleLinesEx(Vec2<int> position, Vec2<int> size, int lineThickness, Color color)
{
    assert(position.GetX() >= 0 && position.GetY() >= 0 &&
           position.GetX() < GetScreenWidth() && position.GetY() < GetScreenHeight()); // If asssertion triggers : Trying to draw ouside of the screen
    DrawRectangleLinesEx({(float)position.GetX(),(float)position.GetY(),(float)size.GetX(),(float)size.GetY()},
                         (float)lineThickness,
                  color);
}

