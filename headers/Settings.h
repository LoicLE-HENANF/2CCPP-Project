//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_SETTINGS_H
#define INC_2CCPP_PROJECT_SETTINGS_H

#include "Vec2.h"

namespace settings
{
    //inline makes the linker choose a definition of these constants as the main one and link the others to it right after the pre process has finished
    // constexpr = calculate at compile time (not at running time)
    // Game settings
    inline const std::string title = "Laying Grass";
    inline constexpr int screenWidth = 800;
    inline constexpr int screenHeight = 600;
    inline constexpr int fps = 60;

    // Board settings
    inline constexpr int cellSize = 20;
    inline constexpr int padding = 2;
    inline constexpr  Vec2<int> boardPosition{250, 70};
    inline constexpr  Vec2<int> boardSize{20, 20};
}

#endif //INC_2CCPP_PROJECT_SETTINGS_H