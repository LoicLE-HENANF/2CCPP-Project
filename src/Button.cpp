//
// Created by lehen on 14/11/2023.
//

#include "../headers/Button.h"

void Button::Draw() {
    GameEngine::DrawRectangle(buttonPos, buttonSize, color);
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

