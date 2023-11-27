//
// Created by lehen on 23/11/2023.
//

#include <iostream>
#include "../../headers/GameObjects/Tiles.h"
#include "../../headers/Settings.h"

Tiles::Tiles() : color(WHITE) {
    // On ajoute à tiles toutes les Tiles
    std::cout << "init tiles" << std::endl;
    tiles.push_back(Tile1{color, {0,0}});
    tiles.push_back(Tile2{color, {0,0}});
    tiles.push_back(Tile3{color, {0,0}});
    tiles.push_back(Tile4{color, {0,0}});
    tiles.push_back(Tile5{color, {0,0}});
    tiles.push_back(Tile6{color, {0,0}});
    tiles.push_back(Tile7{color, {0,0}});
    tiles.push_back(Tile8{color, {0,0}});
    tiles.push_back(Tile9{color, {0,0}});
    tiles.push_back(Tile10{color, {0,0}});
    tiles.push_back(Tile11{color, {0,0}});
    tiles.push_back(Tile12{color, {0,0}});
    tiles.push_back(Tile13{color, {0,0}});
    tiles.push_back(Tile14{color, {0,0}});
    tiles.push_back(Tile15{color, {0,0}});
    tiles.push_back(Tile16{color, {0,0}});
    tiles.push_back(Tile17{color, {0,0}});
    tiles.push_back(Tile18{color, {0,0}});
    tiles.push_back(Tile19{color, {0,0}});
    tiles.push_back(Tile20{color, {0,0}});
    tiles.push_back(Tile21{color, {0,0}});
    tiles.push_back(Tile22{color, {0,0}});
    tiles.push_back(Tile23{color, {0,0}});
    tiles.push_back(Tile24{color, {0,0}});
    tiles.push_back(Tile25{color, {0,0}});
    tiles.push_back(Tile26{color, {0,0}});
    tiles.push_back(Tile27{color, {0,0}});
    tiles.push_back(Tile28{color, {0,0}});
    tiles.push_back(Tile29{color, {0,0}});
    tiles.push_back(Tile30{color, {0,0}});
    tiles.push_back(Tile31{color, {0,0}});
    tiles.push_back(Tile32{color, {0,0}});
    tiles.push_back(Tile33{color, {0,0}});
    tiles.push_back(Tile34{color, {0,0}});
    tiles.push_back(Tile35{color, {0,0}});
    tiles.push_back(Tile36{color, {0,0}});
    tiles.push_back(Tile37{color, {0,0}});
    tiles.push_back(Tile38{color, {0,0}});
    tiles.push_back(Tile39{color, {0,0}});
    tiles.push_back(Tile40{color, {0,0}});
    tiles.push_back(Tile41{color, {0,0}});
    tiles.push_back(Tile42{color, {0,0}});
    tiles.push_back(Tile43{color, {0,0}});
    tiles.push_back(Tile44{color, {0,0}});
    tiles.push_back(Tile45{color, {0,0}});
    tiles.push_back(Tile46{color, {0,0}});
    tiles.push_back(Tile47{color, {0,0}});
    tiles.push_back(Tile48{color, {0,0}});
    tiles.push_back(Tile49{color, {0,0}});
    tiles.push_back(Tile50{color, {0,0}});
    tiles.push_back(Tile51{color, {0,0}});
    tiles.push_back(Tile52{color, {0,0}});
    tiles.push_back(Tile53{color, {0,0}});
    tiles.push_back(Tile54{color, {0,0}});
    tiles.push_back(Tile55{color, {0,0}});
    tiles.push_back(Tile56{color, {0,0}});
    tiles.push_back(Tile57{color, {0,0}});
    tiles.push_back(Tile58{color, {0,0}});
    tiles.push_back(Tile59{color, {0,0}});
    tiles.push_back(Tile60{color, {0,0}});
    tiles.push_back(Tile61{color, {0,0}});
    tiles.push_back(Tile62{color, {0,0}});
    tiles.push_back(Tile63{color, {0,0}});
    tiles.push_back(Tile64{color, {0,0}});
    tiles.push_back(Tile65{color, {0,0}});
    tiles.push_back(Tile66{color, {0,0}});
    tiles.push_back(Tile67{color, {0,0}});
    tiles.push_back(Tile68{color, {0,0}});
    tiles.push_back(Tile69{color, {0,0}});
    tiles.push_back(Tile70{color, {0,0}});
    tiles.push_back(Tile71{color, {0,0}});
    tiles.push_back(Tile72{color, {0,0}});
    tiles.push_back(Tile73{color, {0,0}});
    tiles.push_back(Tile74{color, {0,0}});
    tiles.push_back(Tile75{color, {0,0}});
    tiles.push_back(Tile76{color, {0,0}});
    tiles.push_back(Tile77{color, {0,0}});
    tiles.push_back(Tile78{color, {0,0}});
    tiles.push_back(Tile79{color, {0,0}});
    tiles.push_back(Tile80{color, {0,0}});
    tiles.push_back(Tile81{color, {0,0}});
    tiles.push_back(Tile82{color, {0,0}});
    tiles.push_back(Tile83{color, {0,0}});
    tiles.push_back(Tile84{color, {0,0}});
    tiles.push_back(Tile85{color, {0,0}});
    tiles.push_back(Tile86{color, {0,0}});

}

void Tiles::DrawNextTiles(Vec2<int> position) {
    std::vector<Tile> nextTiles = GetFiveTiles();

    int dimensionTotal = 0;

    for (Tile iTile:nextTiles) {
        Vec2<int> tilePosition = position + Vec2<int>{0,  dimensionTotal * (settings::cellSize + settings::padding)};
        dimensionTotal += iTile.GetDimension();
        for (int y = 0; y < iTile.GetDimension(); ++y) {
            for (int x = 0; x <iTile.GetDimension(); ++x) {
                if (iTile.GetValue(x,y)) {
                    iTile.Draw(tilePosition, {x, y});
                }
            }

        }

    }
}