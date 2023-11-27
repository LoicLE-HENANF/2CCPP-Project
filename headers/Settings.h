//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_SETTINGS_H
#define INC_2CCPP_PROJECT_SETTINGS_H

#include "Utilities/Vec2.h"
#include <string>
#include "raylib.h"

namespace settings
{
    //inline makes the linker choose a definition of these constants as the main one and link the others to it right after the pre process has finished
    // constexpr = calculate at compile time (not at running time)
    // Game settings
    inline const std::string title = "Laying Grass";
    inline constexpr int screenWidth = 1200;
    inline constexpr int screenHeight = 1000;
    inline constexpr int fps = 60;

    inline constexpr int maxCharName = 15;

    // Board settings
    inline constexpr int cellSize = 20;
    inline constexpr int padding = 2;
    inline constexpr  Vec2<int> boardPosition{200, 100};
    inline constexpr  Vec2<int> boardSize{20, 20};
    inline constexpr Color bonusStone = GRAY;
    inline constexpr Color bonusRobbery = {255, 10, 10, 200};
    inline constexpr Color bonusTEC = WHITE;

    // Cell settings
    inline constexpr Color cellBaseColor = BROWN;
}

#endif //INC_2CCPP_PROJECT_SETTINGS_H
