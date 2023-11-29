//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BOARD_H
#define INC_2CCPP_PROJECT_BOARD_H

#include <cassert>
#include <iostream>
#include <map>
#include "Players.h"
#include "Tile.h"
#include "../Settings.h"
#include "Cell.h"


    /**
     * @brief Represents a game board.
     *
     * The Board class manages the game board, including tile placement, cell management, and drawing.
     */
class Board {
public:
    // Cell class only used in board, its implementation can be found in the Board.cpp file

    /**
     * @brief Default constructor for the Board class.
     *
     * Initializes the board with default settings.
     */
    Board(): boardPos(settings::boardPosition),
            padding(settings::padding),
            cellSize(settings::cellSize){
        assert(cellSize > 0); // If assertion triggers : the width or height is below 0
        cells.resize(width*height);
        std::cout << "nb of cells: " << cells.size() << std::endl;
    };

    /**
     * @brief Assignment operator for the Board class.
     *
     * @param other The Board object to copy from.
     * @return Reference to the current Board object.
     */
    Board& operator=(const Board& other){ return *this;}

    /**
     * @brief Clears the board by removing all cells.
     */
    void ClearBoard(){
        cells.clear();
        cells.resize(width*height);
    }

    /**
     * @brief Initializes the board with players.
     *
     * @param players The Players object representing the players in the game.
     */
    void InitBoard(const Players& players);

    /**
     * @brief Sets the tile of a cell at a specific position.
     *
     * @param tile The tile to set.
     * @param position The position of the cell.
     */
    void SetCells(Tile tile, Vec2<int> position);

    /**
     * @brief Sets the color of a cell at a specific position.
     *
     * @param position The position of the cell.
     * @param c The color to set.
     */
    void SetCell(Vec2<int> position, Color c);

    /**
     * @brief Gets the position of the board.
     *
     * @return Vec2 representing the x and y coordinates of the board position.
     */
    Vec2<int> GetBoardPos() const {
        return boardPos;
    };

    /**
     * @brief Draws a cell at a specific position.
     *
     * @param position The position of the cell to draw.
     */
    void DrawCell(Vec2<int> position) const;

    /**
     * @brief Draws a colored cell at a specific position.
     *
     * @param position The position of the cell to draw.
     * @param c The color of the cell.
     */
    void DrawCell(Vec2<int> position, Color c) const;

    /**
     * @brief Draws the border of the board.
     */
    void DrawBorder() const;

    /**
     * @brief Draws the entire board.
     */
    void Draw() const;

    // getters, setters

    /**
     * @brief Sets the position of the board.
     *
     * @param newBoardPos The new position of the board.
     */
    void SetBoardPos(Vec2<int> newBoardPos){
        boardPos = newBoardPos;
    };

    /**
     * @brief Sets the size of the board.
     *
     * @param boardSize_ The new size of the board.
     */
    void SetBoardSize(Vec2<int> boardSize_){
        width = boardSize_.GetX();
        height = boardSize_.GetY();
        cells.resize(width*height);
    };

    /**
     * @brief Sets the padding of the board.
     *
     * @param newPadding The new padding of the board.
     */
    void SetBoardPadding(int newPadding){ padding = newPadding; };

    /**
     * @brief Sets the cell size of the board.
     *
     * @param newCellSize The new cell size of the board.
     */
    void SetBoardCellSize(int newCellSize){ cellSize = newCellSize; };

    /**
     * @brief Gets the size of the board.
     *
     * @return Vec2 representing the width and height of the board.
     */
    Vec2<int> GetSize() const;

    // Tile placement

    /**
     * @brief Places a tile on the board at a specific position.
     *
     * @param tile The tile to place.
     * @param position The position to place the tile.
     * @return The result of the tile placement.
     */
    int PlaceTile(Tile tile, Vec2<int> position);

    /**
     * @brief Checks if a cell can be placed at a specific position on the board.
     *
     * @param position The position to check.
     * @return True if a cell can be placed, false otherwise.
     */
    bool CanPlaceCell(Vec2<int> position);

    /**
     * @brief Checks for bonuses of a specified player color on the board.
     *
     * @param PlayerColor The color of the player to check for bonuses.
     * @return A map of bonuses and their counts.
     */
    std::map<int, int> CheckForBonuses(Color PlayerColor);

private:
    std::vector<Cell> cells;
    Vec2<int> boardPos;

    int width = 0;
    int height = 0;
    int padding;
    int cellSize;

    /**
     * @brief Checks if a tile can be placed at the specified position.
     *
     * @param tile The tile to check.
     * @param position The position to check.
     * @return True if the tile can be placed, false otherwise.
     */
    bool CanPlaceTile(Tile tile, Vec2<int> position);

    /**
     * @brief Checks if a neighboring tile exists at the specified position.
     *
     * @param tile The tile to check for neighbors.
     * @param position The position to check.
     * @return True if a neighboring tile exists, false otherwise.
     */
    bool NeighboringTile(Tile tile, Vec2<int> position);

    /**
     * @brief Gets the reference to the cell at the specified coordinates.
     *
     * @param x The x-coordinate of the cell.
     * @param y The y-coordinate of the cell.
     * @return A reference to the Cell object.
     */
    Cell &GetCell(int x, int y);
};


#endif //INC_2CCPP_PROJECT_BOARD_H
