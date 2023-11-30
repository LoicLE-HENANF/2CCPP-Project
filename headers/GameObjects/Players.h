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
    int GetSize() const;

    /**
     * @brief Gets the player at the specified index.
     *
     * @param i The index of the player to retrieve.
     * @return The Player object at the specified index.
     */
    Player GetPlayer(int i) const;

    /**
     * @brief Gets the index of the current player.
     *
     * @return The index of the current player.
     */
    int GetCurrentPlayerIndex() const;

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
    int GetTurn() const;

    /**
     * @brief Gets the name of the current player.
     *
     * @return The name of the current player.
     */
    std::string GetCurrentPlayerName();

    void AddTECToCurrentPlayer();

    bool CurrentPlayerHasTEC();

    void RemoveTECFromPlayer();

    std::vector<Player> &GetPlayers();

    void SetPlayersScores(std::vector<int> playersScores);

private:
    std::vector<Player> players;
    Player currentPlayer;
    int currentPlayerIndex = 0;
    int turn =0;

};


#endif //INC_2CCPP_PROJECT_PLAYERS_H
