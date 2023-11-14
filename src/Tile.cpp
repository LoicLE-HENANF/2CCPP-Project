//
// Created by Enzo Robert on 14/11/2023.
//

#include "../headers/Tile.h"



Tile::Tile(const int *shape, int dimension, Color color, const Board &board) :
        shape(shape),
        dimension(dimension),
        color(color),
        boardPosition(board.GetBoardPos()),
        board(board)
{

}

// Tile1
Tile1::Tile1(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile2
Tile2::Tile2(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile3
Tile3::Tile3(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile4
Tile4::Tile4(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile5
Tile5::Tile5(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile6
Tile6::Tile6(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile7
Tile7::Tile7(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile8
Tile8::Tile8(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile9
Tile9::Tile9(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile10
Tile10::Tile10(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile11
Tile11::Tile11(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile12
Tile12::Tile12(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile13
Tile13::Tile13(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile14
Tile14::Tile14(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile15
Tile15::Tile15(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile16
Tile16::Tile16(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile17
Tile17::Tile17(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile18
Tile18::Tile18(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile19
Tile19::Tile19(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile20
Tile20::Tile20(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile21
Tile21::Tile21(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile22
Tile22::Tile22(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile23
Tile23::Tile23(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile24
Tile24::Tile24(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile25
Tile25::Tile25(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile26
Tile26::Tile26(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile27
Tile27::Tile27(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile28
Tile28::Tile28(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile29
Tile29::Tile29(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile30
Tile30::Tile30(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile31
Tile31::Tile31(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile32
Tile32::Tile32(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile33
Tile33::Tile33(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile34
Tile34::Tile34(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile35
Tile35::Tile35(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile36
Tile36::Tile36(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile37
Tile37::Tile37(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile38
Tile38::Tile38(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile39
Tile39::Tile39(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile40
Tile40::Tile40(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile41
Tile41::Tile41(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile42
Tile42::Tile42(Color color, const Board &board) :
        Tile(shape, dimension, color, board)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}
