//
// Created by lehen on 23/11/2023.
//

#ifndef INC_2CCPP_PROJECT_PLAYERS_H
#define INC_2CCPP_PROJECT_PLAYERS_H

#include <vector>
#include "Player.h"

class Players {
public:
    Players() = default;
    ~Players() = default;

    void Init(int numberOfPlayers, std::vector<Color> colors, std::vector<std::string> names);

    Color GetCurrentPlayerColor(){ return players[currentPlayerIndex].GetColor(); };

    int GetSize() const;

    Player GetPlayer(int i) const;

    int GetCurrentPlayerIndex() const;

    void NextPlayer();

    Player GetCurrentPlayer();

    int GetTurn() const;

    std::string GetCurrentPlayerName();

    void AddTECToCurrentPlayer();

private:
    std::vector<Player> players;
    Player currentPlayer;
    int currentPlayerIndex = 0;
    int turn =0;

};


#endif //INC_2CCPP_PROJECT_PLAYERS_H
