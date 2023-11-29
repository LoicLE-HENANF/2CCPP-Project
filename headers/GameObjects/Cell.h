//
// Created by lehen on 27/11/2023.
//

#ifndef INC_2CCPP_PROJECT_CELL_H
#define INC_2CCPP_PROJECT_CELL_H


#include "raylib.h"
#include "../Utilities/Vec2.h"

class Cell
{
public:
    Cell();
    void Remove();
    void SetColor(Color color);
    Color GetColor() const;

    int Placed();
    void DrawCellFollow(Color color);

    void SetBonus(const int i);

    int GetIsBonus() const;

    void SetTaken(bool _taken);

    bool GetTaken();

    void SetIsStone(bool value);

private:
    Color c;
    bool placed = false;
    int isBonus = 0;
    bool taken = false;
    bool isStone = false;
};


#endif //INC_2CCPP_PROJECT_CELL_H
