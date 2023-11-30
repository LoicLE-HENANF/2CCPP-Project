//
// Created by lehen on 12/11/2023.
//



#include "../../headers/GameObjects/Board.h"
#include <cassert>
#include "../../headers/GameEngine/RaylibWrapper.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <random>

using namespace settings;

// Board implementation
void Board::InitBoard(const Players& players) {
    // clearing board
    cells.clear();
    cells.resize(width*height);

    stoneTexture = LoadTexture(settings::stonePath);
    robberyTexture = LoadTexture(settings::robberyPath);
    TECTexture = LoadTexture(settings::TECPath);


    // determining bonuses positions
    std::vector<Vec2<int>> BonusesPos;
    int numberOfStone = (int)std::ceil(players.GetSize() * 0.5);
    int numberOfRob = (int)players.GetSize();
    int numberOfTEC = (int)std::ceil(players.GetSize() * 1.5);

    // rng maker
    std::random_device seeder;
    int min = 1;
    int max = width - 2;

    std::mt19937 rng(seeder());
    std::uniform_int_distribution<int> gen(min, max);

    // Generating bonus squares position
    while(BonusesPos.size() < numberOfRob
                            + numberOfStone
                            + numberOfTEC) {

        Vec2<int> newPos {
                gen(rng),
                gen(rng)
        };

        // check if element in vector
        if (std::find(BonusesPos.begin(), BonusesPos.end(), newPos) == BonusesPos.end()){
            BonusesPos.push_back(newPos);
        }
    }

    for (int i = 0; i < numberOfStone; ++i) {
        Vec2<int> position = BonusesPos[i];
        cells[position.GetY() * width + position.GetX()].SetBonus(settings::bonusStone);
    }
    for (int i = numberOfStone; i < numberOfStone + numberOfRob; ++i) {
        Vec2<int> position = BonusesPos[i];
        cells[position.GetY() * width + position.GetX()].SetBonus(settings::bonusRobbery);
    }
    for (int i = numberOfStone + numberOfRob; i < numberOfStone + numberOfRob + numberOfTEC; ++i) {
        Vec2<int> position = BonusesPos[i];
        cells[position.GetY() * width + position.GetX()].SetBonus(settings::bonusTEC);
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
    Vec2<int> origin = boardPos + padding + (position *settings::cellSize);
    GameEngine::DrawRectangle(origin,
                              Vec2<int>{cellSize,settings::cellSize} - padding,
                              c);
}

void Board::DrawBorder() const {
    GameEngine::DrawRectangleLinesEx(boardPos - (cellSize / 2),
                                     Vec2{width*cellSize, height*cellSize} +settings::cellSize + padding,
                                    settings::cellSize/2,
                                     BLACK);
}

void Board::Draw() const {
    // Drawing cells
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Vec2<int> origin = boardPos + padding + (Vec2<int>{ x,y } *settings::cellSize);
            if (cells[y * width + x].GetIsBonus()){
                switch (cells[y * width + x].GetIsBonus()) {
                    case 1:
                        GameEngine::DrawTexture(stoneTexture, origin);
                        break;
                    case 2:
                        // if cell is bonus = 2: draw texture for bonus 2
                        GameEngine::DrawTexture(robberyTexture, origin);
                        break;
                    case 3:
                        GameEngine::DrawTexture(TECTexture, origin);
                        // if cell is bonus = 3: draw texture for bonus 3
                        break;
                }
            }else if(cells[y * width + x].IsStone()){
                // if cell is stone: draw texture for stone
                GameEngine::DrawTexture(stoneTexture, origin);
            }else{
                // if cell is normal: draw with Draw function (based on color)
                DrawCell(Vec2<int>{x, y});
            }
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
    for (int y = 0; y < tile.GetDimension(); ++y) {
        for (int x = 0; x < tile.GetDimension(); ++x) {
            // check if ousite the board
            if (position.GetX() - x >= 0 && position.GetY() - y >= 0 && position.GetX() + x < width && position.GetY() + y < height){
                if (tile.GetValue(x, y) && (GetCell(position.GetX() + x, position.GetY() + y).Placed())){
                    std::cout << "CanPlaceTile: placed cell found" << std::endl;
                    return false;
                }
            }
//            else{
//                if (tile.GetValue(x, y) == 0){
//                    continue;
//                }
//                else{
//                    return false;
//                }
//            }
        }
    }
    std::cout << "CanPlaceTile: no problem" << std::endl;
    return true;
}

int Board::PlaceTile(Tile tile, Vec2<int> position) {
    if (CanPlaceTile(tile, position) && NeighboringTile(tile, position)){
        SetCells(tile, position);
        return true;
    }
    return false;
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
        std::cout << "other cell found" << std::endl;
        return false;

    }
    if (cellFound){
        return true;
    }
    std::cout << "no correct cell cell found" << std::endl;
    return false;
}

Cell &Board::GetCell(int x, int y) {
    return cells[y * width + x];
}

