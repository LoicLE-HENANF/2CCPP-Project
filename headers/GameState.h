//
// Created by lehen on 13/11/2023.
//

#ifndef INC_2CCPP_PROJECT_GAMESTATE_H
#define INC_2CCPP_PROJECT_GAMESTATE_H

#include <iostream>
#include "Game.h"
#include "IState.h"

class GameState : IState {
public:
    explicit GameState()= default;;
    ~GameState() override = default;

    void OnEntry() override = 0;
    void OnExit() override = 0;

    static GameState* GetCurrentState(){ return currentState;};

    bool IsOpening() const{ return isOpening; };
    void OpenClose() { isOpening = !isOpening; };

    // Gamestates methods

    static GameState* currentState;
    static GameState *mainMenu,
                        *options,
                        *playing;
    virtual void Update()  = 0;
    virtual void Draw() = 0;

private:
    bool isOpening = true;





};


#endif //INC_2CCPP_PROJECT_GAMESTATE_H
