//
// Created by lehen on 12/11/2023.
//

#include "../headers/Game.h"
#include "raylib.h"
#include <cassert>

#include "../headers/settings.h"
#include "../headers/GameStates.h"

using namespace settings;

// Game class implementation
Game::Game(int width, int height, int fps, const std::string &title)
{
    assert(!GetWindowHandle()); //If assertion triggers : windows is already opened
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());


}

Game::~Game() noexcept {
    assert(GetWindowHandle()); //If assertion triggers : windows is already closed
    CloseWindow();
}

bool Game::GameShouldClose() {
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
    GameState::currentState->Update();
    GameState::currentState->Draw();
    EndDrawing();

}

void Game::Draw() {
    // Draw basic logic ? maybe
//    ClearBackground(BLACK);
//    board.Draw();

}

void Game::Update() {
    // Game logic
}
