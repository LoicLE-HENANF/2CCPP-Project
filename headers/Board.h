//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BOARD_H
#define INC_2CCPP_PROJECT_BOARD_H

#include <vector>
#include "RaylibWrapper.h"
#include "Vec2.h"
#include "Settings.h"

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

        private:
            Color c;
            };
public:
    Board(): boardPos(settings::boardPosition), width(0), height(0), padding(settings::padding), cellSize(settings::cellSize){};
    Board(Vec2<int> boardPos, Vec2<int> size, int cellSize, int padding);

    Board& operator=(const Board& other){ return *this;}

    void SetCell(Vec2<int> position, Color c);
    Vec2<int> GetBoardPos() const { return boardPos;}
    void DrawCell(Vec2<int> position) const;
    void DrawCell(Vec2<int> position, Color c) const;
    void DrawBorder() const;
    void Draw() const;

    // getters, setters
    void SetBoardPos(Vec2<int> newBoardPos){ boardPos = newBoardPos; };
    void SetBoardSize(Vec2<int> boardSize){
        width = boardSize.GetX();
        height = boardSize.GetY();
        cells.resize(width*height);
    };

    void SetBoardPadding(int newPadding){ padding = newPadding; };
    void SetBoardCellSize(int newCellSize){ cellSize = newCellSize; };

private:
    std::vector<Cell> cells;
    Vec2<int> boardPos;
    int width;
    int height;
    int padding;
    int cellSize;

};


#endif //INC_2CCPP_PROJECT_BOARD_H
