//
// Created by lehen on 23/11/2023.
//

#include "../headers/Players.h"

void Players::Init(int numberOfPlayers, Color color) {
    players.clear();
    players.resize(numberOfPlayers);
    currentPlayerIndex = 0;
    players[currentPlayerIndex].SetColor(color);
}

int Players::GetSize() const{
    return players.size();
}

Player Players::GetPlayer(int i) const{
    return players[i];
}
