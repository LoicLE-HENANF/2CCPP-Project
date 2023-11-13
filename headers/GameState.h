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

    void OnEntry() override {
        isOpening = false;
        std::cout << "Enterring "<< typeid(this).name() << "..." << std::endl;
    };
    void OnExit() override {
        std::cout << "Exiting "<< typeid(this).name() << " ..." << std::endl;
        isOpening = true;
    };

    static GameState* GetCurrentState(){ return currentState;};
    bool IsOpening() const{return isOpening;};

    // Gamestates methods

    static GameState* currentState;
    static GameState *mainMenu, *options;

private:
    bool isOpening = true;
    virtual void Update()  = 0;
    virtual void Draw() = 0;
public:
    virtual void Tick(){ this->Update(); this->Draw(); };



};


#endif //INC_2CCPP_PROJECT_GAMESTATE_H
