//
// Created by lehen on 14/11/2023.
//

#include <iostream>
#include "../../headers/UI/Button.h"
#include "../../headers/GameEngine/RaylibWrapper.h"

void Button::Draw() {

    GameEngine::DrawRectangle(buttonPos, buttonSize, color);
//    GameEngine::DrawText(text, buttonPos, 20, color);
    DrawText(text.c_str(), buttonPos.GetX() + 5, buttonPos.GetY() + 5, 20, BLACK);
}

int Button::CanClick() {
    return GameEngine::CheckCollisionPointRec(GameEngine::GetMousePosition(),
                                              buttonPos, buttonSize);
}

bool Button::DetectClick() {
    if(CanClick()){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "button pressed." << std::endl;
        }
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            return true;
        }
    }
    return false;
}

