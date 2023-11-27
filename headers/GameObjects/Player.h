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
    bool isAI = false;
    bool isDistant = false;

public:
    Player() : name(""), color(WHITE) {};
    ~Player() = default;

    [[nodiscard]] Color GetColor() const;
    void SetColor(Color _color);

    [[nodiscard]] bool GetIsAI() const{
        return isAI;
    };
    void SetIsAI(bool _isAI){
        isAI = _isAI;
    };

    [[nodiscard]] bool GetIsDistant() const{
        return isDistant;
    };
    void SetIsDistant(bool _isDistant){
        isAI = _isDistant;
    };

    Tiles& GetTiles();

    std::string GetPlayerName();

    void SetName(std::string _name);
};


#endif //INC_2CCPP_PROJECT_PLAYER_H
