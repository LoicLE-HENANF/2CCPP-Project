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

    void DrawMenu();
    void UpdateMenu();

    void DrawGame();
    void UpdateGame();

    // Game variables
    bool areChoicesMade;
    Board board;
    Vec2<int> boardSize{};

    int tickCounter = 0;
    // -> Tiles

    Tiles tiles{GREEN};


    //player info
    int numberOfPlayer = 4;
    Players players;
    Color colorChoice = RED;


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
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            (settings::screenHeight / 2) - (buttonSize.GetY() / 2) - 100};

    NumberChoice numberChoice{numberChoicePos,
                              Vec2{100,100},
                              BLACK,
                              WHITE,
                              2,
                              9};

    // UI (game)
    // TODO: next tiles
    // TODO: bouton pour utiliser bonus



};


#endif //INC_2CCPP_PROJECT_GAME_H
