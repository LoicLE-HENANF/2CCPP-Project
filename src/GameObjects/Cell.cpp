//
// Created by lehen on 27/11/2023.
//

#include "../../headers/GameObjects/Cell.h"
#include "../../headers/Utilities/Vec2.h"
#include "../../headers/GameEngine/RaylibWrapper.h"
#include "../../headers/Settings.h"

Cell::Cell()
        :
        c(settings::cellBaseColor),
        placed(false)
{

}

void Cell::SetColor(Color color) {
    c = color;
    placed = true;
    isStone = false;
    isBonus = 0;
}

Color Cell::GetColor() const {
    return c;
}

int Cell::Placed() {
    return placed;
}

void Cell::DrawCellFollow(Color color) {
    Vec2<int> mousePos = GameEngine::GetMousePosition();
    Vec2<int> pos = mousePos - (mousePos % settings::cellSize);
    GameEngine::DrawRectangle(pos + settings::padding,
                              Vec2<int>{settings::cellSize, settings::cellSize} - settings::padding,
                              color);
}

void Cell::SetBonus(const int i) {
    isBonus = i;
    placed = true;
}

int Cell::GetIsBonus() const {
    return isBonus;
}

//void Cell::SetTaken(bool _taken) {
//    taken = _taken;
//}

//bool Cell::GetTaken() {
//    return taken;
//}

void Cell::SetIsStone(bool value) {
    isStone = value;
    placed = true;
}

bool Cell::IsStone() const {
    return isStone;
}

