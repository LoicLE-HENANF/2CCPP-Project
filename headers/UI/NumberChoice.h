//
// Created by lehen on 15/11/2023.
//

#ifndef INC_2CCPP_PROJECT_NUMBERCHOICE_H
#define INC_2CCPP_PROJECT_NUMBERCHOICE_H


#include "../Utilities/Vec2.h"
#include "raylib.h"

/**
 * @brief Represents a number choice interface in the game.
 *
 * The NumberChoice class manages information about a number choice interface, including its position, size, colors,
 * minimum and maximum values, and the current selected value.
 */
class NumberChoice {
public:

    /**
     * @brief Constructor for the NumberChoice class.
     *
     * @param position The position of the number choice interface.
     * @param size The size of the number choice interface.
     * @param primaryColor The primary color used for drawing.
     * @param secondaryColor The secondary color used for drawing.
     * @param minimum The minimum value allowed for the number choice.
     * @param maximum The maximum value allowed for the number choice.
     */
    NumberChoice(Vec2<int> position,
                 Vec2<int> size,
                 Color primaryColor,
                 Color secondaryColor,
                 int minimum,
                 int maximum)
                 :
                 position(position),
                 size(size),
                 primaryColor(primaryColor),
                 secondaryColor(secondaryColor),
                 minimum(minimum),
                 maximum(maximum)
                 {};

    /**
     * @brief Destructor for the NumberChoice class.
     */
    ~NumberChoice() = default;

    /**
     * @brief Draws the number choice interface on the screen.
     */
    void Draw();

    /**
     * @brief Checks if the "up" arrow of the number choice interface can be clicked.
     *
     * @return True if the "up" arrow can be clicked, false otherwise.
     */
    bool CanClickArrowUp();

    /**
     * @brief Checks if the "down" arrow of the number choice interface can be clicked.
     *
     * @return True if the "down" arrow can be clicked, false otherwise.
     */
    bool CanClickArrowDown();

    /**
     * @brief Detects a click on the number choice interface.
     *
     * @return The value selected after the click.
     */
    int DetectClick();

private:
    Vec2<int> position;
    Vec2<int> size;
    int fontSize = size.GetY() - 10;
    Color primaryColor = WHITE;
    Color secondaryColor = BLACK;
    int minimum;
    int maximum;
    int value = minimum;

    Vec2<int> numberPos = {position.GetX() + size.GetX()/2,
                           position.GetY() + 10};

    // triangle param
    Vec2<int> trianglePosDown = position + Vec2{0,size.GetY()/2} + size / 10;
    Vec2<int> triangleSizeDown = size/3;
    Vec2<int> trianglePosUp = position + size / 10;
    Vec2<int> triangleSizeUp = size/3;



};


#endif //INC_2CCPP_PROJECT_NUMBERCHOICE_H
