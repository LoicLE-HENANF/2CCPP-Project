//
// Created by lehen on 15/11/2023.
//

#include <iostream>
#include <raylib.h>

#include "../../headers/UI/NumberChoice.h"
#include "../../headers/RaylibWrapper.h"

//using namespace GameEngine;

void NumberChoice::Draw() {
    // Draw background
    GameEngine::DrawRectangle(position,size,primaryColor);
    // draw arrows
    GameEngine::DrawTriangleUp(trianglePosUp,
                             triangleSizeUp,
                             secondaryColor
                             );
    GameEngine::DrawTriangleDown(trianglePosDown,
                               triangleSizeDown,
                               secondaryColor
    );
    // Draw value
    DrawText(std::to_string(value).c_str(),
             numberPos.GetX(),
             numberPos.GetY(),
             fontSize,
             secondaryColor);
}

bool NumberChoice::CanClickArrowUp() {
    return GameEngine::CheckCollisionPointRec(GameEngine::GetMousePosition(),
                                              trianglePosUp, triangleSizeUp);
}

bool NumberChoice::CanClickArrowDown() {
    return GameEngine::CheckCollisionPointRec(GameEngine::GetMousePosition(),
                                              trianglePosDown, triangleSizeDown);
}

void NumberChoice::DetectClick() {
    if (CanClickArrowDown()){
        // -
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "Arrow of number choice clicked: -" << std::endl;
        }
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            if (value > minimum){
                value -= 1;
            }else{
                value = maximum;
            }

        }
    }
    if (CanClickArrowUp()){
        // +
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "Arrow of number choice clicked: +" << std::endl;
        }
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            if (value < maximum){
                value += 1;
            }else{
                value = minimum;
            }

        }
    }

}
