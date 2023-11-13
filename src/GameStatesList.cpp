//
// Created by lehen on 13/11/2023.
//

#include "../headers/GameStatesList.h"

GameStatesList::GameStatesList(Game &game)
    :
    game(game){

}

GameStatesList::~GameStatesList() {
    Empty();
    delete this;
}

void GameStatesList::Empty() {
    states.clear();
}

void GameStatesList::SetCurrentState(int nextState) {
    currentStateIndex = nextState;
}

void GameStatesList::addState(GameState *newState) {
    states.push_back(newState);
}

GameState *GameStatesList::GetCurrent() {
    return states[currentStateIndex];
}




