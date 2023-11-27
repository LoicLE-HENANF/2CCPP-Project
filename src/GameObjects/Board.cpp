//
// Created by lehen on 12/11/2023.
//



#include "../../headers/GameObjects/Board.h"
#include <cassert>
#include "../../headers/GameEngine/RaylibWrapper.h"
#include <algorithm>

using namespace settings;

// Board implementation
void Board::InitBoard(const Players& players) {
    // clearing board
    cells.clear();
    cells.resize(width*height);
    // determining starting positions
    std::vector<Vec2<int>> startingPos;

    // generation des emplacements de départ
    while(startingPos.size() < players.GetSize()) {
        Vec2<int> newPos {
                std::rand() % width,
                std::rand() % height
        };

        // check if element in vector
        if (std::find(startingPos.begin(), startingPos.end(), newPos) == startingPos.end()){
            startingPos.push_back(newPos);
        }
    }

    // placing starting cells
    for (int i = 0; i < players.GetSize(); ++i) {
        Color color = players.GetPlayer(i).GetColor();
        Vec2<int> position = startingPos[i];
        cells[position.GetY() * width + position.GetX()].SetColor(color);
    }



    // determining bonuses positions

    //
}

void Board::SetCell(Vec2<int> position, Color c) {
    if(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height){
        cells[position.GetY() * width + position.GetX()].SetColor(c);

    }
}

void Board::DrawCell(Vec2<int> position) const {
    Color c = cells[position.GetY() * width + position.GetX()].GetColor();
    DrawCell(position, c);
}

void Board::DrawCell(Vec2<int> position, Color c) const {
    assert(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height); // If assertion triggers : x or y is out of bounds
    Vec2<int> origin = boardPos + padding + (position * cellSize);
    GameEngine::DrawRectangle(origin,
                              Vec2<int>{cellSize, cellSize} - padding,
                              c);
}

void Board::DrawBorder() const {
    GameEngine::DrawRectangleLinesEx(boardPos - (cellSize / 2),
                                     Vec2{width*cellSize, height*cellSize} + cellSize + padding,
                                     cellSize/2,
                                     BLACK);
}

void Board::Draw() const {
    // Drawing cells
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            DrawCell(Vec2<int>{x, y});
        }
    }
    // Drawing board borders
    DrawBorder();
}

void Board::SetCells(Tile tile, Vec2<int> position) {
    for (int x = 0; x < tile.GetDimension(); ++x) {
        for (int y = 0; y < tile.GetDimension(); ++y) {
            if(tile.GetValue(x, y)){
                SetCell({position.GetX() + x, position.GetY() + y}, tile.GetColor());
            }
        }
    }
}

bool Board::CanPlaceTile(Tile tile, Vec2<int> position) {
    // check if tile can be place by comparing tile 1 and 0 to the clicked groupe of cells
    for (int x = 0; x < tile.GetDimension(); ++x) {
        for (int y = 0; y < tile.GetDimension(); ++y) {
            // check if ousite the board
            if (position.GetX() + x >= 0 && position.GetY() + y >= 0 && position.GetX() + x < width && position.GetY() + y < height){
                if (tile.GetValue(x, y) && (cells[(position.GetY() + y) * width + (position.GetX() + x)].Placed())){
                    return false;
                }
            }else{
                if (tile.GetValue(x, y) == 0){
                    continue;
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}

bool Board::PlaceTile(Tile tile, Vec2<int> position) {
    if (CanPlaceTile(tile, position) && NeighboringTile(tile, position)){
        SetCells(tile, position);
        return true;
    }
    return false;
}

Vec2<int> Board::GetSize() const {
    return {width, height};
}

bool Board::NeighboringTile(Tile tile, Vec2<int> position) {
    bool cellFound = false;
    for (int y = 0; y < tile.GetDimension(); ++y) {
        for (int x = 0; x < tile.GetDimension(); ++x) {
            Color tileColor = tile.GetColor();
            Color cellColor = GetCell(position.GetX() + x, position.GetY() + y).GetColor();
            Color cellUpColor = cellBaseColor;
            Color cellDownColor = cellBaseColor;
            Color cellLeftColor = cellBaseColor;
            Color cellRightColor = cellBaseColor;

            if (position.GetY() + y + 1 < height){
                cellUpColor = GetCell(position.GetX() + x, position.GetY() + y+1).GetColor();
            }
            if (position.GetY() + y - 1 >= 0){
                cellDownColor = GetCell(position.GetX() + x, position.GetY() + y-1).GetColor();
            }
            if (position.GetX() + x + 1 < width){
                cellLeftColor = GetCell(position.GetX() + x+1, position.GetY() + y).GetColor();
            }
            if (position.GetX() + x - 1 >= 0){
                cellRightColor = GetCell(position.GetX() + x-1, position.GetY() + y).GetColor();
            }

            // si la case est de la meme couleur que la tile
            bool checkTileCellColor = GameEngine::ColorEquals(tileColor, cellColor);
            bool checkTileCellUpColor = GameEngine::ColorEquals(tileColor, cellUpColor);
            bool checkTileCellDownColor = GameEngine::ColorEquals(tileColor, cellDownColor);
            bool checkTileCellLeftColor = GameEngine::ColorEquals(tileColor, cellLeftColor);
            bool checkTileCellRightColor = GameEngine::ColorEquals(tileColor, cellRightColor);

            // si la case est de la couleur de base des cases
            bool checkBaseCellColor = GameEngine::ColorEquals(cellBaseColor, cellColor);
            bool checkBaseCellUpColor = GameEngine::ColorEquals(cellBaseColor, cellUpColor);
            bool checkBaseCellDownColor = GameEngine::ColorEquals(cellBaseColor, cellDownColor);
            bool checkBaseCellLeftColor = GameEngine::ColorEquals(cellBaseColor, cellLeftColor);
            bool checkBaseCellRightColor = GameEngine::ColorEquals(cellBaseColor, cellRightColor);
            
            std::cout << "check for neighbor tile number: " << y * tile.GetDimension() + x << std::endl;

            // si la case de la tile est vide (0) et que ca couleur correspond
            if (!tile.GetValue(x, y) && checkTileCellColor){
                cellFound = true;
            }else if(tile.GetValue(x, y) && (checkTileCellUpColor
                                            || checkTileCellDownColor
                                            || checkTileCellLeftColor
                                            || checkTileCellRightColor)){
                cellFound = true;
            } // si la case est d'une autre couleur que la couleur de base
            else if(!tile.GetValue(x, y) && !checkBaseCellColor){
                std::cout << "cant place here because tileValue = 0 and different color inside" << std::endl;
                return false;
            }else if(tile.GetValue(x, y) && (!checkBaseCellUpColor
                                             || !checkBaseCellDownColor
                                             || !checkBaseCellLeftColor
                                             || !checkBaseCellRightColor)){
                std::cout << "cant place here because tileValue = 1 and different color detected" << std::endl;
                return false;
            }

        }
    }
    if (cellFound){
        return true;
    }
    return false;
}

Cell &Board::GetCell(int x, int y) {
    return cells[y * width + x];
}




