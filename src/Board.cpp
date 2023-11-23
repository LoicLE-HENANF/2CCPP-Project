//
// Created by lehen on 12/11/2023.
//



#include "../headers/Board.h"
#include "../headers/RaylibWrapper.h"
#include "../headers/settings.h"
#include <cassert>
#include <iostream>

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
Board::Board(Vec2<int> boardPos, Vec2<int> size, int cellSize, int padding)
    :
        boardPos(boardPos),
    width(size.GetX()),
    height(size.GetY()),
    cellSize(cellSize),
    padding(padding)
{
    assert(width > 0 && height > 0); // If assertion triggers : the width or height is below 0
    assert(cellSize > 0); // If assertion triggers : the width or height is below 0
    cells.resize(width*height);
    std::cout << "nb of cells: " << cells.size() << std::endl;
}

void Board::SetCell(Vec2<int> position, Color c) {
    assert(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height); // If assertion triggers : x or y is out of bounds
    cells[position.GetY() * width + position.GetX()].SetColor(c);
}

void Board::DrawCell(Vec2<int> position) const {

    Color c = cells[position.GetY() * width + position.GetX()].GetColor();
    assert(c != WHITE); // If assertion triggers : cell is white


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

