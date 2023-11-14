//
// Created by lehen on 14/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BUTTON_H
#define INC_2CCPP_PROJECT_BUTTON_H


#include "Vec2.h"
#include "GameState.h"

class Button {
public:
    Button(Vec2<int> buttonPos, Vec2<int> buttonSize, std::string text, Color color) :
        text(text),
        color(color),
        buttonPos(buttonPos),
        buttonSize(buttonSize)
        {

        };
    ~Button() = default;

    void Draw();
    int CanClick();
    void DetectClick();


private:
    std::string text;
    Color color;
    Vec2<int> buttonPos;
    Vec2<int> buttonSize;
};


#endif //INC_2CCPP_PROJECT_BUTTON_H
