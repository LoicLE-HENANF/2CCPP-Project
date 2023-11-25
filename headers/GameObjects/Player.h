//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_PLAYER_H
#define INC_2CCPP_PROJECT_PLAYER_H

#include "raylib.h"
#include "Tiles.h"
#include <string>

// Our player class
class Player {
private:
    std::string name;
    Color color;

public:
    Player() : name(""), color(WHITE) {};
    ~Player() = default;

    [[nodiscard]] Color GetColor() const;

    void SetColor(Color _color);
};


#endif //INC_2CCPP_PROJECT_PLAYER_H
