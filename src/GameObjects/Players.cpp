//
// Created by lehen on 23/11/2023.
//

#include "../../headers/GameObjects/Players.h"

void Players::Init(int numberOfPlayers, std::vector<Color> colors, std::vector<std::string> names) {
    players.clear();
    players.resize(numberOfPlayers);
    currentPlayerIndex = 0;

    for (int i = 0; i < numberOfPlayers; ++i) {
        players[i].SetColor(colors[i]);
        players[i].SetName(names[i]);
    }
}

int Players::GetSize() const{
    return players.size();
}

Player Players::GetPlayer(int i) const{
    return players[i];
}

int Players::GetCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

void Players::NextPlayer() {
    currentPlayerIndex = (currentPlayerIndex + 1) % (int)players.size();
}

Player Players::GetCurrentPlayer() {
    return players[currentPlayerIndex];
}
