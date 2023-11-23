//
// Created by lehen on 12/11/2023.
//



#include "../headers/Board.h"
#include "../headers/RaylibWrapper.h"
#include "../headers/settings.h"
#include "../headers/Player.h"
#include "../headers/Players.h"
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace GameEngine;
using namespace settings;

// Cell implementation
Board::Cell::Cell()
    :
    c(settings::cellBaseColor)
{

}

void Board::Cell::SetColor(Color color) {
    c = color;
}

Color Board::Cell::GetColor() const {
    return c;
}

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
                std::rand() % boardSize.GetX(),
                std::rand() % boardSize.GetY()
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
    assert(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height); // If assertion triggers : x or y is out of bounds
    cells[position.GetY() * width + position.GetX()].SetColor(c);
}

void Board::DrawCell(Vec2<int> position) const {

    Color c = cells[position.GetY() * width + position.GetX()].GetColor();
//    assert(c != WHITE); // If assertion triggers : cell is white


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
//            std::cout << "drawing cell at " << x << ", " << y << std::endl;
            DrawCell(Vec2<int>{x, y});
        }
    }

    // Drawing board borders
    DrawBorder();

}

