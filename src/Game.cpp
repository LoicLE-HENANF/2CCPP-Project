//
// Created by lehen on 12/11/2023.
//

#include "../headers/Game.h"
#include "raylib.h"
#include "assert.h"
#include "../headers/settings.h"

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
    Update();
    Draw();
    EndDrawing();
}

void Game::Draw() {
    ClearBackground(BLACK);
    board.Draw();
}

void Game::Update() {

}

void Game::ChangeState(Game::PlayerState nextState) {
    currentState = nextState;
}
