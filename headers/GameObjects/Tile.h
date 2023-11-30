//
// Created by Enzo Robert on 14/11/2023.
//

#ifndef INC_2CCPP_PROJECT_TILE_H
#define INC_2CCPP_PROJECT_TILE_H

#include "raylib.h"
#include "../Utilities/Vec2.h"

/**
 * @brief Represents a tile in the game.
 *
 * The Tile class manages information about a game tile, including its shape, color, position, and various operations.
 */
class Tile {
public:

    /**
     * @brief Constructor for the Tile class.
     *
     * @param shape The shape of the tile represented as a 1D array.
     * @param dimension The dimension of the square-shaped tile.
     * @param color The color of the tile.
     * @param position The position of the tile on the game board.
     */
    Tile(const int *shape, int dimension, Color color, Vec2<int> position);
    /**
     * @brief Draws the tile at the specified position on the game board.
     *
     * @param pos The position to draw the tile.
     * @param cellPos The position of the cell on the game board.
     */
    void Draw(Vec2<int> pos, Vec2<int> cellPos);

    /**
     * @brief Draws the tile following the mouse cursor.
     *
     * Similar to Draw but for following the mouse cursor.
     */
    void DrawFollow(); // Like Draw but to follow the user's mouse

    /**
     * @brief Gets the position of the tile on the game board.
     *
     * @return The position of the tile.
     */
    Vec2<int> GetPosition(){
        return position;
    }

    /**
     * @brief Gets the dimension of the tile.
     *
     * @return The dimension of the tile.
     */
    int GetDimension();

    /**
     * @brief Gets the value of the tile at the specified coordinates.
     *
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return The value of the tile at the specified coordinates.
     */
    const int GetValue(int x, int y);


    /**
     * @brief Rotates the tile clockwise.
     */
    void RotateClockwise();


    /**
     * @brief Gets the color of the tile.
     *
     * @return The color of the tile.
     */
    Color GetColor();

    /**
     * @brief Flips the tile.
     */
    void Flip();

    /**
     * @brief Sets the color of the tile.
     *
     * @param color The color to set for the tile.
     */
    void SetColor(Color color);

private:
    const int* shape;
    int dimension;
    Color color;
    Vec2<int> position;

    /**
     * @brief Enumeration representing the rotation state of the tile.
     */
    enum class Rotation{
        UP,
        RIGHT,
        DOWN,
        LEFT
    };
    Rotation currentRotation;
    bool flipped = false;
};

/**
 * @brief Represents a specific type of tile in the game.
 *
 * The Tile1 class is a subclass of Tile and represents a specific tile configuration.
 */
class Tile1 : public Tile{
public:

    /**
     * @brief Constructor for the Tile1 class.
     *
     * @param color The color of the tile.
     * @param position The position of the tile on the game board.
     */
    Tile1(Color color, Vec2<int> position);
private:

    /**
     * @brief 1D array representing the shape of the Tile1.
     */
    static constexpr int shape[] = {1,0,0,
                                     1,1,1,
                                     0,0,0};

    /**
     * @brief The dimension of the Tile1.
     *
     * To keep track of the size of the tile.
     */
    static constexpr int dimension = 3; //pour garder en mémoire la taille de la tuile
};

