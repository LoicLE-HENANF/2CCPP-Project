//
// Created by Enzo Robert on 14/11/2023.
//

#ifndef INC_2CCPP_PROJECT_TILE_H
#define INC_2CCPP_PROJECT_TILE_H
#include "Board.h"
// Color from raylib
// Vec2 = custom vector class for our project
// Board notre objet board

class Tile {
public:
    Tile(const int* shape, int dimension, Color color, const Board& board);
    void Draw() const; // fonction qui appelera DrawCell de board
private:
    Vec2<int> boardPosition;
    const int* shape;
    const int dimension;
    const Color color;
    const Board& board;
};

class Tile1 : public Tile{
public:
    Tile1(Color color, const Board &board);
private:
    static constexpr int shape[] = {1,0,0,
                                     1,1,1,
                                     0,0,0};
    static constexpr int dimension = 3; //pour garder en mémoire la taille de la tuile
};

class Tile2 : public Tile{
public:
    Tile2(Color color, const Board &board);
private:
    static constexpr int shape[] = {0,1,0,
                                     0,1,0,
                                     1,1,1}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile3 : public Tile{
public:
    Tile3(Color color, const Board &board);
private:
    static constexpr int shape[] = {0,1,0,
                                     1,1,1,
                                     0,1,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile4 : public Tile{
public:
    Tile4(Color color, const Board &board);
private:
    static constexpr int shape[] = {0,0,1,
                                     1,1,1,
                                     1,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile5 : public Tile{
public:
    Tile5(Color color, const Board &board);
private:
    static constexpr int shape[] = {0,1,0,
                                     1,1,1,
                                     0,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile6 : public Tile{
public:
    Tile6(Color color, const Board &board);
private:
    static constexpr int shape[] = {1,1,
                                     1,1}; // la forme de la tuile
    static constexpr int dimension = 2; //pour garder en mémoire la taille du pattern
};

class Tile7 : public Tile{
public:
    Tile7(Color color, const Board &board);
private:
    static constexpr int shape[] = {1,0,1,
                                     1,1,1,
                                     0,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile8 : public Tile{
public:
    Tile8(Color color, const Board &board);
private:
    static constexpr int shape[] = {1,1,1,
                                     0,0,0,
                                     0,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile9 : public Tile{
public:
    Tile9(Color color, const Board &board);
private:
    static constexpr int shape[] = {0,1,0,
                                     1,1,0,
                                     1,0,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile10 : public Tile{
public:
    Tile10(Color color, const Board &board);
private:
    static constexpr int shape[] = {1,0,
                                     1,1}; // la forme de la tuile
    static constexpr int dimension = 2; //pour garder en mémoire la taille du pattern
};

class Tile11 : public Tile{
public:
    Tile11(Color color, const Board &board);
private:
    static constexpr int shape[] = {0,0,1,
                                     0,1,1,
                                     1,1,0}; // la forme de la tuile
    static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile12 : public Tile{
public:
    Tile12(Color color, const Board &board);
private:
    static constexpr int shape[] = {1,1,
                                     0,0}; // la forme de la tuile
    static constexpr int dimension = 2; //pour garder en mémoire la taille du pattern
};

class Tile13 : public Tile{
public:
    Tile13(Color color, const Board &board);
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
    Tile14(Color color, const Board &board);
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
Tile15(Color color, const Board &board);
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
Tile16(Color color, const Board &board);
private:
static constexpr int shape[] = {0,0,1,0,
                                 0,1,1,0,
                                 1,1,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile17 : public Tile{
public:
Tile17(Color color, const Board &board);
private:
static constexpr int shape[] = {0,1,0,
                                 1,1,1,
                                 1,1,0}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile18 : public Tile{
public:
Tile18(Color color, const Board &board);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,1,0,0,
                                 1,0,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile19 : public Tile{
public:
Tile19(Color color, const Board &board);
private:
static constexpr int shape[] = {0,1,1,
                                 1,1,0,
                                 1,1,0}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile20 : public Tile{
public:
Tile20(Color color, const Board &board);
private:
static constexpr int shape[] = {0,1,0,
                                 1,1,0,
                                 1,1,1}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile21 : public Tile{
public:
Tile21(Color color, const Board &board);
private:
static constexpr int shape[] = {0,1,0,0,
                                 0,1,0,0,
                                 1,1,1,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile22 : public Tile{
public:
Tile22(Color color, const Board &board);
private:
static constexpr int shape[] = {1,1,0,
                                 1,1,0,
                                 1,1,0}; // la forme de la tuile
static constexpr int dimension = 3; //pour garder en mémoire la taille du pattern
};

class Tile23 : public Tile{
public:
Tile23(Color color, const Board &board);
private:
static constexpr int shape[] = {1,1,0,0,
                                 0,1,0,0,
                                 0,1,0,0,
                                 0,1,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile24 : public Tile{
public:
Tile24(Color color, const Board &board);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,1,0,0,
                                 0,1,1,0,
                                 0,0,1,1}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile25 : public Tile{
public:
Tile25(Color color, const Board &board);
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
Tile26(Color color, const Board &board);
private:
static constexpr int shape[] = {1,1,0,0,
                                 0,1,1,1,
                                 0,0,0,1,
                                 0,0,0,1}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile27 : public Tile{
public:
Tile27(Color color, const Board &board);
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
Tile28(Color color, const Board &board);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,1,0,0,
                                 1,1,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile29 : public Tile{
public:
Tile29(Color color, const Board &board);
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
Tile30(Color color, const Board &board);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,1,1,0,
                                 1,0,1,1,
                                 0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile31 : public Tile{
public:
Tile31(Color color, const Board &board);
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
Tile32(Color color, const Board &board);
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
Tile33(Color color, const Board &board);
private:
static constexpr int shape[] = {1,0,0,0,
                                 1,0,0,0,
                                 1,1,0,0,
                                 1,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile34 : public Tile{
public:
Tile34(Color color, const Board &board);
private:
static constexpr int shape[] = {1,0,0,1,
                                 1,1,1,1,
                                 0,0,0,0,
                                 0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 4; //pour garder en mémoire la taille du pattern
};

class Tile35 : public Tile{
public:
Tile35(Color color, const Board &board);
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
Tile36(Color color, const Board &board);
private:
static constexpr int shape[] = {1,0,0,0,0,
                                 1,0,0,0,0,
                                 1,1,0,0,0,
                                 0,1,1,1,0,
                                 0,0,0,0,0}; // la forme de la tuile
static constexpr int dimension = 5; //pour garder en mémoire la taille du pattern
};










#endif //INC_2CCPP_PROJECT_TILE_H
