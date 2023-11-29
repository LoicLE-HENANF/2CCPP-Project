//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_PLAYER_H
#define INC_2CCPP_PROJECT_PLAYER_H

#include "raylib.h"
#include "Tiles.h"
#include <string>

// Our player class

/**
 * @brief Represents a player in the game.
 *
 * The Player class manages information about a player, including their name, color, AI status (no AI in game), and distant status.
 */
class Player {
private:
    std::string name;
    Color color;
    bool isAI = false;
    bool isDistant = false;

public:

    /**
     * @brief Default constructor for the Player class.
     *
     * Initializes a player with default values.
     */
    Player() : name("a"), color(WHITE) {};

    /**
     * @brief Destructor for the Player class.
     */
    ~Player() = default;

    /**
     * @brief Gets the color of the player.
     *
     * @return The color of the player.
     */
    [[nodiscard]] Color GetColor() const;

    /**
     * @brief Sets the color of the player.
     *
     * @param _color The color to set for the player.
     */
    void SetColor(Color _color);

    /**
     * @brief Checks if the player is controlled by AI.
     *
     * @return True if the player is controlled by AI, false otherwise.
     */
    [[nodiscard]] bool GetIsAI() const{
        return isAI;
    };

    /**
     * @brief Sets the AI status of the player.
     *
     * @param _isAI The AI status to set.
     */
    void SetIsAI(bool _isAI){
        isAI = _isAI;
    };

    /**
     * @brief Checks if the player is distant.
     *
     * @return True if the player is distant, false otherwise.
     */
    [[nodiscard]] bool GetIsDistant() const{
        return isDistant;
    };

    /**
     * @brief Sets the distant status of the player.
     *
     * @param _isDistant The distant status to set.
     */
    void SetIsDistant(bool _isDistant){
        isAI = _isDistant;
    };

    /**
     * @brief Gets the tiles owned by the player.
     *
     * @return Reference to the Tiles object owned by the player.
     */
    Tiles& GetTiles();

    /**
     * @brief Gets the name of the player.
     *
     * @return The name of the player.
     */
    std::string GetPlayerName();

    /**
     * @brief Sets the name of the player.
     *
     * @param _name The name to set for the player.
     */
    void SetName(std::string _name);
};


#endif //INC_2CCPP_PROJECT_PLAYER_H
