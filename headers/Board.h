//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BOARD_H
#define INC_2CCPP_PROJECT_BOARD_H

#include <vector>
#include "raylibWrapper.h"
#include "Vec2.h"

class Board {
private:
    // Cell class only used in board, its implementation can be found in the Board.cpp file
    class Cell
            {
        public:
            Cell();
            void Remove();
            void SetColor(Color color);
            Color GetColor() const;
            bool Exists() const;

        private:
            bool exists;
            Color c;
            };
public:
    Board(): width(0), height(0), padding(0), cellSize(0){};
    Board(Vec2<int> screenPos, Vec2<int> size, int cellSize, int padding);

    Board& operator=(const Board& other){ return *this;}

    void SetCell(Vec2<int> position, Color c);
    void DrawCell(Vec2<int> position) const;
    void DrawBorder() const;
    void Draw() const;
    bool CellExists(Vec2<int> position) const;
private:
    std::vector<Cell> cells;
    Vec2<int> screenPos{};
    const int width;
    const int height;
    const int padding;
    const int cellSize;

};


#endif //INC_2CCPP_PROJECT_BOARD_H
