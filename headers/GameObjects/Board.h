//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BOARD_H
#define INC_2CCPP_PROJECT_BOARD_H

#include <cassert>
#include <iostream>
#include "Players.h"
#include "Tile.h"
#include "../Settings.h"
#include "Cell.h"

class Board {
public:
    // Cell class only used in board, its implementation can be found in the Board.cpp file


    Board(): boardPos(settings::boardPosition),
            width(settings::boardSize.GetX()),
            height(settings::boardSize.GetY()),
            padding(settings::padding),
            cellSize(settings::cellSize){
        assert(width > 0 && height > 0); // If assertion triggers : the width or height is below 0
        assert(cellSize > 0); // If assertion triggers : the width or height is below 0
        cells.resize(width*height);
        std::cout << "nb of cells: " << cells.size() << std::endl;
    };

    Board& operator=(const Board& other){ return *this;}

    void ClearBoard(){
        cells.clear();
        cells.resize(width*height);
    }
    void InitBoard(const Players& players);
    void SetCells(Tile tile, Vec2<int> position);
    void SetCell(Vec2<int> position, Color c);
    Vec2<int> GetBoardPos() const {
        return boardPos;
    };
    void DrawCell(Vec2<int> position) const;
    void DrawCell(Vec2<int> position, Color c) const;
    void DrawBorder() const;
    void Draw() const;

    // getters, setters
    void SetBoardPos(Vec2<int> newBoardPos){
        boardPos = newBoardPos;
    };
    void SetBoardSize(Vec2<int> boardSize){
        width = boardSize.GetX();
        height = boardSize.GetY();
        cells.resize(width*height);
    };
    void SetBoardPadding(int newPadding){ padding = newPadding; };
    void SetBoardCellSize(int newCellSize){ cellSize = newCellSize; };
    Vec2<int> GetSize() const;

    // Tile placement
    bool PlaceTile(Tile tile, Vec2<int> position);

    bool CanPlaceCell(Vec2<int> position, Color color);

private:
    std::vector<Cell> cells;
    Vec2<int> boardPos;

    int width;
    int height;
    int padding;
    int cellSize;

    bool CanPlaceTile(Tile tile, Vec2<int> position);
    bool NeighboringTile(Tile tile, Vec2<int> position);

    Cell &GetCell(int x, int y);

    bool OposingTile(Tile tile, Vec2<int> position);
};


#endif //INC_2CCPP_PROJECT_BOARD_H
