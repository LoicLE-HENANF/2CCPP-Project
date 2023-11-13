//
// Created by lehen on 13/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAMESTATESLIST_H
#define INC_2CCPP_PROJECT_GAMESTATESLIST_H

#include "Settings.h"
#include "Game.h"
#include "GameState.h"

class GameStatesList {
public:
    explicit GameStatesList(Game &game);
    ~GameStatesList();

    // methods
    void SetCurrentState(int nextState);
    void addState(GameState* newState);

    void Empty();

    GameState* GetCurrent();

private:
    Game& game;
    std::vector<GameState*> states;
    int currentStateIndex = settings::MENU_PRINCIPAL_STATE;

};


#endif //INC_2CCPP_PROJECT_GAMESTATESLIST_H
