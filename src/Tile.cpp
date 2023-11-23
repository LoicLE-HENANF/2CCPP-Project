//
// Created by Enzo Robert on 14/11/2023.
//

#include "../headers/Tile.h"
#include "../headers/Settings.h"
#include "../headers/RaylibWrapper.h"


Tile::Tile(const int *shape, const int dimension, Color color, Vec2<int> position) :
        shape(shape),
        dimension(dimension),
        color(color),
        position(position)
{

}

void Tile::Draw() {
    for (int x= 0; x< dimension; ++x) {
        for (int y = 0; y < dimension; ++y) {
            if(shape[y * dimension + x]){
                Vec2<int> cellPos = {x, y};
                Vec2<int> size = {settings::cellSize, settings::cellSize};
                GameEngine::DrawRectangle(position + cellPos * settings::cellSize + settings::padding,
                                          size - settings::padding,
                                          color);
            }
        }
    }
}

void Tile::DrawFollow(Vec2<int> boardSize) {
    for (int x= 0; x< dimension; ++x) {
        for (int y = 0; y < dimension; ++y) {
            if(shape[y * dimension + x]){
                Vec2<int> cellPos = {x, y};
                Vec2<int> size = {settings::cellSize, settings::cellSize};

                Vec2<int> mousePos = GameEngine::GetMousePosition();

                int offset = (dimension / 2) * settings::cellSize;

                Vec2<int> pos = mousePos - (mousePos % boardSize);

//                GameEngine::DrawRectangle(pos + cellPos * settings::cellSize + settings::padding - offset,
//                                          size - settings::padding,
//                                          color);

                GameEngine::DrawRectangle(pos + cellPos * settings::cellSize + settings::padding,
                                          size - settings::padding,
                                          color);
            }
        }
    }
}

int Tile::GetDimension() {
    return dimension;
}

const int * Tile::GetShape() {
    return shape;
}

// Tile1
Tile1::Tile1(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile2
Tile2::Tile2(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile3
Tile3::Tile3(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile4
Tile4::Tile4(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile5
Tile5::Tile5(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile6
Tile6::Tile6(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile7
Tile7::Tile7(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile8
Tile8::Tile8(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile9
Tile9::Tile9(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile10
Tile10::Tile10(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile11
Tile11::Tile11(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile12
Tile12::Tile12(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile13
Tile13::Tile13(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile14
Tile14::Tile14(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile15
Tile15::Tile15(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile16
Tile16::Tile16(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile17
Tile17::Tile17(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile18
Tile18::Tile18(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile19
Tile19::Tile19(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile20
Tile20::Tile20(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile21
Tile21::Tile21(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile22
Tile22::Tile22(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile23
Tile23::Tile23(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile24
Tile24::Tile24(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile25
Tile25::Tile25(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile26
Tile26::Tile26(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile27
Tile27::Tile27(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile28
Tile28::Tile28(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile29
Tile29::Tile29(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile30
Tile30::Tile30(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile31
Tile31::Tile31(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile32
Tile32::Tile32(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile33
Tile33::Tile33(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile34
Tile34::Tile34(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile35
Tile35::Tile35(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile36
Tile36::Tile36(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile37
Tile37::Tile37(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile38
Tile38::Tile38(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile39
Tile39::Tile39(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile40
Tile40::Tile40(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile41
Tile41::Tile41(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile42
Tile42::Tile42(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile43
Tile43::Tile43(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile44
Tile44::Tile44(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile45
Tile45::Tile45(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile46
Tile46::Tile46(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile47
Tile47::Tile47(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile48
Tile48::Tile48(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile49
Tile49::Tile49(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile50
Tile50::Tile50(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile51
Tile51::Tile51(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile52
Tile52::Tile52(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile53
Tile53::Tile53(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile54
Tile54::Tile54(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile55
Tile55::Tile55(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile56
Tile56::Tile56(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile57
Tile57::Tile57(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile58
Tile58::Tile58(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile59
Tile59::Tile59(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile60
Tile60::Tile60(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile61
Tile61::Tile61(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile62
Tile62::Tile62(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile63
Tile63::Tile63(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile64
Tile64::Tile64(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile65
Tile65::Tile65(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile66
Tile66::Tile66(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile67
Tile67::Tile67(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile68
Tile68::Tile68(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile69
Tile69::Tile69(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile70
Tile70::Tile70(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile71
Tile71::Tile71(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile72
Tile72::Tile72(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile73
Tile73::Tile73(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile74
Tile74::Tile74(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile75
Tile75::Tile75(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile76
Tile76::Tile76(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile77
Tile77::Tile77(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile78
Tile78::Tile78(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile79
Tile79::Tile79(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile80
Tile80::Tile80(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile81
Tile81::Tile81(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile82
Tile82::Tile82(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile83
Tile83::Tile83(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile84
Tile84::Tile84(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile85
Tile85::Tile85(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}

// Tile86
Tile86::Tile86(Color color, Vec2<int> position) :
        Tile(shape, dimension, color, position)
{
    // check if dim correspond bien à la shape at compile time
    static_assert(sizeof(shape) / sizeof(int) == dimension * dimension);
    // très simple de voir si ca fonctionne: change la dim de la Tile et static_assert au dessus devient rouge (failed assertion)
}



