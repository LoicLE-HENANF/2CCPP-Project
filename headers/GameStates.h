//
// Created by lehen on 13/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAMESTATES_H
#define INC_2CCPP_PROJECT_GAMESTATES_H

#include "Game.h"
#include "GameState.h"
#include "Settings.h"
#include "UI/Button.h"
#include "UI/CheckBox.h"
#include "UI/NumberChoice.h"


class MainMenu: public GameState {
public:
    explicit MainMenu() = default;

    void OnEntry() override;
    void OnExit() override;
private:
    void Update() override;
    void Draw() override;

    Vec2<int> buttonSize = {70,30};

    Vec2<int> playButtonPos = {
            (settings::screenWidth / 2) - (buttonSize.GetX() / 2),
            (settings::screenHeight / 2) - (buttonSize.GetY() / 2)
    };
    Button playButton{
        playButtonPos,
        buttonSize,
        "Play",
        RED,
        GameState::playing,
    };
    Vec2<int> optionsButtonPos = {

    };
    Vec2<int> quitButtonPos = {

    };

    // test checkbox
    Vec2<int> checkBoxPos = {
        50,50
    };

    CheckBox checkBox {
        checkBoxPos,
        {50,50},
        5,
        BLACK,
        PINK,
        false
    };

    // test numberChoice
    Vec2<int> numberChoicePos = {100,100};

    NumberChoice numberChoice{numberChoicePos,
                              Vec2{100,100},
                              BLACK,
                              WHITE,
                              2,
                              9};

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

    Vec2<int> boardSize;
    int numberOfPlayer;

    void Update() override;
    void Draw() override;
};



#endif //INC_2CCPP_PROJECT_GAMESTATES_H
