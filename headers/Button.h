//
// Created by lehen on 14/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BUTTON_H
#define INC_2CCPP_PROJECT_BUTTON_H


#include <utility>

#include "Vec2.h"
#include "GameState.h"

class Button {
public:
    Button(Vec2<int> buttonPos, Vec2<int> buttonSize, std::string text, Color color, GameState* targetState) :
        text(text),
        color(color),
        buttonPos(buttonPos),
        buttonSize(buttonSize),
        targetState(targetState)
        {

        };
    ~Button() = default;

    void Draw();
    int CanClick();
    bool DetectClick();


private:
    GameState* targetState;
    std::string text;
    Color color;
    Vec2<int> buttonPos;
    Vec2<int> buttonSize;
};


#endif //INC_2CCPP_PROJECT_BUTTON_H
