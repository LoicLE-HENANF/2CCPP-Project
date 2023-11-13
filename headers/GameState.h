//
// Created by lehen on 13/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAMESTATE_H
#define INC_2CCPP_PROJECT_GAMESTATE_H

#include "Game.h"

#include "IState.h"


class GameState : IState {
public:
    explicit GameState(Game &game) : game(game){};
    ~GameState() override = default;

    void OnEntry() override = 0;
    void OnExit() override = 0;

    // Gamestates methods
private:
    Game &game;
    virtual void Update()  = 0;
    virtual void Draw() = 0;
public:
    virtual void Tick() = 0;



};


#endif //INC_2CCPP_PROJECT_GAMESTATE_H
