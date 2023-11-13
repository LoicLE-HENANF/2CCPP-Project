//
// Created by lehen on 13/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAMESTATES_H
#define INC_2CCPP_PROJECT_GAMESTATES_H

#include "Game.h"
#include "GameState.h"


class MenuPrincipal: GameState {
public:
    explicit MenuPrincipal(Game &game) : GameState(game) {}

    void OnEntry() override;
    void OnExit() override;
    void Tick() override;
private:
    void Update() override;
    void Draw() override;
};

class GameOptions: GameState {
    explicit GameOptions(Game &game) : GameState(game) {}

    void OnEntry() override;
    void OnExit() override;
    void Update() override;
    void Draw() override;
    void Tick() override;
};

class Playing: GameState {
    explicit Playing(Game &game) : GameState(game) {}

    void OnEntry() override;
    void OnExit() override;
    void Update() override;
    void Draw() override;
    void Tick() override;
};



#endif //INC_2CCPP_PROJECT_GAMESTATES_H
