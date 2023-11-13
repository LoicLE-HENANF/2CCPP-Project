//
// Created by lehen on 13/11/2023.
//

#include <iostream>
#include "../headers/GameStates.h"
#include "raylib.h"

// MenuPrincipal state:
void MenuPrincipal::OnEntry() {
    // run on entry
    OpenClose();
    std::cout << "Entering main menu..." << std::endl;

}

void MenuPrincipal::OnExit() {
    // run on exit - will return or set next state
    OpenClose();
    std::cout << "Exiting main menu..." << std::endl;
}

void MenuPrincipal::Update() {
    // updating the menu logic (click etc)
}

void MenuPrincipal::Draw() {
    // drawing the menu (bouton, image, sprites, title)
    ClearBackground(GREEN);
}

// GameOption state
void Options::OnEntry() {
    // run on entry
    OpenClose();
    std::cout << "Entering options..." << std::endl;
}

void Options::OnExit() {
    // run on exit - will return or set next state
    OpenClose();
    std::cout << "Exiting options..." << std::endl;
}

void Options::Update() {

}

void Options::Draw() {

}

// Playing state
void Playing::OnEntry() {
    // run on entry
    OpenClose();
    std::cout << "Entering playing..." << std::endl;
}

void Playing::OnExit() {
    // run on exit - will return or set next state
    OpenClose();
    std::cout << "Exiting playing..." << std::endl;
}

void Playing::Update() {

}

void Playing::Draw() {

}
