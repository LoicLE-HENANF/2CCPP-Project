//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAME_H
#define INC_2CCPP_PROJECT_GAME_H

#include <string>
#include "Board.h"
#include "GameState.h"
#include "Settings.h"
//#include "GameStatesList.h"

class Game {

public:
    Game(int width, int height, int fps, const std::string &title);
    ~Game() noexcept; // noexcept to avoid stack unwinding
    Game(const Game& other) = delete; //copy constructor deleted
    Game& operator=(const Game& other) = delete; //copy assignment deleted

    [[nodiscard]] static bool GameShouldClose() ;

    void Tick();



private:
    void Draw();
    void Update();

    // Game variables
    Vec2<int> boardSize;
};


#endif //INC_2CCPP_PROJECT_GAME_H