bool Board::CanPlaceCell(Vec2<int> position) {
    bool checkCellPlaced = cells[(position.GetY() * width) + position.GetX()].Placed();

    bool checkCellUpPlaced = false;
    bool checkCellDownPlaced = false;
    bool checkCellRightPlaced = false;
    bool checkCellLeftPlaced = false;

    if (position.GetY()+1 < height){
        checkCellUpPlaced = cells[(position.GetY()+1) * width + position.GetX()].Placed();
    }
    if (position.GetY()-1 >= 0){
        checkCellDownPlaced = cells[(position.GetY()-1) * width + position.GetX()].Placed();

    }
    if (position.GetX()+1 < width){
        checkCellRightPlaced = cells[(position.GetY()) * width + position.GetX()+1].Placed();

    }
    if (position.GetX()-1 >= 0){
        checkCellLeftPlaced = cells[(position.GetY()) * width + position.GetX()-1].Placed();

    }

    if (!checkCellPlaced && !checkCellUpPlaced && !checkCellDownPlaced && !checkCellRightPlaced && !checkCellLeftPlaced){
        return true;
    }

    return false;
}
// return a map of bonuses count that got capture by player
std::map<int, int> Board::CheckForBonuses(Color playerColor) {
    std::map<int, int> output = {{settings::bonusStone, 0},
                                 {settings::bonusRobbery, 0},
                                 {settings::bonusTEC, 0}};

    for (int y = 0; y < width; ++y) {
        for (int x = 0; x < height; ++x) {
            // si une case est un bonus
            if (cells[y * width + x].GetIsBonus() != 0){
                // recupération des couleurs des cases adjacentes
                Color cellUpColor = cellBaseColor;
                Color cellDownColor = cellBaseColor;
                Color cellLeftColor = cellBaseColor;
                Color cellRightColor = cellBaseColor;

                if (y + 1 < height){
                    cellUpColor = GetCell(x, y+1).GetColor();
                }
                if (y - 1 >= 0){
                    cellDownColor = GetCell(x, y-1).GetColor();
                }
                if (x + 1 < width){
                    cellLeftColor = GetCell(x+1, y).GetColor();
                }
                if (x - 1 >= 0){
                    cellRightColor = GetCell(x-1, y).GetColor();
                }
                bool checkTileCellUpColor = GameEngine::ColorEquals(playerColor, cellUpColor);
                bool checkTileCellDownColor = GameEngine::ColorEquals(playerColor, cellDownColor);
                bool checkTileCellLeftColor = GameEngine::ColorEquals(playerColor, cellLeftColor);
                bool checkTileCellRightColor = GameEngine::ColorEquals(playerColor, cellRightColor);

                if (checkTileCellUpColor && checkTileCellDownColor &&
                        checkTileCellLeftColor && checkTileCellRightColor){
                    output.at(cells[y * width + x].GetIsBonus()) += 1;
                    GetCell(x,y).SetColor(playerColor);
                }
            }
        }
    }
    return output;
}

bool Board::SetCellToStone(Vec2<int> position) {
    if(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height){
        if (!cells[position.GetY() * width + position.GetX()].Placed() && cells[position.GetY() * width + position.GetX()].GetIsBonus() == 0){
            cells[position.GetY() * width + position.GetX()].SetIsStone(true);
            return true;
        }
    }
    return false;
}

bool Board::Robbery(Vec2<int> position, Color playerColor) {
    if(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height){
        Color cellColor = cells[position.GetY() * width + position.GetX()].GetColor();
        bool colorCheck = GameEngine::ColorEquals(cellColor, playerColor);
        if (cells[position.GetY() * width + position.GetX()].Placed() && cells[position.GetY() * width + position.GetX()].GetIsBonus() == 0 && !colorCheck){
            cells[position.GetY() * width + position.GetX()].SetColor(playerColor);
            return true;
        }
    }
    return false;
}

bool Board::RemoveStone(Vec2<int> position) {
    if(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height){
        if (cells[position.GetY() * width + position.GetX()].IsStone()){
            cells[position.GetY() * width + position.GetX()].SetColor(settings::cellBaseColor);
            return true;
        }
    }
    return false;
}

bool Board::CheckIfStoneOnTheBoard() {
    bool stoneSquareFound = false;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (GetCell(x, y).IsStone()){
                stoneSquareFound = true;
            }
        }
    }
    return stoneSquareFound;
}

std::vector<int> Board::CalculateScore(std::vector<Player> &players) {
    std::vector<int> playersSquareSize;
    for (const Player& player: players) {
        int maxSquareSize = 0;
        // for every board coordinates
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {

                if (GameEngine::ColorEquals(GetCell(x,y).GetColor(), player.GetColor())) {
                    int squareSize = 1;
                    bool isSquare = true;
                    do {
                        if (x + squareSize >= width || y + squareSize >= height) {
                            break;
                        }
                        for (int i = x; i <= x + squareSize; ++i) {
                            for (int j = y; j <= y + squareSize; ++j) {
                                if (!GameEngine::ColorEquals(GetCell(i,j).GetColor(), player.GetColor())) {
                                    isSquare = false;
                                    break;
                                }
                            }
                            if (!isSquare) break;
                        }
                        if (isSquare) squareSize++;
                    } while (isSquare);
                    maxSquareSize = std::max(maxSquareSize, squareSize);

                }
            }
        }
        playersSquareSize.push_back(maxSquareSize);
    }
    return playersSquareSize;
}

Player Board::FindTrueWinner(const std::vector<Player>& playersToCheck) {
    std::vector<int> nbsOfCells;
    for (const Player& player: playersToCheck) {
        nbsOfCells.push_back(CountCells(player.GetColor()));
    }

    auto maxElementIndex = std::distance(nbsOfCells.begin(),std::max_element(nbsOfCells.begin(), nbsOfCells.end()));

    return playersToCheck[maxElementIndex];
}

int Board::CountCells(Color color) {
    int nbOfCells = 0;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (GameEngine::ColorEquals(color, GetCell(x, y).GetColor())){
                nbOfCells++;
            }
        }
    }
    return nbOfCells;
}




