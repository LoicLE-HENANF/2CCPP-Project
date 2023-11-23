//
// Created by lehen on 15/11/2023.
//

#include <iostream>
#include "../../headers/UI/CheckBox.h"
#include "../../headers/GameEngine/RaylibWrapper.h"

using namespace GameEngine;

void CheckBox::Draw() {
    DrawRectangle(position, size, colorEdge);
    if(value){
        DrawRectangle(position + padding, size - padding*2, colorIn);
    }
}

bool CheckBox::CanClick() {
    return GameEngine::CheckCollisionPointRec(GameEngine::GetMousePosition(),
                                              position, size);
}

void CheckBox::DetectClick() {
    if(CanClick()){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "checkBox pressed." << std::endl;
        }
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            value = !value;
        }

    }
}
