//
// Created by lehen on 12/11/2023.
//



#include "../headers/Board.h"
#include "../headers/raylibWrapper.h"
#include "../headers/settings.h"
#include <cassert>

using namespace GameEngine;
using namespace settings;

// Cell implementation
Board::Cell::Cell()
    :
    exists(true),
    c(settings::cellBaseColor)
{

}

void Board::Cell::SetColor(Color color) {
    c = color;
    exists = true;
}

void Board::Cell::Remove() {
    exists = false;
}

Color Board::Cell::GetColor() const {
    return c;
}

bool Board::Cell::Exists() const {
    return exists;
}

// Board implementation
Board::Board(Vec2<int> screenPos, Vec2<int> size, int cellSize, int padding)
    :
    screenPos(screenPos),
    width(size.GetX()),
    height(size.GetY()),
    cellSize(cellSize),
    padding(padding)
{
    assert(width > 0 && height > 0); // If assertion triggers : the width or height is below 0
    assert(cellSize > 0); // If assertion triggers : the width or height is below 0
    cells.resize(width*height);
}

void Board::SetCell(Vec2<int> position, Color c) {
    assert(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height); // If assertion triggers : x or y is out of bounds
    cells[position.GetY() * width + position.GetX()].SetColor(c);
}

void Board::DrawCell(Vec2<int> position) const {
    assert(position.GetX() >= 0 && position.GetY() >= 0 && position.GetX()<width && position.GetY() < height); // If assertion triggers : x or y is out of bounds
    Color c = cells[position.GetY() * width + position.GetX()].GetColor();
    Vec2<int> origin = screenPos + padding + (position * cellSize);
    GameEngine::DrawRectangle(origin,
                  Vec2<int>{cellSize, cellSize} - padding,
                              c);
}

void Board::DrawBorder() const {
    GameEngine::DrawRectangleLinesEx(screenPos - (cellSize / 2),
                              Vec2{width*cellSize, height*cellSize} + cellSize,
                              cellSize/2,
                                     WHITE);
}

void Board::Draw() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (CellExists({x,y})){
                DrawCell(Vec2<int>{x, y});
            }

        }
    }
    DrawBorder();

}

bool Board::CellExists(Vec2<int> position) const {
    return cells[position.GetY() * width + position.GetX()].Exists();
}
