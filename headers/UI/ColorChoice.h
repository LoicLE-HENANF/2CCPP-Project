//
// Created by lehen on 25/11/2023.
//

#ifndef INC_2CCPP_PROJECT_COLORCHOICE_H
#define INC_2CCPP_PROJECT_COLORCHOICE_H


#include <iostream>
#include "../Utilities/Vec2.h"
#include "raylib.h"

class ColorChoice { ;
public:
    ColorChoice(Vec2<int> position,
                Vec2<int> size)
            :
            position(position),
            size(size)
    {}
    ~ColorChoice() = default;

    void Draw();

    bool CanClick();
    Color DetectClick();

private:
    Vec2<int> position;
    Vec2<int> size;

    enum class AllColor {
        RED_,
        BLUE_,
        GREEN_,
        PURPLE_,
        YELLOW_,
        ORANGE_,
        BLACK_
    };

    AllColor colorChosen = AllColor::RED_;
    Color GetColor(){
        switch (colorChosen) {
            case AllColor::RED_:
                return RED;
            case AllColor::BLUE_:
                return BLUE;
            case AllColor::GREEN_:
                return GREEN;
            case AllColor::PURPLE_:
                return PURPLE;
            case AllColor::YELLOW_:
                return YELLOW;
            case AllColor::ORANGE_:
                return ORANGE;
            case AllColor::BLACK_:
                return BLACK;
            default:
                std::cout << "default color reached" << std::endl;
                return WHITE;
        }
    };

    void NextColor(){
        colorChosen = AllColor((int(colorChosen) + 1) % 7); // change to the number of color in AllColor
    };
};


#endif //INC_2CCPP_PROJECT_COLORCHOICE_H