class Tile2 : public Tile{
public:
    Tile2(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {0,1,0,
                                     0,1,0,
                                     1,1,1}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile3 : public Tile{
public:
    Tile3(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {0,1,0,
                                     1,1,1,
                                     0,1,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile4 : public Tile{
public:
    Tile4(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {0,0,1,
                                     1,1,1,
                                     1,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile5 : public Tile{
public:
    Tile5(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {0,1,0,
                                     1,1,1,
                                     0,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile6 : public Tile{
public:
    Tile6(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {1,1,
                                     1,1}; // la forme de la tuile
    static constexpr int dimension = 2; //pour garder en mémoire la taille du pattern
};

class Tile7 : public Tile{
public:
    Tile7(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {1,1,1,
                                     1,0,1,
                                     0,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile8 : public Tile{
public:
    Tile8(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {1,1,1,
                                     0,0,0,
                                     0,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile9 : public Tile{
public:
    Tile9(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {0,1,0,
                                     1,1,0,
                                     1,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile10 : public Tile{
public:
    Tile10(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {1,0,
                                     1,1}; // la forme de la tuile
    static constexpr int dimension = 2; //pour garder en mémoire la taille du pattern
};

class Tile11 : public Tile{
public:
    Tile11(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {0,0,1,
                                     0,1,1,
                                     1,1,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile12 : public Tile{
public:
    Tile12(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {1,1,
                                     0,0}; // la forme de la tuile
    static constexpr int dimension = 2; //pour garder en mémoire la taille du pattern
};

class Tile13 : public Tile{
public:
    Tile13(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {0,1,0,0,0,
                                     1,1,0,0,0,
                                     1,0,0,0,0,
                                    1,0,0,0,0,
                                     1,1,0,0,0}; // la forme de la tuile
    static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile14 : public Tile{
public:
    Tile14(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {1,1,1,0,0,
                                     1,0,0,0,0,
                                     1,0,0,0,0,
                                     1,0,0,0,0,
                                     1,0,0,0,0}; // la forme de la tuile
    static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile15 : public Tile{
public:
Tile15(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,0,1,0,
                                 0,0,0,1,0,
                                 0,0,0,1,1,
                                 0,1,1,1,0,
                                 1,1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile16 : public Tile{
public:
Tile16(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,1,0,
                                 0,1,1,0,
                                 1,1,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile17 : public Tile{
public:
Tile17(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,
                                 1,1,1,
                                 1,1,0}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile18 : public Tile{
public:
Tile18(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,1,0,0,
                                 1,0,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile19 : public Tile{
public:
Tile19(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,1,
                                 1,1,0,
                                 1,1,0}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile20 : public Tile{
public:
Tile20(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,
                                 1,1,0,
                                 1,1,1}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile21 : public Tile{
public:
Tile21(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                 0,1,0,0,
                                 1,1,1,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile22 : public Tile{
public:
Tile22(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,
                                 1,1,0,
                                 1,1,0}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile23 : public Tile{
public:
Tile23(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,
                                 0,1,0,0,
                                 0,1,0,0,
                                 0,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile24 : public Tile{
public:
Tile24(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,1,0,0,
                                 0,1,1,0,
                                 0,0,1,1}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile25 : public Tile{
public:
Tile25(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,1,1,1,
                                 0,0,0,0,0,
                                 0,0,0,0,0,
                                 0,0,0,0,0,
                                 0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile26 : public Tile{
public:
Tile26(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,
                                 0,1,1,1,
                                 0,0,0,1,
                                 0,0,0,1}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile27 : public Tile{
public:
Tile27(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,0,
                                 1,1,0,0,0,
                                 1,0,0,0,0,
                                 1,1,0,0,0,
                                 1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile28 : public Tile{
public:
Tile28(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,1,0,0,
                                 1,1,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile29 : public Tile{
public:
Tile29(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,0,
                                 0,1,0,0,0,
                                 0,1,0,0,0,
                                 1,1,1,0,0,
                                 1,0,1,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile30 : public Tile{
public:
Tile30(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,1,1,0,
                                 1,0,1,1,
                                 0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile31 : public Tile{
public:
Tile31(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,0,
                                 0,1,0,0,0,
                                 1,1,0,0,0,
                                 1,0,0,0,0,
                                 1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile32 : public Tile{
public:
Tile32(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,0,
                                 0,1,0,0,0,
                                 0,1,1,1,0,
                                 1,1,0,0,0,
                                 1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile33 : public Tile{
public:
Tile33(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,0,0,0,
                                 1,1,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile34 : public Tile{
public:
Tile34(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,1,
                                 1,1,1,1,
                                 0,0,0,0,
                                 0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile35 : public Tile{
public:
Tile35(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,0,1,1,
                                 1,0,0,0,1,
                                 1,1,1,1,1,
                                 0,0,0,0,0,
                                 0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile36 : public Tile{
public:
Tile36(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,0,
                                 1,0,0,0,0,
                                 1,1,0,0,0,
                                 0,1,1,1,0,
                                 0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile37 : public Tile{
public:
Tile37(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,0,
                                 0,1,1,0,0,
                                 1,1,0,0,0,
                                 0,1,1,0,0,
                                 0,1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile38 : public Tile{
public:
Tile38(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,
                                 1,1,0,
                                 1,1,0}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile39 : public Tile{
public:
Tile39(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                 0,1,0,0,
                                 1,1,1,1,
                                 0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile40 : public Tile{
public:
Tile40(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                 1,1,0,0,
                                 1,1,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile41 : public Tile{
public:
Tile41(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,1,
                                0,1,0,
                                1,1,0}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile42 : public Tile{
public:
    Tile42(Color color, Vec2<int> position);
private:
    static constexpr int shape[] = {1,1,1,1,
                                    0,0,0,0,
                                    0,0,0,0,
                                    0,0,0,0}; // la forme de la tuile
    static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile43 : public Tile{
public:
Tile43(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,
                                1,0,0,0,
                                1,1,1,1,
                                0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile44 : public Tile{
public:
Tile44(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,1,0,
                                1,1,0,0,
                                0,1,1,1,
                                0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile45 : public Tile{
public:
Tile45(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                1,1,0,0,
                                1,0,0,0,
                                1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile46 : public Tile{
public:
Tile46(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,0,
                                1,1,0,0,0,
                                1,0,0,0,0,
                                1,0,0,0,0,
                                1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile47 : public Tile{
public:
Tile47(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,1,1,1,
                                0,0,1,0,0,
                                0,0,1,0,0,
                                0,0,1,0,0,
                                1,1,1,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile48 : public Tile{
public:
Tile48(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,0,0,
                                 0,1,0,0,0,0,
                                 1,1,0,0,0,0,
                                 1,0,0,0,0,0,
                                 1,1,0,0,0,0,
                                 1,0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 6; //pour garder en mémoire la taille du pattern
};

class Tile49 : public Tile{
public:
Tile49(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,0,
                                0,1,0,0,0,
                                0,1,1,1,0,
                                0,0,0,1,0,
                                0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile50 : public Tile{
public:
Tile50(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,0,
                                0,1,0,0,0,
                                1,1,1,0,0,
                                0,1,0,0,0,
                                0,1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile51 : public Tile{
public:
Tile51(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,1,
                                0,0,1,
                                1,1,1}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile52 : public Tile{
public:
Tile52(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,0,0,
                                1,0,0,0,0,0,
                                1,0,0,0,0,0,
                                1,0,0,0,0,0,
                                1,0,0,0,0,0,
                                1,0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 6; //pour garder en mémoire la taille du pattern
};

class Tile53 : public Tile{
public:
Tile53(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,1,0,
                                1,1,1,0,
                                0,1,0,0,
                                1,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile54 : public Tile{
public:
Tile54(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,1,0,
                                1,1,1,0,
                                0,1,1,1,
                                0,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile55 : public Tile{
public:
Tile55(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,1,0,
                                0,1,0,0,
                                0,1,0,0,
                                1,1,1,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile56 : public Tile{
public:
Tile56(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,0,
                                1,0,0,0,0,
                                1,1,0,0,0,
                                1,0,0,0,0,
                                1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile57 : public Tile{
public:
Tile57(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,
                                0,1,0,0,
                                0,1,0,1,
                                1,1,1,1}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile58 : public Tile{
public:
Tile58(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,1,0,0,
                                0,1,1,0,0,
                                1,1,0,0,0,
                                1,0,0,0,0,
                                1,1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile59 : public Tile{
public:
Tile59(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,1,0,0,0,
                                0,1,0,0,0,0,
                                0,1,0,0,0,0,
                                0,1,0,0,0,0,
                                1,1,0,0,0,0,
                                1,0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 6; //pour garder en mémoire la taille du pattern
};

class Tile60 : public Tile{
public:
Tile60(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,1,0,
                                1,1,1,1,
                                0,0,0,0,
                                0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile61 : public Tile{
public:
Tile61(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,
                                0,1,0,1,
                                0,1,0,1,
                                0,1,1,1}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile62 : public Tile{
public:
Tile62(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,0,
                                1,0,1,0,0,
                                1,1,1,1,0,
                                0,1,0,0,0,
                                0,1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile63 : public Tile{
public:
Tile63(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,0,0,0,
                                1,0,0,0,0,0,0,
                                1,0,0,0,0,0,0,
                                1,0,0,0,0,0,0,
                                1,0,0,0,0,0,0,
                                1,0,0,0,0,0,0,
                                1,0,0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 7; //pour garder en mémoire la taille du pattern
};

class Tile64 : public Tile{
public:
Tile64(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                1,1,1,0,
                                1,0,0,0,
                                1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile65 : public Tile{
public:
Tile65(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,1,
                                1,0,1,
                                1,1,1}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile66 : public Tile{
public:
Tile66(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,
                                1,1,1,
                                1,0,1}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile67 : public Tile{
public:
Tile67(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,1,0,0,
                                0,0,1,0,0,
                                1,1,1,1,1,
                                0,0,1,0,0,
                                0,0,1,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile68 : public Tile{
public:
Tile68(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,0,1,0,0,
                                0,0,1,1,0,0,
                                0,0,1,0,0,0,
                                0,0,1,0,0,0,
                                0,1,1,0,0,0,
                                1,1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 6; //pour garder en mémoire la taille du pattern
};

class Tile69 : public Tile{
public:
Tile69(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,0,
                                1,0,0,0,0,
                                1,1,0,0,0,
                                1,0,0,0,0,
                                1,1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile70 : public Tile{
public:
Tile70(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,0,
                                0,1,0,0,0,
                                0,1,0,0,0,
                                1,1,1,1,0,
                                0,1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile71 : public Tile{
public:
Tile71(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,0,
                                1,1,0,0,0,
                                1,0,0,0,0,
                                1,0,0,0,0,
                                1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};

class Tile72 : public Tile{
public:
Tile72(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,1,0,
                                0,1,0,0,
                                1,1,0,0,
                                1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile73 : public Tile{
public:
Tile73(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,1,0,0,0,
                                0,1,0,0,0,0,
                                1,1,0,0,0,0,
                                0,1,0,0,0,0,
                                0,1,0,0,0,0,
                                0,1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 6; //pour garder en mémoire la taille du pattern
};

class Tile74 : public Tile{
public:
Tile74(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,0,0,
                                1,1,0,0,0,0,
                                0,1,1,0,0,0,
                                0,1,0,0,0,0,
                                0,1,0,0,0,0,
                                0,1,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 6; //pour garder en mémoire la taille du pattern
};

class Tile75 : public Tile{
public:
Tile75(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                0,1,1,0,
                                1,1,0,0,
                                0,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile76 : public Tile{
public:
Tile76(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,0,0,
                                1,1,1,1,
                                0,0,0,0,
                                0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile77 : public Tile{
public:
Tile77(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,1,1,
                                1,1,1,0,
                                1,0,0,0,
                                1,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile78 : public Tile{
public:
Tile78(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,1,0,
                                0,1,0,0,
                                0,1,0,0,
                                1,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile79 : public Tile{
public:
Tile79(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                0,1,0,0,
                                1,1,1,0,
                                0,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile80 : public Tile{
public:
Tile80(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,1,1,0,
                                1,0,1,0,
                                1,0,0,0,
                                1,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile81 : public Tile{
public:
Tile81(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                0,1,1,0,
                                1,1,0,0,
                                1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile82 : public Tile{
public:
Tile82(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,
                                1,1,0,
                                1,1,1}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile83 : public Tile{
public:
Tile83(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {1,0,0,0,
                                1,0,0,0,
                                1,0,0,0,
                                1,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile84 : public Tile{
public:
Tile84(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,0,0,0,
                                0,1,0,0,
                                1,1,1,1,
                                1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile85 : public Tile{
public:
Tile85(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,1,0,
                                1,1,0,0,
                                1,0,0,0,
                                1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile86 : public Tile{
public:
Tile86(Color color, Vec2<int> position);
private:
static constexpr int shape[] = {0,1,0,0,
                                1,1,0,0,
                                1,0,0,0,
                                1,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

#endif //INC_2CCPP_PROJECT_TILE_H
