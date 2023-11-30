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

/**
 * @brief Manages the tiles in the game.
 *
 * The Tiles class manages the tiles in the game, including their retrieval, skipping, and drawing.
 */
class Tiles {
public:

    /**
     * @brief Default constructor for the Tiles class.
     */
    Tiles();

    /**
     * @brief Gets the current tile.
     *
     * @return Reference to the current tile.
     */
    Tile& GetCurrentTile(){
        return tiles[currentTileIndex];
    }

    /**
     * @brief Gets the next five tiles in the sequence.
     *
     * @return A vector containing the next five tiles.
     */
    std::vector<Tile> GetFiveTiles(){
        std::vector<Tile> outTiles;
        for (int i = currentTileIndex + 1; i < currentTileIndex + 6; ++i) {
            outTiles.push_back(tiles[i]);
        }
        return outTiles;
    }

    /**
     * @brief Moves to the next tile in the sequence.
     */
    void NextTile(){
        if (currentTileIndex >= tiles.size()){
            currentTileIndex = 0;
        }else{
            currentTileIndex++;
        }
    }

    /**
     * @brief Draws the next tiles at the specified position.
     *
     * @param position The position to draw the next tiles.
     */
    void DrawNextTiles(Vec2<int> position);

    /**
     * @brief Sets the color of all tiles.
     *
     * @param _color The color to set for all tiles.
     */
    void SetTilesColor(Color _color){
        color = _color;
        for (Tile &tile : tiles) {
            tile.SetColor(_color);
        }
    }

    /**
    * @brief Attempts to use a TEC (Tile Exchange Coupon) at the specified position.
    *
    * @param position The position at which to use the TEC.
    * @return True if the TEC was successfully used, false otherwise.
    */
    bool UseTEC(Vec2<int> position);

private:
    std::vector<Tile> tiles;
    int currentTileIndex = 0;
    std::vector<Tile> placedTiles;
    Color color;
    bool isUsingTEC = false;
    int TECTileIndexOffset = 0;

};


#endif //INC_2CCPP_PROJECT_TILES_H
