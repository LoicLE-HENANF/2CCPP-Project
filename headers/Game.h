//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAME_H
#define INC_2CCPP_PROJECT_GAME_H

#include <string>
#include "Board.h"

class Game {
private:
    enum PlayerState{
        MenuPrincipal,
        GameOptions,
        Playing,
    };
public:
    Game(int width, int height, int fps, const std::string& title);
    ~Game() noexcept; // noexcept to avoid stack unwinding
    Game(const Game& other) = delete; //copy constructor deleted
    Game& operator=(const Game& other) = delete; //copy assignment deleted

    [[nodiscard]] bool GameShouldClose() const;

    void Tick();

    void ChangeState(PlayerState nextState);



private:
    void Draw();
    void Update();

    Board board;

    PlayerState currentState = PlayerState::MenuPrincipal;

};


#endif //INC_2CCPP_PROJECT_GAME_H
