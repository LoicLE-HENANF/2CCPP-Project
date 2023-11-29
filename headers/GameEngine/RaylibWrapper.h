//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_RAYLIBWRAPPER_H
#define INC_2CCPP_PROJECT_RAYLIBWRAPPER_H

#include "../Utilities/Vec2.h"
#include "raylib.h"
#include <string>

namespace GameEngine {
    //raylib function:
    // void DrawRectangle(int posX, int posY, int width, int height, Color color)
    // ours:


    /**
     * @brief Draws a filled rectangle on the screen.
     *
     * This function uses Vec2 to represent the position and size of the rectangle.
     *
     * @param position The top-left corner of the rectangle.
     * @param size The width and height of the rectangle.
     * @param color The color of the rectangle.
     */
    void DrawRectangle(Vec2<int> position, Vec2<int> size, Color color);

    /**
     * @brief Draws the outline of a rectangle with specified line thickness.
     *
     * This function uses Vec2 to represent the position and size of the rectangle.
     *
     * @param position The top-left corner of the rectangle.
     * @param size The width and height of the rectangle.
     * @param lineThickness The thickness of the lines outlining the rectangle.
     * @param color The color of the outline.
     */
    void DrawRectangleLinesEx(Vec2<int> position, Vec2<int> size, int lineThickness, Color color);

    /**
     * @brief Retrieves the current mouse position.
     *
     * @return Vec2 representing the x and y coordinates of the mouse position.
     */
    Vec2<int> GetMousePosition();

    /**
    * @brief Checks if a point is inside a specified rectangle.
    *
    * @param point The point to check.
    * @param position The top-left corner of the rectangle.
    * @param size The width and height of the rectangle.
    * @return True if the point is inside the rectangle, false otherwise.
    */
    bool CheckCollisionPointRec(Vec2<int> point, Vec2<int> position, Vec2<int> size);

    /**
     * @brief Draws an upward-pointing triangle.
     *
     * @param position The position where the triangle will be drawn.
     * @param size The width and height of the triangle.
     * @param color The color of the triangle.
     */
    void DrawTriangleUp(Vec2<int> position, Vec2<int> size, Color color);

    /**
     * @brief Draws an downward-pointing triangle.
     *
     * @param position The position where the triangle will be drawn.
     * @param size The width and height of the triangle.
     * @param color The color of the triangle.
     */
    void DrawTriangleDown(Vec2<int> position, Vec2<int> size, Color color);

    /**
    * @brief Compares colors 1 and color 2.
    *
    * @param color1 The first color.
    * @param color2 The second color.
    * @return True if the colors are equal, false otherwise.
    */
    bool ColorEquals(Color color1, Color color2);

    /**
    * @brief Draw an image.
    *
    * @param image The image to draw.
    * @param position The position of the top left corner of the image.
    */
    void DrawTexture(Texture2D texture, Vec2<int> position);
}


#endif //INC_2CCPP_PROJECT_RAYLIBWRAPPER_H
