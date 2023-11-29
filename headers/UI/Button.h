//
// Created by lehen on 14/11/2023.
//

#ifndef INC_2CCPP_PROJECT_BUTTON_H
#define INC_2CCPP_PROJECT_BUTTON_H


#include <utility>
#include <string>

#include "../Utilities/Vec2.h"
#include "raylib.h"

/**
 * @brief Represents a button in the game.
 *
 * The Button class manages information about a button, including its position, size, text, color, and activation state.
 */
class Button {
public:

    /**
     * @brief Constructor for the Button class.
     *
     * @param buttonPos The position of the button.
     * @param buttonSize The size of the button.
     * @param text The text displayed on the button.
     * @param color The color of the button.
     */
    Button(Vec2<int> buttonPos, Vec2<int> buttonSize, std::string text, Color color) :
        text(std::move(text)),
        color(color),
        buttonPos(buttonPos),
        buttonSize(buttonSize)
        {

        };

    /**
     * @brief Destructor for the Button class.
     */
    ~Button() = default;

    /**
     * @brief Draws the button on the screen.
     */
    void Draw();

    /**
     * @brief Checks if the button can be clicked.
     *
     * @return 1 if the button can be clicked, 0 otherwise.
     */
    int CanClick();

    /**
     * @brief Detects a click on the button.
     *
     * @return True if a click is detected, false otherwise.
     */
    bool DetectClick();

    /**
     * @brief Turns on the button.
     */
    void TurnOn(){
        activated = true;
    }

    /**
     * @brief Turns off the button.
     */
    void TurnOff(){
        activated = false;
    }


private:
    std::string text;
    Color color;
    Vec2<int> buttonPos;
    Vec2<int> buttonSize;

    bool activated = true;
};


#endif //INC_2CCPP_PROJECT_BUTTON_H
