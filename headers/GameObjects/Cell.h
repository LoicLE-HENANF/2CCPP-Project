//
// Created by lehen on 27/11/2023.
//

#ifndef INC_2CCPP_PROJECT_CELL_H
#define INC_2CCPP_PROJECT_CELL_H


#include "raylib.h"
#include "../Utilities/Vec2.h"

/**
 * @brief Represents a cell in the game board.
 *
 * The Cell class manages the state of a cell, including its color, bonus status, and whether it has been taken.
 */
class Cell
{
public:

    /**
     * @brief Default constructor for the Cell class.
     *
     * Initializes a cell with default values.
     */
    Cell();

    /**
     * @brief Sets the color of the cell.
     *
     * @param color The color to set for the cell.
     */
    void SetColor(Color color);

    /**
    * @brief Gets the color of the cell.
    *
    * @return The color of the cell.
    */
    [[nodiscard]] Color GetColor() const;

    /**
     * @brief Marks the cell as placed on the board.
     *
     * @return The result of the placement operation.
     */
    int Placed();

    /**
     * @brief Draws the cell with a specified color.
     *
     * @param color The color to use when drawing the cell.
     */
    void DrawCellFollow(Color color);

    /**
     * @brief Sets the bonus status of the cell.
     *
     * @param i The bonus value to set.
     */
    void SetBonus(int i);

    /**
     * @brief Gets the bonus status of the cell.
     *
     * @return The bonus status of the cell.
     */
    [[nodiscard]] int GetIsBonus() const;

    void SetIsStone(bool value);

    [[nodiscard]] bool IsStone() const;

private:
    Color c;
    bool placed = false;
    int isBonus = 0;
    bool taken = false;
    bool isStone = false;
};


#endif //INC_2CCPP_PROJECT_CELL_H
