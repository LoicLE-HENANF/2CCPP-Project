//
// Created by lehen on 12/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAME_H
#define INC_2CCPP_PROJECT_GAME_H


#include <string>
#include "Board.h"
#include "Tiles.h"
#include "../UI/Button.h"
#include "../UI/NumberChoice.h"
#include "../UI/PlayersChoice.h"

class Game {

public:
    Game();
    ~Game() noexcept; // noexcept to avoid stack unwinding
    Game(const Game& other) = delete; //copy constructor deleted
    Game& operator=(const Game& other) = delete; //copy assignment deleted

    [[nodiscard]] static bool GameShouldClose() ;

    void Tick();



private:
    // Draw and Update
    void Draw();
    void Update();

    void DrawMenu();
    void UpdateMenu();

    void DrawGame();
    void UpdateGame();

    // multiplayer logic
    bool isServer = false;
    bool isClient = false;

    // Game variables
    bool playing = false;
    bool starting = false;
    bool gameOver = false;

    Board board;
    Vec2<int> boardSize = settings::boardSize;
    int placedStartingCell = 0;

    int tickCounter = 0;

    // tiles
    Tiles tiles;
    std::vector<Cell> startingCells;


    //player info
    int numberOfPlayer = 2;
    Players players;
    Color* playersColor;
    const char** playersNames;

    // UI (options)

    Vec2<int> buttonSize = {70,30};

    Vec2<int> playButtonPos = {
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            (settings::screenHeight / 2) - (buttonSize.GetY() / 2) +200
    };
    Button playButton{
            playButtonPos,
            buttonSize,
            "Play",
            RED
    };
    void PlayButtonClick();

    Vec2<int> numberChoicePos = {
            (settings::screenWidth / 4) - (buttonSize.GetX() / 4),
            (settings::screenHeight / 4) - (buttonSize.GetY() / 4) - 100};

    NumberChoice numberChoice{numberChoicePos,
                              Vec2{100,100},
                              BLACK,
                              WHITE,
                              2,
                              9};

    Vec2<int> colorChoiceSize = {50,50};
    Vec2<int> nameChoiceSize = {300,50};

    Vec2<int> colorChoicePos = {
            (settings::screenWidth / 4) - (buttonSize.GetX() / 4),
            (settings::screenHeight / 4) - (buttonSize.GetY() / 4) + 50
    };


    PlayersChoice playersChoice{
        colorChoicePos,
        colorChoiceSize,
        nameChoiceSize,
        10
    };

    // UI (game)
    // TODO: next tiles
    // TODO: bouton pour utiliser bonus



    void UpdateStarting();

    void DrawingStarting();

    void EndGame();

    void BeginGame();
};


#endif //INC_2CCPP_PROJECT_GAME_H
