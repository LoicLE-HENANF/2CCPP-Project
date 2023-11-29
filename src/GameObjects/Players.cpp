//
// Created by lehen on 23/11/2023.
//

#include <iostream>
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
    return (int)players.size();
}

Player Players::GetPlayer(int i) const{
    return players[i];
}

int Players::GetCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

void Players::NextPlayer() {
    if (currentPlayerIndex < (int)players.size() - 1){
        currentPlayerIndex++;
    } else{
        currentPlayerIndex = 0;

        turn++;
        std::cout << "turn: " << turn<<std::endl;
    }

}

Player Players::GetCurrentPlayer() {
    return players[currentPlayerIndex];
}

int Players::GetTurn() const {
    return turn;
}

std::string Players::GetCurrentPlayerName() {
    return players[currentPlayerIndex].GetPlayerName();
}

void Players::AddTECToCurrentPlayer() {
    players[currentPlayerIndex].AddTEC();
}
