//
// Created by lehen on 12/11/2023.
//

#include "../headers/Game.h"
#include "raylib.h"
#include "assert.h"

Game::Game(int width, int height, int fps, const std::string& title)
    :
    board(200,200,10,20,15,2)
{
    assert(!GetWindowHandle()); //If assertion triggers : windows is already opened
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 10; ++x) {
            board.SetCell(x, y, RED);
        }
    }

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
