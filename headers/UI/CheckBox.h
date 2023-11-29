//
// Created by lehen on 15/11/2023.
//

#ifndef INC_2CCPP_PROJECT_CHECKBOX_H
#define INC_2CCPP_PROJECT_CHECKBOX_H


#include "../Utilities/Vec2.h"
#include "raylib.h"

/**
 * @brief Represents a checkbox in the game.
 *
 * The CheckBox class manages information about a checkbox, including its position, size, padding, colors, and value.
 */
class CheckBox {
public:

    /**
     * @brief Constructor for the CheckBox class.
     *
     * @param position The position of the checkbox.
     * @param size The size of the checkbox.
     * @param padding The padding around the checkbox.
     * @param colorIn The color of the checkbox when checked.
     * @param colorEdge The color of the checkbox edge.
     * @param defaultValue The default value of the checkbox.
     */
    CheckBox(Vec2<int> position, Vec2<int> size, int padding, Color colorIn, Color colorEdge, bool defaultValue) :
    position(position),
    size(size),
    padding(padding),
    colorIn(colorIn),
    colorEdge(colorEdge),
    value(defaultValue)
    {};

    /**
     * @brief Destructor for the CheckBox class.
     */
    ~CheckBox() = default;

    /**
     * @brief Gets the value of the checkbox.
     *
     * @return The value of the checkbox.
     */
    bool GetValue() const{ return value;};

    /**
     * @brief Draws the checkbox on the screen.
     */
    void Draw();

    /**
     * @brief Checks if the checkbox can be clicked.
     *
     * @return True if the checkbox can be clicked, false otherwise.
     */
    bool CanClick();

    /**
     * @brief Detects a click on the checkbox and toggles its value.
     */
    void DetectClick();


private:
    Vec2<int> position;
    Vec2<int> size;
    int padding;
    Color colorIn;
    Color colorEdge;
    bool value;

};


#endif //INC_2CCPP_PROJECT_CHECKBOX_H
