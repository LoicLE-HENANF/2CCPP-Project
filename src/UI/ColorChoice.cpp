//
// Created by lehen on 25/11/2023.
//

#include "../../headers/UI/ColorChoice.h"
#include "../../headers/GameEngine/RaylibWrapper.h"

void ColorChoice::Draw() {
    GameEngine::DrawRectangle(position, size, GetColor());
}

bool ColorChoice::CanClick() {
    if (GameEngine::CheckCollisionPointRec(GameEngine::GetMousePosition(), position, size)){
        return true;
    }
    return false;
}


Color ColorChoice::DetectClick() {
    if (CanClick() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        NextColor();
    }
    return GetColor();
}
