//
// Created by lehen on 14/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BUTTON_H
#define INC_2CCPP_PROJECT_BUTTON_H


#include <utility>
#include <string>

#include "../Utilities/Vec2.h"
#include "raylib.h"


class Button {
public:
    Button(Vec2<int> buttonPos, Vec2<int> buttonSize, std::string text, Color color) :
        text(std::move(text)),
        color(color),
        buttonPos(buttonPos),
        buttonSize(buttonSize)
        {

        };
    ~Button() = default;

    void Draw();
    int CanClick();
    bool DetectClick();

    void TurnOn(){
        activated = true;
    }
    void TurnOff(){
        activated = false;
    }


private:
    std::string text;
    Color color;
    Vec2<int> buttonPos;
    Vec2<int> buttonSize;

    bool activated = true;
};


#endif //INC_2CCPP_PROJECT_BUTTON_H
