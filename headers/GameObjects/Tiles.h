//
// Created by lehen on 23/11/2023.
//

#ifndef INC_2CCPP_PROJECT_TILES_H
#define INC_2CCPP_PROJECT_TILES_H


#include <vector>
#include "Tile.h"

///
/// Classe qui gérera les tiles que le joueur peut poser, qui seront toutes de la couleur qu'il a choisi.
///
class Tiles {
public:
    Tiles();


    // getters and setters
//    void SetCurrentTileIndex(int index){ currentTileIndex = index; };
//
//    int GetCurrentTileIndex(){ return currentTileIndex; };

    Tile& GetCurrentTile(){
        return tiles[currentTileIndex];
    }

    std::vector<Tile> GetFiveTiles(){
        std::vector<Tile> outTiles;
        for (int i = currentTileIndex; i < currentTileIndex + 5; ++i) {
            outTiles.push_back(tiles[i]);
        }
        return outTiles;
    }

    void SkipTwoTiles(){
        if (currentTileIndex == tiles.size() - 2){
            currentTileIndex = 0;
        }else if (currentTileIndex == tiles.size() - 1){
            currentTileIndex = 1;
        }else{
            currentTileIndex += 2;
        }
    }

    void NextTile(){
        if (currentTileIndex >= tiles.size()){
            currentTileIndex = 0;
        }else{
            currentTileIndex++;
        }
    }

    void SetTilesColor(Color _color){
        color = _color;
        for (Tile &tile : tiles) {
            tile.SetColor(_color);
        }
    }

private:
    std::vector<Tile> tiles;
    int currentTileIndex = 0;
    std::vector<Tile> placedTiles;
    Color color;


};


#endif //INC_2CCPP_PROJECT_TILES_H
