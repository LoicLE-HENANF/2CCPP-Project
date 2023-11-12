//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BOARD_H
#define INC_2CCPP_PROJECT_BOARD_H

#include "raylib.h"
#include "vector"

class Board {
private:
    // Cell class only used in board, its implementation can be found in the Board.cpp file
    class Cell
            {
        public:
            Cell();
            void SetColor(Color color);
            Color GetColor() const;
            void Remove();
        private:
            bool exists;
            Color c;
            };
public:
    Board(int windowX, int windowY, int width, int height, int cellSize);

    void SetCell(int x, int y, Color c);
    void DrawCell(int x, int y) const;
    void Draw() const;
private:
    std::vector<Cell> cells;
    int windowX;
    int windowY;
    const int width;
    const int height;
    const int cellSize;

};


#endif //INC_2CCPP_PROJECT_BOARD_H
