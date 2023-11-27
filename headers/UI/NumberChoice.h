//
// Created by lehen on 15/11/2023.
//

#ifndef INC_2CCPP_PROJECT_NUMBERCHOICE_H
#define INC_2CCPP_PROJECT_NUMBERCHOICE_H


#include "../Utilities/Vec2.h"
#include "raylib.h"

class NumberChoice {
public:
    NumberChoice(Vec2<int> position,
                 Vec2<int> size,
                 Color primaryColor,
                 Color secondaryColor,
                 int minimum,
                 int maximum)
                 :
                 position(position),
                 size(size),
                 primaryColor(primaryColor),
                 secondaryColor(secondaryColor),
                 minimum(minimum),
                 maximum(maximum)
                 {};
    ~NumberChoice() = default;

    void Draw();
    bool CanClickArrowUp();
    bool CanClickArrowDown();

    int DetectClick();

private:
    Vec2<int> position;
    Vec2<int> size;
    int fontSize = size.GetY() - 10;
    Color primaryColor = WHITE;
    Color secondaryColor = BLACK;
    int minimum;
    int maximum;
    int value = minimum;

    Vec2<int> numberPos = {position.GetX() + size.GetX()/2,
                           position.GetY() + 10};

    // triangle param
    Vec2<int> trianglePosDown = position + Vec2{0,size.GetY()/2} + size / 10;
    Vec2<int> triangleSizeDown = size/3;
    Vec2<int> trianglePosUp = position + size / 10;
    Vec2<int> triangleSizeUp = size/3;



};


#endif //INC_2CCPP_PROJECT_NUMBERCHOICE_H
