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
#include "../UI/ColorChoice.h"

class Game {

public:
    Game(int width, int height, int fps, const std::string &title);
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

    // Game logic
    bool CanPlaceTile(Tile tile, Vec2<int> position);
    void PlaceTile(Tile tile, Vec2<int> position);

    // Game variables
    bool areChoicesMade;
    Board board;
    Vec2<int> boardSize{};

    int tickCounter = 0;


    //player info
    int numberOfPlayer = 4;
    Players players;
    Color colorChoice = RED;

    std::vector<Color> allColors = {RED,BLUE,GREEN, YELLOW, PURPLE, BLACK, ORANGE};


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

    Vec2<int> colorChoiceSize = {50,50};

    Vec2<int> colorChoicePos = {
            (settings::screenWidth / 2) - (colorChoiceSize.GetX() / 2),
            (settings::screenHeight / 2) - (colorChoiceSize.GetY() / 2) + 100
    };
    ColorChoice colorChoiceButton{
        colorChoicePos,
        colorChoiceSize
    };

    // UI (game)
    // TODO: next tiles
    // TODO: bouton pour utiliser bonus



};


#endif //INC_2CCPP_PROJECT_GAME_H
