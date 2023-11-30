//
// Created by lehen on 23/11/2023.
//

#include <iostream>
#include "../../headers/GameObjects/Players.h"

void Players::Init(int numberOfPlayers, std::vector<Color> colors, std::vector<std::string> names) {
    turn = 0;
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
    return players[currentPlayerIndex].GetName();
}

void Players::AddTECToCurrentPlayer() {
    players[currentPlayerIndex].AddTEC();
}

bool Players::CurrentPlayerHasTEC() {
    if (players[currentPlayerIndex].GetNumberOfTEC() > 0){
        return true;
    }
    return false;

}

void Players::RemoveTECFromPlayer() {
    players[currentPlayerIndex].RemoveTEC();
}

std::vector<Player>& Players::GetPlayers() {
    return players;
}

void Players::SetPlayersScores(std::vector<int> playersScores) {
    for (int i = 0; i < players.size(); ++i) {
        players[i].SetScore(playersScores[i]);
    }
}

