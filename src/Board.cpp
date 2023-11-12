//
// Created by lehen on 12/11/2023.
//

#include "../headers/Board.h"
#include "assert.h"

// Cell implementation
Board::Cell::Cell()
    :
    exists(false),
    c(WHITE)
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

// Board implementation
Board::Board(int windowX, int windowY, int width, int height, int cellSize, int padding)
    :
    windowX(windowX),
    windowY(windowY),
    width(width),
    height(height),
    cellSize(cellSize),
    padding(padding)
{
    assert(width > 0 && height > 0); // If assertion triggers : the width or height is below 0
    assert(cellSize > 0); // If assertion triggers : the width or height is below 0
    cells.resize(width*height);
}

void Board::SetCell(int x, int y, Color c) {
    assert(x >= 0 && y >= 0 && x<width && y < height); // If assertion triggers : x or y is out of bounds
    cells[y * width + x].SetColor(c);
}

void Board::DrawCell(int x, int y) const {
    assert(x >= 0 && y >= 0 && x<width && y < height); // If assertion triggers : x or y is out of bounds
    Color c = cells[y * width + x].GetColor();
    // here can use DrawRectangleV with Vector2 from raylib or create our own class because Vec2 from raylib is very poor (just 2 float and that's it
    DrawRectangle(windowX + x * cellSize + padding,
                  windowY + y * cellSize + padding,
                  cellSize - padding,
                  cellSize - padding,
                  c);
}

void Board::Draw() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            DrawCell(x, y);
        }
    }

}
