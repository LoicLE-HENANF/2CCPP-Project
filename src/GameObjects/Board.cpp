//
// Created by lehen on 12/11/2023.
//



#include "../../headers/GameObjects/Board.h"
#include <cassert>
#include "../../headers/GameEngine/RaylibWrapper.h"
#include <algorithm>
#include <cmath>

using namespace settings;

// Board implementation
void Board::InitBoard(const Players& players) {
    // clearing board
    cells.clear();
    cells.resize(width*height);
    // determining bonuses positions
    std::vector<Vec2<int>> BonusesPos;
    int numberOfStone = (int)players.GetSize();
    int numberOfRob = (int)std::ceil(players.GetSize() * 0.5);
    int numberOfTEC = (int)std::ceil(players.GetSize() * 1.5);

//     generation des emplacements de départ random (plus d'actu)
    while(BonusesPos.size() < numberOfRob
                            + numberOfStone
                            + numberOfTEC) {
        Vec2<int> newPos {
                std::rand() % width,
                std::rand() % height
        };

        // check if element in vector
        if (std::find(BonusesPos.begin(), BonusesPos.end(), newPos) == BonusesPos.end()){
            BonusesPos.push_back(newPos);
        }
    }

    for (int i = 0; i < numberOfStone; ++i) {
        Vec2<int> position = BonusesPos[i];
        cells[position.GetY() * width + position.GetX()].SetColor(settings::bonusStone);
    }
    for (int i = numberOfStone; i < numberOfStone + numberOfRob; ++i) {
        Vec2<int> position = BonusesPos[i];
        cells[position.GetY() * width + position.GetX()].SetColor(settings::bonusRobbery);
    }
    for (int i = numberOfStone + numberOfRob; i < numberOfStone + numberOfRob + numberOfTEC; ++i) {
        Vec2<int> position = BonusesPos[i];
        cells[position.GetY() * width + position.GetX()].SetColor(settings::bonusTEC);
    }

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

int Board::PlaceTile(Tile tile, Vec2<int> position) {
    int returnValue = 0;

    if (CanPlaceTile(tile, position)&& NeighboringTile(tile, position)){
        SetCells(tile, position);
        returnValue++;
    }
    return returnValue;
}

Vec2<int> Board::GetSize() const {
    return {width, height};
}

bool Board::NeighboringTile(Tile tile, Vec2<int> position) {
    bool cellFound = false;
    bool otherCellFound = false;
    for (int y = 0; y < tile.GetDimension(); ++y) {
        for (int x = 0; x < tile.GetDimension(); ++x) {
            Color tileColor = tile.GetColor();
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
            bool checkTileCellUpColor = GameEngine::ColorEquals(tileColor, cellUpColor);
            bool checkTileCellDownColor = GameEngine::ColorEquals(tileColor, cellDownColor);
            bool checkTileCellLeftColor = GameEngine::ColorEquals(tileColor, cellLeftColor);
            bool checkTileCellRightColor = GameEngine::ColorEquals(tileColor, cellRightColor);

            // si la case est de la couleur de base des cases
            bool checkBaseCellUpColor = GameEngine::ColorEquals(cellBaseColor, cellUpColor);
            bool checkBaseCellDownColor = GameEngine::ColorEquals(cellBaseColor, cellDownColor);
            bool checkBaseCellLeftColor = GameEngine::ColorEquals(cellBaseColor, cellLeftColor);
            bool checkBaseCellRightColor = GameEngine::ColorEquals(cellBaseColor, cellRightColor);


            // si les cases autour de la case en question sont de la meme couleur que la tile
            if(!tile.GetValue(x, y)){
//                std::cout << "vide" << std::endl;
            } else if(tile.GetValue(x, y) && (checkTileCellUpColor
                                              || checkTileCellDownColor
                                              || checkTileCellLeftColor
                                              || checkTileCellRightColor)){
                cellFound = true;
            }
            // si les cases autour de la case ne sont ni de la meme couleur que tile, ni de la couleur de base
            if(!tile.GetValue(x, y)){
//                std::cout << "vide" << std::endl;
            }else if(tile.GetValue(x, y) && (!checkTileCellUpColor && !checkBaseCellUpColor
                                            || !checkTileCellDownColor && !checkBaseCellDownColor
                                            || !checkTileCellLeftColor && !checkBaseCellLeftColor
                                            || !checkTileCellRightColor && !checkBaseCellRightColor)){
//                std::cout << "pos lol: "<< x << ", " << y << std::endl;
                otherCellFound = true;
            }
        }
    }
    if (otherCellFound){
        return false;
    }
    if (cellFound){
        return true;
    }
    return false;
}

Cell &Board::GetCell(int x, int y) {
    return cells[y * width + x];
}

bool Board::CanPlaceCell(Vec2<int> position) {
    bool checkBaseColor = GameEngine::ColorEquals(cells[position.GetY() * width + position.GetX()].GetColor(), cellBaseColor);

    bool checkIfDifCellUp = true;
    bool checkIfDifCellDown = true;
    bool checkIfDifCellRight = true;
    bool checkIfDifCellLeft = true;

    if (position.GetY()+1 < height){
        checkIfDifCellUp = GameEngine::ColorEquals(cells[(position.GetY()+1) * width + position.GetX()].GetColor(), cellBaseColor);
    }
    if (position.GetY()-1 >= 0){
        checkIfDifCellDown = GameEngine::ColorEquals(cells[(position.GetY()-1) * width + position.GetX()].GetColor(), cellBaseColor);

    }
    if (position.GetX()+1 < width){
        checkIfDifCellRight = GameEngine::ColorEquals(cells[(position.GetY()+1) * width + position.GetX()].GetColor(), cellBaseColor);

    }
    if (position.GetX()-1 >= 0){
        checkIfDifCellLeft = GameEngine::ColorEquals(cells[(position.GetY()+1) * width + position.GetX()].GetColor(), cellBaseColor);

    }

    if (checkBaseColor && checkIfDifCellUp && checkIfDifCellDown && checkIfDifCellRight && checkIfDifCellLeft){
        return true;
    }

    return false;
}

int Board::CheckForBonuses(Tile tile, Vec2<int> position) {
    for (int y = 0; y < tile.GetDimension(); ++y) {
        for (int x = 0; x < tile.GetDimension(); ++x) {
            Color cellUpColor = cellBaseColor;
            Color cellDownColor = cellBaseColor;
            Color cellLeftColor = cellBaseColor;
            Color cellRightColor = cellBaseColor;

            if (position.GetY() + y + 1 < height) {
                cellUpColor = GetCell(position.GetX() + x, position.GetY() + y + 1).GetColor();
            }
            if (position.GetY() + y - 1 >= 0) {
                cellDownColor = GetCell(position.GetX() + x, position.GetY() + y - 1).GetColor();
            }
            if (position.GetX() + x + 1 < width) {
                cellLeftColor = GetCell(position.GetX() + x + 1, position.GetY() + y).GetColor();
            }
            if (position.GetX() + x - 1 >= 0) {
                cellRightColor = GetCell(position.GetX() + x - 1, position.GetY() + y).GetColor();
            }

            // si la case est de la meme couleur que la couleur des TEC
            bool checkTECCellUpColor = GameEngine::ColorEquals(settings::bonusTEC, cellUpColor);
            bool checkTECCellDownColor = GameEngine::ColorEquals(settings::bonusTEC, cellDownColor);
            bool checkTECCellLeftColor = GameEngine::ColorEquals(settings::bonusTEC, cellLeftColor);
            bool checkTECCellRightColor = GameEngine::ColorEquals(settings::bonusTEC, cellRightColor);
        }
    }
}




