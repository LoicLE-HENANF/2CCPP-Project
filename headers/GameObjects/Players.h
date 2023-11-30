//
// Created by lehen on 23/11/2023.
//

#ifndef INC_2CCPP_PROJECT_PLAYERS_H
#define INC_2CCPP_PROJECT_PLAYERS_H

#include <vector>
#include "Player.h"

/**
 * @brief Represents a collection of players in the game.
 *
 * The Players class manages the players in the game, including initialization, getting current player information,
 * changing to the next player, and retrieving player details.
 */
class Players {
public:
    /**
     * @brief Default constructor for the Players class.
     */
    Players() = default;

    /**
     * @brief Destructor for the Players class.
     */
    ~Players() = default;

    /**
     * @brief Initializes the players with the specified information.
     *
     * @param numberOfPlayers The number of players in the game.
     * @param colors The colors assigned to each player.
     * @param names The names of each player.
     */
    void Init(int numberOfPlayers, std::vector<Color> colors, std::vector<std::string> names);

    /**
     * @brief Gets the color of the current player.
     *
     * @return The color of the current player.
     */
    Color GetCurrentPlayerColor(){ return players[currentPlayerIndex].GetColor(); };

    /**
     * @brief Gets the total number of players.
     *
     * @return The total number of players.
     */
    [[nodiscard]] int GetSize() const;

    /**
     * @brief Gets the player at the specified index.
     *
     * @param i The index of the player to retrieve.
     * @return The Player object at the specified index.
     */
    [[nodiscard]] Player GetPlayer(int i) const;

    /**
     * @brief Gets the index of the current player.
     *
     * @return The index of the current player.
     */
    [[nodiscard]] int GetCurrentPlayerIndex() const;

    /**
     * @brief Moves to the next player in the sequence.
     */
    void NextPlayer();

    /**
     * @brief Gets the details of the current player.
     *
     * @return The Player object representing the current player.
     */
    Player GetCurrentPlayer();

    /**
     * @brief Gets the current turn in the game.
     *
     * @return The current turn in the game.
     */
    [[nodiscard]] int GetTurn() const;

    /**
     * @brief Gets the name of the current player.
     *
     * @return The name of the current player.
     */
    std::string GetCurrentPlayerName();

    /**
    * @brief Adds a TEC (Tile Exchange Coupon) to the current player.
     */
    void AddTECToCurrentPlayer();

    /**
    * @brief Checks if the current player has a TEC.
    *
    * @return True if the current player has a Tile Exchange Coupon, false otherwise.
    */
    bool CurrentPlayerHasTEC();

    /**
     * @brief Removes a TEC from the current player.
    */
    void RemoveTECFromPlayer();

    /**
    * @brief Gets the vector of players in the game.
    *
    * @return Reference to the vector of players.
    */
    std::vector<Player> &GetPlayers();

    /**
    * @brief Sets the scores for all players in the game.
    *
    * @param playersScores Vector containing scores for each player.
    */
    void SetPlayersScores(std::vector<int> playersScores);

private:
    std::vector<Player> players;
    Player currentPlayer;
    int currentPlayerIndex = 0;
    int turn =0;

};


#endif //INC_2CCPP_PROJECT_PLAYERS_H
