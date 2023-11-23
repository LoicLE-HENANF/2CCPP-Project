//
// Created by lehen on 23/11/2023.
//

#include "../../headers/GameObjects/Tiles.h"

Tiles::Tiles(Color color) {
    // On ajoute à tiles toutes les Tiles
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

}
