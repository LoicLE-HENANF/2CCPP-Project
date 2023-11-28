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

private:
    Color c;
    bool placed = false;
};


#endif //INC_2CCPP_PROJECT_CELL_H
