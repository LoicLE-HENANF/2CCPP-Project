//
// Created by lehen on 13/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAMESTATES_H
#define INC_2CCPP_PROJECT_GAMESTATES_H

#include "Game.h"
#include "GameState.h"
#include "Settings.h"


class MenuPrincipal: public GameState {
public:
    explicit MenuPrincipal() = default;

    void OnEntry() override;
    void OnExit() override;
private:
    void Update() override;
    void Draw() override;
};

class Options: public GameState {
public:
    explicit Options()= default;

    void OnEntry() override;
    void OnExit() override;
private:
    void Update() override;
    void Draw() override;
};

class Playing: public GameState {
public:
    Playing() = default;

    void OnEntry() override;
    void OnExit() override;

    void SetBoard(const Board& b){ board = b; }
private:
    Board board;
    void Update() override;
    void Draw() override;
};



#endif //INC_2CCPP_PROJECT_GAMESTATES_H
