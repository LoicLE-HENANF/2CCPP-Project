//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAME_H
#define INC_2CCPP_PROJECT_GAME_H

#include <string>
#include "Board.h"
#include "GameState.h"
#include "Settings.h"
#include "Player.h"
#include "UI/Button.h"
#include "Tile.h"

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
    bool areChoicesMade;
    Board board;
    Vec2<int> boardSize;
    // -> Tiles
    Tile1 tile {GREEN, settings::boardPosition, {200,100}};


    //player info
    int numberOfPlayer;
    std::vector<Player> players;


    // UI (options)
    Vec2<int> buttonSize = {70,30};

    Vec2<int> playButtonPos = {
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            (settings::screenHeight / 2) - (buttonSize.GetY() / 2)
    };
    Button playButton{
            playButtonPos,
            buttonSize,
            "Play",
            RED
    };

    // UI (game)


};


#endif //INC_2CCPP_PROJECT_GAME_H
