//
// Created by lehen on 12/11/2023.
//

#include "../headers/Game.h"
#include "raylib.h"
#include <cassert>

#include "../headers/settings.h"
#include "../headers/GameStates.h"

using namespace settings;

// Simple Finite State Machine
GameState * GameState::mainMenu = new MenuPrincipal();
GameState * GameState::options = new Options();
    // add states here first from GameStates classes
GameState * GameState::currentState = GameState::mainMenu;

Game::Game(int width, int height, int fps, const std::string& title)
    :
    board(settings::boardPosition, settings::boardSize,settings::cellSize,settings::padding)
{
    assert(!GetWindowHandle()); //If assertion triggers : windows is already opened
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept {
    assert(GetWindowHandle()); //If assertion triggers : windows is already closed
    CloseWindow();
}

bool Game::GameShouldClose() const {
    return WindowShouldClose();
}

void Game::Tick() {

    // game logic is wrap in begin and end drawing function of raylib to avoid forgetting about it in the game logic or the display method
    BeginDrawing();
//    Update();
//    Draw();
    if (GameState::currentState->IsOpening()){
        GameState::currentState->OnEntry();
    }
    GameState::currentState->Tick();
    EndDrawing();

}

void Game::Draw() {
//    ClearBackground(BLACK);
//    board.Draw();

}

void Game::Update() {

}
