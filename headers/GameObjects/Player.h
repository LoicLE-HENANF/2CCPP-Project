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
    int numberOfTEC = 1;
    int score = 0;

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
     * @brief Gets the name of the player.
     *
     * @return The name of the player.
     */
    std::string GetName();

    /**
     * @brief Sets the name of the player.
     *
     * @param _name The name to set for the player.
     */
    void SetName(std::string _name);

    /**
    * @brief Adds a TEC (Tile exchange coupon) to the game.
    */
    void AddTEC();

    /**
 * @brief Gets the number of TECs in the game.
 *
 * @return The number of Tile Exchage Coupon.
 */
    bool GetNumberOfTEC();

    /**
     * @brief Removes a TEC from the game.
    */
    void RemoveTEC();

    /**
    * @brief Sets the score for a player.
     *
     * @param playerScore The score to set for the player.
    */
    void SetScore(int playerScore);

    /**
    * @brief Gets the score as a string representation.
    *
    * @return A string representing the player's score.
    */
    [[nodiscard]] std::string GetScore() const;
};


#endif //INC_2CCPP_PROJECT_PLAYER_H
