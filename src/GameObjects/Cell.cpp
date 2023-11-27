//
// Created by lehen on 27/11/2023.
//

#include "../../headers/GameObjects/Cell.h"
#include "../../headers/Utilities/Vec2.h"
#include "../../headers/GameEngine/RaylibWrapper.h"
#include "../../headers/Settings.h"

Cell::Cell()
        :
        c(settings::cellBaseColor)
{

}

void Cell::SetColor(Color color) {
    c = color;
    placed = true;
}

Color Cell::GetColor() const {
    return c;
}

int Cell::Placed() {
    return placed;
}

void Cell::DrawCellFollow(Vec2<int> _boardSize, Color color) {
    Vec2<int> mousePos = GameEngine::GetMousePosition();
    Vec2<int> pos = mousePos - (mousePos % _boardSize);
    GameEngine::DrawRectangle(pos,
                              Vec2<int>{settings::cellSize, settings::cellSize} - settings::padding,
                              color);
}