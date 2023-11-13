//
// Created by lehen on 13/11/2023.
//

#include "../headers/GameStates.h"
#include "raylib.h"

// MenuPrincipal state:
void MenuPrincipal::OnEntry() {
    // run on entry
}

void MenuPrincipal::OnExit() {
    // run on exit - will return or set next state
}

void MenuPrincipal::Update() {
    // updating the menu logic
}

void MenuPrincipal::Draw() {
    // drawing the menu
}

void MenuPrincipal::Tick() {
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

// GameOption state
void GameOptions::OnEntry() {
    // run on entry
}

void GameOptions::OnExit() {
    // run on exit - will return or set next state
}

void GameOptions::Update() {

}

void GameOptions::Draw() {

}

void GameOptions::Tick() {

}

// Playing state
void Playing::OnEntry() {

}

void Playing::OnExit() {

}

void Playing::Update() {

}

void Playing::Draw() {

}

void Playing::Tick() {

}
